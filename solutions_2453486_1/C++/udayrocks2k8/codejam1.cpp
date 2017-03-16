#include <iostream>
#include <string>
using namespace std;

string st[4];

bool checkRow(char symbol, int row) {
	int symbolCount = 0;
	int tCount = 0;
	for (int i = 0; i < 4; i++) {
		symbolCount += (st[row][i] == symbol);
		tCount += (st[row][i] == 'T');
	}
	return (symbolCount == 4) || (symbolCount == 3 && tCount == 1); 
}

bool checkColumn(char symbol, int row) {
	int symbolCount = 0;
	int tCount = 0;
	for (int i = 0; i < 4; i++) {
		symbolCount += (st[i][row] == symbol);
		tCount += (st[i][row] == 'T');
	}
	return (symbolCount == 4) || (symbolCount == 3 && tCount == 1); 
}

bool checkLeftDiagonal(char symbol) {
	int symbolCount = 0;
	int tCount = 0;
	for (int i = 0; i < 4; i++) {
		symbolCount += (st[i][i] == symbol);
		tCount += (st[i][i] == 'T');
	}
	return (symbolCount == 4) || (symbolCount == 3 && tCount == 1); 
}

bool checkRightDiagonal(char symbol) {
	int symbolCount = 0;
	int tCount = 0;
	for (int i = 0; i < 4; i++) {
		symbolCount += (st[i][3 - i] == symbol);
		tCount += (st[i][3 - i] == 'T');
	}
	return (symbolCount == 4) || (symbolCount == 3 && tCount == 1); 
}

int countSymbols() {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			count += (st[i][j] != '.');
		}
	}
	return count; 
}

void getResult() {
	for (int i = 0; i < 4; i++) {
		cin >> st[i];
	}
	char symbols[] = {'X', 'O'}; 
	for (int i = 0; i < 2; i++) { 
		bool flag = false;
		for (int j = 0; j < 4; j++) {
			flag |= checkRow(symbols[i], j);
			flag |= checkColumn(symbols[i], j);
		}
		flag |= checkRightDiagonal(symbols[i]);
		flag |= checkLeftDiagonal(symbols[i]);
		
		if (flag) {
			cout << symbols[i] << " won" << endl;
			return;
		}
	}
	int symbolCount = countSymbols();
	if (symbolCount == 16) {
		cout << "Draw" << endl;
	} else {
		cout << "Game has not completed" << endl;
	}
}

int main() {
	int testCases;
	cin >> testCases;
	for (int i = 1; i <= testCases; i++) {
		cout << "Case #" << i << ": ";
		getResult();
	}
	return 0;
}