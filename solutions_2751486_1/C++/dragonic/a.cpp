#include <cstdio>
#include <cstring>

using namespace std;

const int maxN = 1000005;
char string[maxN];
bool goodEnd[maxN];
int nextGood[maxN];

bool isVowel (char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long solve (int n)
{
	int length = strlen (string);

	int numVowels = 0;
	for (int i = 0; i < n - 1; i++)
		numVowels += isVowel (string[i]);

	for (int i = 0; i < n; i++)
		goodEnd[i] = false;

	for (int i = n - 1; i < length; i++)
	{
		if (isVowel (string[i])) numVowels++;
		if (i >= n && isVowel (string[i - n])) numVowels--;

		goodEnd[i] = (numVowels == 0);
		//printf ("%i: %i\n", i, numVowels);
	}

	int lastGoodEnd = length;
	for (int i = length - 1; i >= 0; i--)
	{
		if (goodEnd[i])
			lastGoodEnd = i;
		nextGood[i] = lastGoodEnd;
	}

	long long answer = 0;
	for (int i = n - 1; i < length; i++)
		answer += length - nextGood[i];

	return answer;
}

int main()
{
	int nTests;
	scanf ("%i", &nTests);

	for (int i = 0; i < nTests; i++)
	{
		int n;
		scanf ("%s %i", string, &n);
		long long answer = solve (n);

		printf ("Case #%i: %lld\n", i + 1, answer);
	}

	return 0;
}
