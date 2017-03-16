// basic file operations
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool validChar(char check, char lookFor) {
	return check == lookFor || check == 'T';
}

bool valid(char arr [][4], char lookFor) {
	for (int i = 0; i < 4; i++) {
		bool b1 = true; bool b2 = true;
		for (int j = 0; j < 4; j++) {
			if (!validChar(arr[i][j], lookFor))
				b1 = false;
			if (!validChar(arr[j][i], lookFor))
				b2 = false;
		}

		if (b1 || b2)
			return true;
	}
	
	//Check diagonale.
	if (validChar(arr[0][0], lookFor) &&
		validChar(arr[1][1], lookFor) &&
		validChar(arr[2][2], lookFor) &&
		validChar(arr[3][3], lookFor))
		return true;

	if (validChar(arr[0][3], lookFor) &&
		validChar(arr[1][2], lookFor) &&
		validChar(arr[2][1], lookFor) &&
		validChar(arr[3][0], lookFor))
		return true;

	return false;
}



int main() {
	ifstream in;
	in.open("A-small-attempt0.in");

	ofstream out;
	out.open("A-small-attempt0.out");

	int aantal;
	in >> aantal;

	for (int oef = 0; oef < aantal; oef++) {
		//0 == .
		//1 == T
		//2 == X
		//3 == O
		char spelbord[4][4];

		bool possibleUncompleted = false;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				in >> spelbord[i][j];
				if (spelbord[i][j] == '.')
					possibleUncompleted = true;
			}
		}

		out << "Case #" << oef + 1 << ": ";

		if (valid(spelbord, 'X'))
			out << "X won";
		else if (valid(spelbord, 'O'))
			out << "O won";
		else if (possibleUncompleted)
			out << "Game has not completed";
		else
			out << "Draw";

		out << endl;
	}

	in.close();

	return 0;
}