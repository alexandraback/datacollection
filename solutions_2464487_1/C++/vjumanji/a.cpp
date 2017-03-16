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
#define pb              push_back
#define X               first
#define Y               second
#define scan(i)                 if (typeid(i)==typeid(int)) scanf("%d",&i);\
                        else    if (typeid(i)==typeid(long long)) scanf("%lld",&i);\
                        else    scanf("%s",&i);
#define print(i)                if (typeid(i)==typeid(int)) printf("%d",i);\
                        else    if (typeid(i)==typeid(long long)) printf("%lld",i);\
                        else    printf("%s",i);
#define nl              printf("\n");

long long r, t;

int f(int n)
{
	if (2*n+2*r-1 < t/n) return -1;
	if (2*n+2*r-1 > t/n) return 1;
	return 0;
}

long long solve()
{
	int lo=0, hi=-1u/2;
	long long v = (lo+hi)/2;
	while(!(f(v) <= 0 && f(v+1)>=0))
	{
		if (f(v) < 0 && f(v+1) < 0) lo = v+1;
		else hi = v-1;
		v = (lo+hi)/2;
	}
	if (f(v+1)==0) return v+1;
	if (f(v)==0) return v;
	return v;
}

int main()
{
	int T; cin>>T;
	FOR(x,1,T+1)
	{
		cin >> r >> t;
		printf("Case #%d: %d\n", x, solve());
	}
    return 0;
}
