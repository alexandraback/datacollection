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


int main()
{
	int T; cin>>T;
	long long r, t;
	FOR(x,1,T+1)
	{
		cin >> r >> t;
		int ans = floor((sqrt((2*r-1)*(2*r-1) + 8*t) - (2*r-1))/4.0);
		printf("Case #%d: %d\n", x, ans);
	}
    return 0;
}
