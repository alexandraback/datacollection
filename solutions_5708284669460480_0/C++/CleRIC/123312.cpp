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

string key;
string need;
int k,l,s;
string temp;

double res;
int mx = 0;

void go(int ost,double q)
{
	if (ost == 0)
	{
		int cnt = 0;
		for(int i = 0;i < temp.length() - l + 1;i++)
		{
			if (temp.substr(i,l) == need)
				cnt++;
		}
		mx = max(mx,cnt);
		//res += (2 - cnt) * q;
		return;
	}
	for(int i = 0;i < k;i++)
	{
		temp.pb(key[i]);
		go(ost - 1,q * (1.0 / k));
		temp.pop_back();
	}
}

void go2(int ost,double q)
{
	if (ost == 0)
	{
		int cnt = 0;
		for(int i = 0;i < temp.length() - l + 1;i++)
		{
			if (temp.substr(i,l) == need)
				cnt++;
		}
		//mx = max(mx,cnt);
		res += (mx - cnt) * q;
		return;
	}
	for(int i = 0;i < k;i++)
	{
		temp.pb(key[i]);
		go2(ost - 1,q * (1.0 / k));
		temp.pop_back();
	}
}

void solve()
{
	int test = ri();
	fr(testing,1,test)
	{
		k = ri(),l = ri(),s = ri();
		res = 0.0;
		cin >> key >> need;
		mx = 0;
		go(s,1.0);
		go2(s,1.0);
		printf("Case #%d: %.9lf\n",testing,res);
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