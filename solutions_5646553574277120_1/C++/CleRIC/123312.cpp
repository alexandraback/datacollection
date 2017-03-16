#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <memory.h>

#include <time.h>
#pragma comment(linker, "/STACK:20000000")

#define fr(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define fd(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define mp make_pair
#define pb push_back
#define ll long long

using namespace std;

int ri(){int x;scanf("%d",&x);return x;}
ll rll(){ll x;scanf("%lld",&x);return x;}

int mas[50500];

void solve()
{
	int test = ri();
	fr(testing,1,test)
	{
		if (testing > 30)
			continue;
		int c = ri();
		int D = ri();
		int v = ri();
		int d = 0;
		for(int i = 0;i < D;i++)
		{
			int x = ri();
			for(int j = 1;j <= c;j++)
				mas[d++] = x;
		}
		sort(mas,mas + d);
		int pos = 0;
		int res = 0;
		ll sum = 0;
		for(int i = 1;i <= v;i++)
		{
			for(;pos < d && sum < i && sum + 1 >= mas[pos];)
				sum += mas[pos++];
			if (sum >= i)
				continue;
			int x = 0;
			for(int j = d - 1;j >= 0;j--)
			{
				int it = mas[j];
				if (x + it <= i)
					x += it;
			}
			if (x == i)
				continue;
			else
			{
				res++;
				for(int k = 1;k <= c;k++)
					mas[d++] = i;
				sort(mas,mas + d);
			}
		}

		printf("Case #%d: %d\n",testing,res);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("C:/Users/CleRIC/Desktop/Универ/acm.timus.ru/input.txt","rt",stdin);
		freopen("C:/Users/CleRIC/Desktop/Универ/acm.timus.ru/output.txt","wt",stdout);
	#else
		//freopen("input.in","rt",stdin);
		//freopen("output.out","wt",stdout);
	#endif

	solve();

	#ifndef ONLINE_JUDGE
		printf("\n\ntime-%.3lf",clock()*1e-3);
	#endif

	return 0;
}