#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

class NumberGuess {
private:
	int secretNum, count;
	int highNum, lowNum;
	char answer;
public:
	void playNumberGuess() 
	{
		do 
		{
			int guess;
			bool win = false;
		
			cout << "Enter the secret number between 1 - 100: ";
			cin >> secretNum;
			cout << "Enter how many guesses are allowed: ";
			cin >> count;

			lowNum = 1;
			highNum = 100;

			while(!win && count > 0) //checks to see if user won and if they have number of guesses is above 0.
			{
				cout << "Guess the secret number between 1 - 100: ";
				cin >> guess;
				cout << endl;

				if(guess > secretNum) //checks to see if the guess is higher than the secret number
				{
					cout << "You guessed too high!" << endl;
					highNum = guess;
					cout << "New range is: " << lowNum << " - " << highNum << endl;
			
				}
				else if(guess < secretNum) //checks to see if the guess is less than the secret number
				{
					cout << "You guessed too low!" << endl;
					lowNum = guess;
					cout << "New range is: " << lowNum << " - " << highNum << endl;
				}
				else if(guess == secretNum) //checks to see if the guess is equal to the secret number
				{
					cout << "You guessed correctly!" << endl;
					win = true; //changes the bool value of win to true
				}
				count--; //decrements the number of guesses the user has left by 1 each time
			}

			if(win)
			{
				cout << "Congratulations you won the guessing game!" << endl;
			}
			else
			{
				cout << "Sorry you lost because you ran out of guesses." << endl;
				cout << "The secret number was " << secretNum << "." << endl;

				if((highNum - secretNum) < (secretNum - lowNum)) 
				{
					cout << "The closest guess to the secret number was: " << highNum << "." << endl;
				}
				else
				{
					cout << "The closest guess to the secret number was: " << lowNum << "." << endl;
				}
			}

			cout << "Do you want to keep playing? Enter (y/n)" << endl;
			cin >> answer;

		}while(answer != 'n' && answer != 'N');
	}
};

class wordGuess
{
private:
	string player1, player2;
	string secret_word;
	string word_dash;
	string letter_missing;
	char letter_guess;
	char answer;
	int num_guesses;
	bool win;
public:
	bool check_word(string secretWord)
	{
		for(int i = 0; i < secretWord.length(); i++) {
		if(!isalpha(secretWord.at(i))) 
			return false;
	}
		return true;
	}
	void displayMessage()
	{
		cout << "Enter name for player 1: ";
		getline(cin, player1);
		cout << "Enter name for player 2: ";
		getline(cin, player2);
	}
	void playWordGuess()
	{
		do {
		answer = ' ';
		word_dash = "";
		cout << "Player 1, please enter the secret word (only letters): ";
		cin >> secret_word;

		if(check_word(secret_word)) 
		{
			cout << "Enter number of guesses allowed: ";
			cin >> num_guesses;

			for(int i = 0; i < secret_word.length(); i++) 
			{ //prints out the number of '-' for the secret word
				word_dash += '-';
			}//end for
		
			while(num_guesses > 0 && word_dash != secret_word) //keeps looping until player guesses correct word or number of guesses is 0
			{
				bool letter_found = false;
				cout << "The secret word: " << word_dash << endl;
				cout << "Please enter a letter: ";
				cin >> letter_guess;

				for(int i = 0; i < secret_word.length(); i++) //checks to see if guessed letter is within the secret word
				{
					if(letter_guess == secret_word.at(i)) 
					{
						word_dash.at(i) = letter_guess;//sets the letter to the appropriate area of the secret word
						letter_found = true;
					}
				}

				if(!letter_found)
				{
					num_guesses--; //decrements number of guesses if guessed the wrong letter
				}
				cout << "You have " << num_guesses << " guesses left!" << endl;
				
			}//end while

			if(word_dash == secret_word) //checks to see if the guessed word matches the secret word
			{
				cout << "You found the word! Congratulations you win!" << endl;
			}
			else
			{
				cout << "You lose!" << endl;
				for(int i = 0; i < secret_word.length(); i++) {//finds which letters are missing
					if(secret_word.at(i) != word_dash.at(i)) {
						letter_missing += secret_word.at(i);
					}
				}
				cout << "The letters missing were: ";

				for(int i = 0; i < letter_missing.length(); i++) {//outputs the letters that are missing
					cout << letter_missing.at(i) << " ";
				}
				cout << endl;
				cout << "The secret word was: " << secret_word << endl;
			}

		}// end if

		cout << "Would you like to try again?(y/n)" << endl;
		cin >> answer;

	}while(answer == 'y' || answer == 'Y');
	}
};

int main()
{
	int choice;

	cout << "This is the list of games to choose from: " << endl;
	cout << "1) Number Guess" << endl;
	cout << "2) Word Guess" << endl;
	cout << "Please enter a choice: ";
	cin >> choice;

	switch(choice)
	{
		case 1:
			cout << "Excellent! You choice the Number Guess game! I hope you enjoy!" << endl;
			NumberGuess guessGame;
			guessGame.playNumberGuess();
			break;
		case 2:
			cout << "Great choice! You choise the Word Guess game! Good luck!" << endl;
			wordGuess wordGuessGame;
			wordGuessGame.playWordGuess();
			break;
	}

	system("pause");
	return 0;
}