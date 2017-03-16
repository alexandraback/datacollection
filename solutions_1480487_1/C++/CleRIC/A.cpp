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

int mas[205];

bool check(double x,int n,int sum)
{
	double answer=1.0;
	fr(i,1,n)
	{
		double buf=(double)x-mas[i];
		if (buf<1e-12)
			continue;
		answer-=(double)buf/sum;
	}
	return answer>1e-12;
}

void solve()
{
	int test=ri();
	fr(testing,1,test)
	{
		int n=ri();
		fr(i,1,n)
			mas[i]=ri();
		int sum=0;
		fr(i,1,n)
			sum+=mas[i];
		double l=0.0,r=(double)sum;
		fr(i,1,70)
		{
			double MID=(l+r)/2.0;
			if (check(MID,n,sum))
				l=MID;
			else
				r=MID;
		}
		printf("Case #%d: ",testing);
		fr(i,1,n)
			printf("%.10lf ",max(100.0*((double)l-mas[i])/(double)sum+1e-9,0.0));
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