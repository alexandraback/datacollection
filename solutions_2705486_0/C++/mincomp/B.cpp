#include "stdafx.h"
#include <set>
#include <string>
#include <hash_set>

using namespace std;

hash_set<string> dict;
char data[10000];
int f[10000][5];

int findMinTransform(int s, int e, int l, int r)
{
	char d[21];
	for (int i = 0; i < e - s + 1; i++)
	{
		d[i] = data[s + i];
	}
	d[e - s + 1] = 0;
	int len = e - s + 1;

	// No change.
	string ss(d);
	if (dict.count(ss) > 0) return 0;

	// One letter changes.
	for (int i = max(0, l); i < min(len, r); i++)
		for (int j = 'a'; j <= 'z'; j++)
		{
			if (d[i] == j) continue;
			string s(d);
			s[i] = j;
			if (dict.count(s) > 0)
				return 1;
		}

	// Two letters change.
	for (int i = max(0, l); i < min(len, r); i++)
	{
		for (int a = 'a'; a <= 'z'; a++)
		{
			if (d[i] == a) continue;
			for (int j = i + 5; j < min(len, r); j++)
			{
				for (int b = 'a'; b <= 'z'; b++)
				{
					if (d[j] == b) continue;

					string s(d);
					s[i] = a;
					s[j] = b;
					if (dict.count(s) > 0)
						return 2;
				}
			}
		}
	}

	return 10000;
}

int main()
{
	FILE* dictf = fopen("garbled_email_dictionary.txt", "r");
	char s[100];
	int maxLen = 0;
	while (fscanf(dictf, "%s", s) != EOF)
	{
		int len = strlen(s);
		if (len > maxLen) maxLen = len;
		dict.insert(string(s));
	}

	FILE* in = fopen("C-small-attempt1.in", "r");
	FILE* out = fopen("c.out.txt", "w");

	int t;
	fscanf(in, "%d", &t);
	for (int it = 1; it <= t; it++)
	{
		fscanf(in, "%s", data);
		int len = strlen(data);
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j <= 4; j++)
			{
				f[i][j] = 10000;
				for (int dj = 1; dj <= min(i + 1, 10); dj++)
				{
					int k = i - dj;
					for (int l = 0; l <= 4; l++)
					{
						int trans = findMinTransform(i - dj + 1, i, 5 - l - 1, dj - j);

						if (i - dj < 0)
						{
							f[i][j] = min(f[i][j], trans);
						}
						else
						{
							f[i][j] = min(f[i][j], f[k][l] + trans);
						}
					}
				}
			}
		}

		int minf = 10000;
		for (int i = 0; i <= 4; i++)
			if (f[len - 1][i] < minf) minf = f[len - 1][i];
		fprintf(out, "Case #%d: %d\n", it, minf);
	}

	return 0;
}
