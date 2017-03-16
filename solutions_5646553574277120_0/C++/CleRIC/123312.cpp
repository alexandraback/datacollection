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



void solve()
{
	int test = ri();
	fr(testing,1,test)
	{
		ll c = ri();
		int d = ri();
		ll v = ri();
		set<ll> st;
		for(int i = 0;i < d;i++)
			st.insert(ri());
		int pos = 0;
		ll sum = 0;
		int res = 0;
		for(ll i = 1;i <= v;i++)
		{
			ll x = 0;
			for(set<ll>::reverse_iterator it = st.rbegin();it != st.rend();it++)
			{
				if (x + (*it) * c <= i)
					x += (*it) * c;
				else
				if (x + (*it) > i)
					continue;
				else
					x += (i - x) / (*it);
			}
			if (x == i)
				continue;
			else
				st.insert(i),res++;
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