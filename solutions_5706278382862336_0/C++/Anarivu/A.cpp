#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

long long gcd(long long a, long long b)
{
	while(b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

long long pw[55];
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	pw[0] = 1;
	for(int i = 1; i < 55; i++)
		pw[i] = pw[i-1] * 2;

	int TT;
	scanf("%d", &TT);
	for(int T = 0; T < TT; T++)
	{
		printf("Case #%d: ", T+1);
		long long a, b;
		scanf("%lld/%lld", &a, &b);
		long long nd = gcd(a, b);
		a /= nd;
		b /= nd;
		bool f = 0;
		int id = 0;
		for(int i = 0; i < 41 && !f; i++)
		{
			if(b == pw[i])
				f = 1, id = i;
		}
		if(!f)
		{
			printf("impossible\n");
			continue;
		}
		for(int i = 0, j = id; i <= id; i++, j--)
		{
			if(a >= pw[j])
			{
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}