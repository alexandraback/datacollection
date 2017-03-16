#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

char s[1000005];
int len;
int n;

bool isVowel (char c)
{
	return (c == 'a') || (c == 'o') || (c == 'i') || (c == 'e') || (c == 'u');
}

bool isConsonant (char c)
{
	return !isVowel(c);
}

void solve ()
{
	int firstR = -1;
	int cntConsonant = 0;

	long long ans = 0;

	for (int i = len - 1; i > -1; i--)
	{
		if (isVowel(s[i] ) )
		{
			cntConsonant = 0;
		}else
		{
			cntConsonant++;

			if (cntConsonant >= n)
				firstR = i + n - 1;
		}

		if (firstR != -1)
		{
			ans += len - firstR;
		}
	}

	printf("%lld", ans);
}

int main ()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int test, t;

	char c;

	scanf("%d\n", &test);
	for (t = 0; t < test; t++)
	{
		if (t)
			printf("\n");

		printf("Case #%d: ", t + 1);

		// input

		len = 0;

		scanf("%c", &c);
		while (c != ' ')
		{
			s[len++] = c;
			scanf("%c", &c);
		}

		scanf("%d\n", &n);

		// #input

		solve();
	}

	return 0;
}