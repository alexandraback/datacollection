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

const long long mod = (long long) 1e9 + 7;

string s[105];
int n;

char buf[1000];

int cntLet[200], cntFrontLet[200], cntBackLet[200];
char frontChar[105], backChar[105];
bool trashString[105];

int identicalCnt[200];
char goLet[200];

bool usedLet[200];

long long ans;

long long fact (int n)
{
	long long res = 1;
	for (int i = 2; i <= n; i++)
		res = (res * i) % mod;
	return res;
}

bool checkInsideChar (char c, int cnt)
{
	return cntLet[c] == cnt;
}

void buildChain (char c)
{
	while (true)
	{
		usedLet[c] = true;
		ans = (ans * fact(identicalCnt[c] ) ) % mod;
		if (goLet[c] == 0)
			break;
		c = goLet[c];
	}
}

void solve ()
{
	memset(cntLet, 0, sizeof(cntLet) );
	for (int i = 0; i < n; i++)
		for (int j = 0; j < s[i].size(); j++)
			cntLet[s[i][j] ]++;
	memset(trashString, false, sizeof(trashString) );
	for (int i = 0; i < n; i++)
	{
		char firstLet = s[i].front();
		int sIt = 0;
		for (int j = 0; j < s[i].size(); j++)
		{
			if (s[i][j] != firstLet)
				break;
			sIt++;
		}
		char lastLet = s[i].back();
		int tIt = (int) s[i].size() - 1;
		for (int j = (int) s[i].size() - 1; j >= 0; j--)
		{
			if (s[i][j] != lastLet)
				break;
			tIt--;
		}

		if (sIt > tIt)
			continue;

		trashString[i] = true;

		char curChar = s[i][sIt];
		int cntCurChar = 0;
		for (int j = sIt; j <= tIt; j++)
		{
			if (s[i][j] == curChar)
			{
				cntCurChar++;
				continue;
			}

			if (!checkInsideChar(curChar, cntCurChar) )
			{
				printf("0");
				return ;
			}
			curChar = s[i][j];
			cntCurChar = 1;
		}
		if (!checkInsideChar(curChar, cntCurChar) )
		{
			printf("0");
			return ;
		}
	}

	for (int i = 0; i < n; i++)
	{
		frontChar[i] = s[i].front();
		backChar[i] = s[i].back();
	}

	for (int i = 0; i < n; i++)
	{
		if (trashString[i] && frontChar[i] == backChar[i] )
		{
			printf("0");
			return ;
		}
	}

	memset(cntLet, 0, sizeof(cntLet) );
	memset(cntFrontLet, 0, sizeof(cntFrontLet) );
	memset(cntBackLet, 0, sizeof(cntBackLet) );
	memset(identicalCnt, 0, sizeof(identicalCnt) );
	memset(goLet, 0, sizeof(goLet) );
	for (int i = 0; i < n; i++)
	{
		if (frontChar[i] == backChar[i] )
			identicalCnt[frontChar[i] ]++;
		else
			goLet[frontChar[i] ] = backChar[i];

		cntLet[frontChar[i] ]++;
		cntLet[backChar[i] ]++;
		if (frontChar[i] != backChar[i] )
		{
			cntFrontLet[frontChar[i] ]++;
			cntBackLet[backChar[i] ]++;
		}
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		if (cntFrontLet[c] >= 2 || cntBackLet[c] >= 2)
		{
			printf("0");
			return ;
		}
	}

	memset(usedLet, false, sizeof(usedLet) );
	ans = 1;
	int cntChains = 0;
	for (char c = 'a'; c <= 'z'; c++)
	{
		if (cntLet[c] > 0 && cntBackLet[c] == 0)
		{
			cntChains++;
			buildChain(c);
		}
	}

	for (char c = 'a'; c <= 'z'; c++)
	{
		if (cntLet[c] > 0 && !usedLet[c] )
		{
			printf("0");
			return ;
		}
	}

	ans = (ans * fact(cntChains) ) % mod;
	printf("%lld", ans);
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

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", &buf);
			s[i] = string(buf);
		}

		// #input

		solve();
	}

	return 0;
}