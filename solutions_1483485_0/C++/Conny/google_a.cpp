//============================================================================
// Name        : google_a.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

char mapping[] = "yhesocvxduiglbkrztnwjpfmaq";
char line[10000];

void getResult() {
	for (int i = 0; line[i] != 0; i++) {
		if (isalpha(line[i])) {
			line[i] = mapping[line[i] - 'a'];
		}
	}
}

int main() {
	int cases;
	cin >> cases;
	cin.ignore();

	for (int cnt = 1; cnt <= cases; cnt++) {
		cin.getline(line, 10000);
		getResult();

		cout << "Case #" << cnt << ": " << line << endl;
	}

	return 0;
}
