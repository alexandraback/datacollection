#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#include <iostream>

using namespace std;

// -r^2 + (r+1)^2 - (r+2)^2 + (r+3)^2 + ...
// (2r + 1) + (2r + 5) + ...
// 

unsigned long long r, T;

int Check(unsigned long long k)
{
	return (2 * r + 2 * k - 1 <= T / k);
	// 2 * r * k + 2 * k * k - k;
}

void Work(int Case)
{
	scanf("%I64u%I64u", &r, &T);
	unsigned long long Ans = 0, Left = 1, Right = 2000000000;
	while (Left <= Right)
	{
		unsigned long long Mid = (Left + Right) / 2;
		if (Check(Mid))
		{
			Left = Mid + 1;
			Ans = Mid;
		}
		else
			Right = Mid - 1;
	}
	printf("Case #%d: %I64u\n", Case, Ans);
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
		Work(Case);
	return 0;
}