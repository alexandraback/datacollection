// pancake.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
using namespace std;

int countFlips(string input);

int main()
{
	int t;
	string str;
	int res;

	cin >> t;

	getline(cin, str); // read until end of line (needed if getline is used)

	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";

		getline(cin, str);

		res = countFlips(str);
		cout << res;

		cout << "\n";
	}

	return 0;
}

int countFlips(string input)
{
	char prev = ' ';
	string newStr = "";

	for (int i = 0; i < input.length(); i++)
	{
		char sign = input[i];

		if (prev == sign) {
			continue;
		}

		if (sign == '+') {
			newStr.append("+");
		}
		else if (sign == '-') {
			newStr.append("-");
		}
		else {
			cout << "ERROR: unexpected character";
		}

		prev = sign;
	}

	//cout << newStr << "<< ";

	// dont count last char if '+'
	if (prev == '+') {
		return newStr.length() - 1;
	}

	return newStr.length();
}


