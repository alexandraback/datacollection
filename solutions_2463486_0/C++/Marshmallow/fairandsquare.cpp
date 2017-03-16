
#include <fstream>
#include <iostream>
#include <sstream>
#include "fairandsquare.h"

using namespace std;

void SolveFairAndSquare()
{
	// Start by writing down some example fair and square numbers
	unsigned __int64 fairandsquares[100];
	int counter = 0;
	for (unsigned __int64 i=0; i < 2100000; i++)
	{
		if (NumberIsPalindrome(i))
		{
			unsigned __int64 square = i * i;
			if (NumberIsPalindrome(square))
			{
				cout << counter << "\t" << i << "\t" << square << endl;
				fairandsquares[counter] = square;
				counter++;
			}
		}
	}

	// Fill the rest of the array with zeros
	for (int i = counter; i < 100; i++)
	{
		fairandsquares[i] = 0;
	}

	// Set up an input and output file
	ifstream file_in;
	file_in.open("C:\\Users\\John\\Desktop\\CodeJam\\fas.in");
	ofstream file_out;
	file_out.open("C:\\Users\\John\\Desktop\\CodeJam\\fas.out");

	// Load test cases
	int test_cases;
	file_in >> test_cases;
	cout << test_cases << " cases" << endl;

	// For each loop we'll need:
	__int64 small;
	__int64 large;
	int fas_counter;
	bool counting;
	for (int n = 0; n < test_cases; n++)
	{
		// Load the bounds
		file_in >> small >> large;
		cout << "small, large: " << small << "\t" << large << endl;

		// Go through our array and count
		fas_counter = 0;
		for (int i = 0; i < 100; i++)
		{
			if ((fairandsquares[i] >= small) && (fairandsquares[i] <= large))
			{
				fas_counter++;
			}
		}

		// Output
		file_out << "Case #" << (n + 1) << ": " << fas_counter << endl;
		cout << "Case " << (n + 1) << ": " << fas_counter << endl;
	}

	return;
}

bool NumberIsPalindrome(__int64 number)
{
	stringstream stream;
	stream << number;

	string str_number = stream.str();

	return StringIsPalindrome(str_number);
}

bool StringIsPalindrome(string number)
{
	int length = number.length();

	for (int i = 0; i < length/2; i++)
	{
		if (number[i] != number[length - i - 1])
		{
			return false;
		}
	}
	return true;
}
