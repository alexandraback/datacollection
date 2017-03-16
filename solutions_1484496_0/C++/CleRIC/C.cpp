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

ll mas[510];
ll dp[510];

int sum[20*100010];

void solve()
{
	int test=ri();
	fr(testing,1,test)
	{
		int n=ri();
		fr(i,0,n-1)
			mas[i]=rll();
		memset(sum,0,sizeof(sum));
		bool res=false;
		printf("Case #%d: ",testing);
		fd(i,(1<<n)-1,0)
		{
			int now=0;
			fr(j,0,20)
				if ((i&(1<<j)))
					now+=mas[j];
			if (sum[now])
			{
				cout << endl;
				fr(j,0,20)
					if (sum[now]&(1<<j))
						cout << mas[j] << ' ';
				cout << endl;
				fr(j,0,20)
					if ((i&(1<<j)))
						cout << mas[j] << ' ';
				res=true;
				break;
			}
			else
				sum[now]=i;
		}
		if (!res)
			cout << endl << "Impossible";
		cout << endl;
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