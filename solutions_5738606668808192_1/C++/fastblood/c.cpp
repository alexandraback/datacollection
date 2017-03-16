#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef long long lint;
typedef unsigned long long ull;

#define pb push_back
#define mp make_pair

int n;
bool x[32];

const int MaxDivisor = 100;

int pre[MaxDivisor][11][32];

bool checkBase(int base)
{
	for (int i = 3; i < MaxDivisor; i++)
	{
		int val = 0;
		for (int j = 0; j < n; j++)
			if (x[j])
				val = (val + pre[i][base][j]) % i;
		if (val == 0)
			return true;
	}

	return false;
}

void printDivisorInBase(int base)
{
	for (int i = 3; i < MaxDivisor; i++)
	{
		int val = 0;
		for (int j = 0; j < n; j++)
			if (x[j])
				val = (val + pre[i][base][j]) % i;
		if (val == 0)
		{
			printf(" %d", i);
			return;
		}
	}
}

bool check()
{
	for (int i = 2; i <= 10; i++)
		if (!checkBase(i))
			return false;

	return true;
}

void precalc()
{
	for (int i = 3; i < MaxDivisor; i++)
		for (int j = 2; j <= 10; j++)
		{
			int val = 1;
			for (int k = 0; k < 32; k++)
			{
				pre[i][j][k] = val;
				val = (val * j) % i;
			}
		}
}

void solve(int testNumber)
{
	precalc();

	int J;
	scanf("%d%d", &n, &J);
	printf("\n");

	int m = n / 2;

	while (J)
	{
		while (true)
		{
			fill(x, x + 32, 0);
			x[0] = x[n - 1] = 1;
			for (int i = 0; i < m; i++)
				x[1 + (rand() % (n - 2))] = 1;

			if (check())
				break;
		}

		for (int i = n - 1; i >= 0; i--)
			printf("%d", x[i]);
		for (int i = 2; i <= 10; i++)
			printDivisorInBase(i);
		printf("\n");

		J--;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tn;
	scanf("%d", &tn);
	for (int i = 0; i < tn; i++)
	{
		printf("Case #%d: ", i + 1);
		solve(i + 1);
	}
}
