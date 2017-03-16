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

char s[1005000];

bool vowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

ll check(int len,int n)
{
	ll res = 0;
	fr(i,0,len-1)
	{
		int now = 0;
		bool yes = false;
		fr(j,i,len-1)
		{
			if (yes)
				res++;
			if (vowel(s[j]))
				now = 0;
			else
			{
				now++;
				if (now>=n)
					yes = true;
			}
		}
		if (yes)
			res++;
	}
	return res;
}

void solve()
{
	int test = ri();
	fr(ntest,1,test)
	{
		scanf("%s",s);
		int len = strlen(s);
		int n = ri();
		ll res = 0;
		int now = 0;
		vector<int> st;
		fr(i,0,len-1)
		{
			if (vowel(s[i]))
				now = 0;
			else
				now++;
			if (now>=n)
				st.push_back(i-n + 1);
		}
		bool yes = false;
		int m = st.size();
		if (m)
		{
				int ind = 0;
				int last = 0;
				fr(i,0,m-1)
				{
					res += ((ll)st[i] - last + 1) * ((ll)len - st[i] - n + 1);
					last = st[i] + 1;
				}
		
		}
		printf("Case #%d: %lld\n",ntest,res);
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