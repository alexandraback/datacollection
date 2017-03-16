// sheep.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
using namespace std;

// Create template for qsort

bool gDigitTracker[10];

void countUp(long n);
void readDigitsToTracker(long n);
void resetDigitTracker();
bool isAllPresent();

int main()
{
	int t;
	// string str;
	long n;

	cin >> t;

	// getline(cin, str); // read until end of line (needed if getline is used)

	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";

		cin >> n;
		// cin >> str;
		// getline(cin, str);
		resetDigitTracker();

		if (n == 0) {
			cout << "INSOMNIA";
		}
		else {
			countUp(n);
		}

		cout << "\n";
	}

	return 0;
}

void countUp(long n)
{
	int i = 0;
	do {
		i++;
		readDigitsToTracker(n * i);
	} while (isAllPresent() == false);

	cout << (n * i);
}

void readDigitsToTracker(long n)
{
	long digit;
	while (n > 0) {
		digit = n % 10;
		n /= 10;
		gDigitTracker[digit] = true;
	}
}

void resetDigitTracker()
{
	for (int i = 0; i < 10; i++)
	{
		gDigitTracker[i] = false;
	}
}

bool isAllPresent()
{
	for (int i = 0; i < 10; i++)
	{
		if (gDigitTracker[i] == false) {
			return false;
		}
	}

	return true;
}