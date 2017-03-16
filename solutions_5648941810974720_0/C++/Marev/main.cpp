#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

#include "BigInteger.hh"

using namespace std;

stringstream out;

bool isNumber(string a, string number)
{
	int aLetters[26] = { 0 };
	int numberLetters[26] = { 0 };

	for (int i = 0; i < a.length(); i++)
		aLetters[a[i] - 'a']++;

	for (int i = 0; i < number.length(); i++)
		numberLetters[number[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		if (aLetters[i] != numberLetters[i])
			return false;

	return true;
}

void function()
{
	string S;
	string currentString;
	cin >> S;
	int lastDigit = 0;
	int letters[26] = { 0 };
	int numbers[10] = { 0 };

	for (int i = 0; i < S.length(); i++)
	{
		letters[S[i] - 'A']++;
	}

	numbers[0] += letters['Z' - 'A'];
	letters['E' - 'A'] -= letters['Z' - 'A'];
	letters['R' - 'A'] -= letters['Z' - 'A'];
	letters['O' - 'A'] -= letters['Z' - 'A'];
	letters['Z' - 'A'] = 0;

	numbers[2] += letters['W' - 'A'];
	letters['T' - 'A'] -= letters['W' - 'A'];
	letters['O' - 'A'] -= letters['W' - 'A'];
	letters['W' - 'A'] = 0;

	numbers[4] += letters['U' - 'A'];
	letters['F' - 'A'] -= letters['U' - 'A'];
	letters['O' - 'A'] -= letters['U' - 'A'];
	letters['R' - 'A'] -= letters['U' - 'A'];
	letters['U' - 'A'] = 0;

	numbers[6] += letters['X' - 'A'];
	letters['S' - 'A'] -= letters['X' - 'A'];
	letters['I' - 'A'] -= letters['X' - 'A'];
	letters['X' - 'A'] = 0;

	numbers[8] += letters['G' - 'A'];
	letters['E' - 'A'] -= letters['G' - 'A'];
	letters['I' - 'A'] -= letters['G' - 'A'];
	letters['H' - 'A'] -= letters['G' - 'A'];
	letters['T' - 'A'] -= letters['G' - 'A'];
	letters['G' - 'A'] = 0;

	numbers[1] += letters['O' - 'A'];
	letters['N' - 'A'] -= letters['O' - 'A'];
	letters['E' - 'A'] -= letters['O' - 'A'];
	letters['O' - 'A'] = 0;

	numbers[3] += letters['R' - 'A'];
	letters['T' - 'A'] -= letters['R' - 'A'];
	letters['H' - 'A'] -= letters['R' - 'A'];
	letters['E' - 'A'] -= letters['R' - 'A'];
	letters['E' - 'A'] -= letters['R' - 'A'];
	letters['R' - 'A'] = 0;

	numbers[5] += letters['F' - 'A'];
	letters['I' - 'A'] -= letters['F' - 'A'];
	letters['V' - 'A'] -= letters['F' - 'A'];
	letters['E' - 'A'] -= letters['F' - 'A'];
	letters['F' - 'A'] = 0;

	numbers[7] += letters['S' - 'A'];
	letters['E' - 'A'] -= letters['S' - 'A'];
	letters['V' - 'A'] -= letters['S' - 'A'];
	letters['E' - 'A'] -= letters['S' - 'A'];
	letters['N' - 'A'] -= letters['S' - 'A'];
	letters['S' - 'A'] = 0;

	numbers[9] += letters['I' - 'A'];

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < numbers[i]; j++)
			out << i;
	out << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		out << "Case #" << i << ": ";
		function();
	}
	cout << out.str();

	return 0;
}