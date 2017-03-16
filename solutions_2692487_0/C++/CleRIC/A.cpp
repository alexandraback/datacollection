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

int mas[105];

void solve()
{
	int test = ri();
	for(int tst = 1; tst <= test; tst++)
	{
		int a = ri(), n = ri();
		fr(i,1,n)
			mas[i] = ri();
		if (a == 1)
		{
			printf("Case #%d: %d\n",tst,n);
			continue;
		}
	
		sort(mas+1,mas+1+n);
		vector<int> st;
		int res = 2e9;
		int cnt = 0;
		for(int i = 1;i<=n;i++)
		{
			if (a>mas[i])
				a+=mas[i];
			else
			{
				res = min(res,cnt + n - i + 1);
				cnt++;
				a += a - 1;
				if (a<=mas[i])
					i--;
				else
					a+=mas[i];
			}
		}
		printf("Case #%d: %d\n",tst,min(res,cnt));
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