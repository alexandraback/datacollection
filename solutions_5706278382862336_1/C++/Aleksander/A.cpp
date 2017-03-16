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

char s[1000];
int sLen;
int sIt;
long long a, b;

long long gcd (long long a, long long b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

void readNumber (long long & val)
{
	val = 0;
	for ( ; ; sIt++)
	{
		if (!isdigit(s[sIt] ) )
			break;
		val = val * 10 + (s[sIt] - '0');
	}
}

void readChar ()
{
	sIt++;
}

bool isPowerTwo (long long val)
{
	while (val != 1)
	{
		if (val & 1)
			return false;
		val >>= 1;
	}
	return true;
}

void solve ()
{
	long long g = gcd(a, b);
	a /= g; b /= g;

	if (a == 0 || !isPowerTwo(b) )
	{
		printf("impossible");
		return ;
	}

	int ans = 0;
	while (a < b)
	{
		a *= 2;
		ans++;
	}
	printf("%d", ans);
}

int main ()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int test_amount, test_num;

	scanf("%d\n", &test_amount);
	for (test_num = 0; test_num < test_amount; test_num++)
	{
		if (test_num)
			printf("\n");

		printf("Case #%d: ", test_num + 1);

		// input

		gets(s);
		sLen = strlen(s);
		sIt = 0;
		readNumber(a);
		readChar();
		readNumber(b);

		// #input

		solve();
	}

	return 0;
}