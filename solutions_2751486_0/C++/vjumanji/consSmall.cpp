#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <typeinfo>

using namespace std;

#define FOR(i,a,b)      for(int i(a);i<b;++i)
#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
#define REP(i,n)        FOR(i,0,n)
#define CL(a,x)         memset(a,x,sizeof(a))
#define FL(a,x)			fill_n(a,sizeof(a)/sizeof(a[0]),x)
#define asort(a,n)		sort(a,a+n)
#define vsort(v,n)		sort(v.begin(), v.begin()+n)
#define pb              push_back
#define X               first
#define Y               second
#define scan(i)			if (typeid(i)==typeid(int)) scanf("%d",&i);\
			else    if (typeid(i)==typeid(long long)) scanf("%lld",&i);\
			else    scanf("%s",&i);
#define print(i)		if (typeid(i)==typeid(int)) printf("%d",i);\
			else    if (typeid(i)==typeid(long long)) printf("%lld",i);\
			else    printf("%s",i);
#define nl		printf("\n");

int n,L;
char S[1000];

bool valid(int i, int w)
{
	int co = 0;
	for (int x=i; x<i+w; x++)
	{
		if (S[x]=='a' || S[x]=='e' || S[x]=='i' || S[x]=='o' || S[x]=='u')
		{
			co = 0;
		}
		else{
			co++;
		}
		if (co==n) return true;
	}
	return false;
}

int solve()
{
	int res=0;
	for (int i=1; i<=L; i++)
		for (int j=0; j+i<=L; j++)
		{
			if (valid(j,i))
			{
				res++;
			}
		}
	return res;
}

int main()
{
	int t; scan(t);
	REP(i, t)
	{
	scan(S);
	L = strlen(S);
	cin >> n;
	cout << "Case #"<<i+1<<": "<< solve();nl;
	}
	return 0;
}
