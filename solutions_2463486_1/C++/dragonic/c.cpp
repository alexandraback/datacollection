// Compile with 'g++ -std=c++11 -Wall -Wextra c.cpp -o c.elf -lgmpxx -lgmp -lstdc++ -O2 && time ./c.elf >c.out <C-small-attempt0.in'
// Assuming GMP installed

#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

#include <gmp.h>
#include <gmpxx.h>

using namespace std;

bool isFair (long long x)
{
	vector <int> digits;
	while (x)
	{
		digits.push_back (x % 10);
		x /= 10;
	}

	for (unsigned i = 0; i < digits.size() / 2; i++)
		if (digits[i] != digits[digits.size() - i - 1])
			return false;

	return true;
}

vector <mpz_class> theNumbers;

const int maxBaseLength = 30;
char beginning[maxBaseLength];
int beginningLength = 0;

const int minRootLength = 1, maxRootLength = 52;

char placeDigits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
const int numDigits = 3;

int digitCount[10];
int maxDigitCount[10];

void testPalyndrome (char continueWith)
{
	static char number[maxBaseLength * 2];

	int end = beginningLength * 2 - 1;

	if (continueWith >= '0' && continueWith <= '9')
	{
		number[beginningLength] = continueWith;
		end++;
	}

	for (int i = 0; i < beginningLength; i++)
		number[i] = number[end - i] = beginning[i];
	number[end + 1] = 0;

	//printf ("%.*s (%c) => %s\n", beginningLength, beginning, continueWith, number);

	mpz_t sourceNumber;
	mpz_init_set_str (sourceNumber, number, 10);

	mpz_t square;
	mpz_init (square);

	mpz_pow_ui (square, sourceNumber, 2);

	char* received = mpz_get_str (0, 10, square);
	int length = strlen (received);

	bool palyndrome = true;
	for (int i = 0; i < length / 2; i++)
		if (received[i] != received[length - i - 1])
		{
			palyndrome = false;
			break;
		}

	bool taken = false;
	//printf ("square: %s, palyndrome: %s\n", received, palyndrome ? "true" : "false");
	if (palyndrome && length <= 101)
	{
		//printf ("%s = %s ^2\n", received, number);

		for (int i = 0; i < numDigits; i++)
			maxDigitCount[i] = max (maxDigitCount[i], digitCount[i]);

		theNumbers.push_back (mpz_class (square));
		taken = true;
	}

	free (received);

	if (!taken) mpz_clear (square);
	mpz_clear (sourceNumber);
}

void bruteforce()
{
	// test current string
	if (beginningLength * 2 >= minRootLength && beginningLength * 2 <= maxRootLength)
		testPalyndrome ('X');

	if (beginningLength * 2 + 1 >= minRootLength && beginningLength * 2 + 1 <= maxRootLength)
		for (int i = 0; i < numDigits; i++)
		{
			if (beginningLength == 0 && placeDigits[i] == '0') continue;
			testPalyndrome (placeDigits[i]);
		}

	if (beginningLength * 2 > maxRootLength) return;

	for (int i = 0; i < numDigits; i++)
	{
		if (beginningLength == 0 && placeDigits[i] == '0') continue;

		beginning[beginningLength] = placeDigits[i];
		digitCount[i]++;

		if (digitCount[1] <= 4 && digitCount[2] <= 1)
		{
			beginningLength++;
			bruteforce();
			beginningLength--;
		}

		digitCount[i]--;
	}
}

struct compareLarge
{
	bool operator() (const mpz_class& a, const mpz_class& b) const
	{
		return a < b;
	}
};

void generateNumbers()
{
	// an exception
	mpz_t nine;
	mpz_init_set_str (nine, "9", 10);
	theNumbers.push_back (mpz_class (nine));

	bruteforce();
	sort (theNumbers.begin(), theNumbers.end(), compareLarge());
}

#define eprintf(...) fprintf (stderr, __VA_ARGS__)

int main()
{
	generateNumbers();

	/*for (mpz_class x: theNumbers)
		cout << x << '\n';
	cout << endl;
	*/
	eprintf ("%i numbers generated and sorted\n", (int)theNumbers.size());

	int nTests;
	scanf ("%i", &nTests);

	for (int i = 0; i < nTests; i++)
	{
		mpz_class a, b;
		cin >> a >> b;

		int beginIndex = lower_bound (theNumbers.begin(), theNumbers.end(), a) - theNumbers.begin();
		int endIndex = upper_bound (theNumbers.begin(), theNumbers.end(), b) - theNumbers.begin();
		int answer = endIndex - beginIndex;

		if (answer < 0) answer = 0;

		cout << "Case #" << i + 1 << ": " << answer << '\n';
		eprintf ("answered query #%i of %i: %i\n", i + 1, nTests, answer);
	}
	cout.flush();

	//for (int i = 0; i < numDigits; i++)
	//	printf ("max count of '%c': %i\n", placeDigits[i], maxDigitCount[i]);

	return 0;
}