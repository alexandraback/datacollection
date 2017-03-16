#pragma warning(disable:4996)
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const char inFileName[] = "B-large.in";
const char outFileName[] = "B-large.out";

const int MAX_N = 20;
const long long INF = 4000000000000000000LL;

int T, n;
char s1[MAX_N], s2[MAX_N];
char s[2][MAX_N];
long long d[MAX_N];
int c1[MAX_N], c2[MAX_N];

long long deg10[MAX_N];
long long suffMax[2][MAX_N];
long long suffMin[2][MAX_N];

int solve()
{
	return 0;
}

int main() {

	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	deg10[0] = 1LL;
	for (int i = 1; i <= 18; i++)
		deg10[i] = deg10[i - 1] * 10;

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++)
	{
		fscanf(inFile, "%s", s1);
		fscanf(inFile, "%s", s2);
		int n = strlen(s1);
		for (int i = 0; i < n; i++)
		{
			s[0][i + 1] = s1[n - 1 - i];
			s[1][i + 1] = s2[n - 1 - i];
		}
		
		for (int ind = 0; ind < 2; ind++)
		{
			suffMax[ind][1] = (s[ind][1] == '?' ? 9 : s[ind][1] - '0');
			suffMin[ind][1] = (s[ind][1] == '?' ? 0 : s[ind][1] - '0');
		}
		for (int ind = 0; ind < 2; ind++)
		{
			for (int i = 2; i <= n; i++)
			{
				suffMax[ind][i] = suffMax[ind][i - 1] + deg10[i - 1] * (s[ind][i] == '?' ? 9 : s[ind][i] - '0');
				suffMin[ind][i] = suffMin[ind][i - 1] + deg10[i - 1] * (s[ind][i] == '?' ? 0 : s[ind][i] - '0');
			}
		}

		//-----
		
		d[0] = 0LL;
		for (int pos = 1; pos <= n; pos++)
		{
			d[pos] = INF;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if ((s[0][pos] != '?' && (s[0][pos] - '0' != i))  || (s[1][pos] != '?' && (s[1][pos] - '0' != j)))
					{
					}
					else
					{
						long long currSol;
						if (i < j)
						{
							currSol = deg10[pos - 1] * (j - i) + suffMin[1][pos - 1] - suffMax[0][pos - 1];
						}
						else if (i > j)
						{
							currSol = deg10[pos - 1] * (i - j) + suffMin[0][pos - 1] - suffMax[1][pos - 1];
						}
						else
						{
							currSol = d[pos - 1];
						}
						if (currSol < d[pos])
						{
							d[pos] = currSol;
							c1[pos] = i;
							c2[pos] = j;
						}
					}
				}
			}
		}

		int ind = n;
		while (c1[ind] == c2[ind] && ind > 0)
		{
			s1[n - ind] = '0' + c1[ind];
			s2[n - ind] = '0' + c2[ind];
			ind--;
		}
		if (ind > 0)
		{
			s1[n - ind] = '0' + c1[ind];
			s2[n - ind] = '0' + c2[ind];
			if (c1[ind] > c2[ind])
			{
				for (int i = ind - 1; i > 0; i--)
				{
					if (s1[n - i] == '?') s1[n - i] = '0';
					if (s2[n - i] == '?') s2[n - i] = '9';
				}
			}
			else
			{
				for (int i = ind - 1; i > 0; i--)
				{
					if (s1[n - i] == '?') s1[n - i] = '9';
					if (s2[n - i] == '?') s2[n - i] = '0';
				}
			}
		}


		fprintf(outFile, "Case #%d: %s %s\n", t + 1, s1, s2);
	}

	fclose(inFile);
	fclose(outFile);
	return 0;
}
