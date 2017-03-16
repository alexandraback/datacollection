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

ll dp[50][2][2][2];

ll a,b,k;

ll stupid_solve()
{
	ll res = 0;
	fr(i,0,a)
		fr(j,0,b)
			res += (i & j) <= k ? 1 : 0;
	return res;
}

ll go(int pos,bool e1,bool e2,bool e3)
{
	if (pos == -1)
		return 1;
	if (dp[pos][e1][e2][e3] != -1)
		return dp[pos][e1][e2][e3];
	ll res = 0;
	bool ne1 = (a & (1LL << pos));
	bool ne2 = (b & (1LL << pos));
	bool ne3 = (k & (1LL << pos));
	int a1 = e1 ? ne1 : 1;
	int b1 = e2 ? ne2 : 1;
	int k1 = e3 ? ne3 : 1;
	fr(i,0,a1)
		fr(j,0,b1)
			fr(t,0,k1)
			{
				ll temp = 0;
				if ((i & j) == t)
				{
					temp += go(pos - 1,e1 & (i == a1),e2 & (j == b1),e3 & (t == k1));
				}
				res += temp;
			}

	return dp[pos][e1][e2][e3] = res;
}

void solve()
{
	int test = ri();
	fr(testing,1,test)
	{
		cin >> a >> b >> k;
		a--,b--,k--;
		//ll res2 = stupid_solve();
		ll res1 = 0;
		memset(dp,-1,sizeof(dp));
		res1 = go(40,1,1,1);

		printf("Case #%d: %lld\n",testing,res1);
		//cout << res1 << " " << res2 << endl;
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