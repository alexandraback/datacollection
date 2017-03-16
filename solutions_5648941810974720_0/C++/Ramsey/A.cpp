#pragma warning(disable:4996)
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const char inFileName[] = "A-small.in";
const char outFileName[] = "A-small.out";

const int MAX_S = 2010;

const string names[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
const char rep[] = { 'Z', 'O', 'W', 'T', 'U', 'F', 'X', 'S', 'G', 'I'};
const int indices[] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

int T;
int num[10];
int freq[30];
char s[MAX_S];

int main() {

	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++)
	{
		for (int i = 0; i < 10; i++)
			num[i] = 0;
		for (int i = 0; i < 26; i++)
			freq[i] = 0;

		fscanf(inFile, "%s", s);
		int n = strlen(s);
		for (int i = 0; i < n; i++)
			freq[s[i] - 'A']++;

		for (int i = 0; i < 10; i++)
		{
			int ind = indices[i];
			num[ind] = freq[rep[ind] - 'A'];
			for (int j = 1; j <= num[ind]; j++)
			{
				for (int k = 0; k < names[ind].length(); k++)
				{
					freq[names[ind][k] - 'A']--;
				}
			}
		}

		bool ok = true;
		for (int i = 0; i < 26; i++)
			ok = ok && (freq[i] == 0);

		fprintf(outFile, "Case #%d: ", t + 1);
		if (ok)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 1; j <= num[i]; j++)
					fprintf(outFile, "%d", i);
			}
			fprintf(outFile, "\n");
		}
		else
		{
			fprintf(outFile, "FAIL\n");
		}
	}

	fclose(inFile);
	fclose(outFile);
	return 0;
}
