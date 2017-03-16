#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cctype>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<map>
#include<set>
#define pi (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define rrep(i,n) for((i)=(n);(i)>=0;(i)--)
#define PB push_back
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
long double prob;
int main()
{
	freopen("A-small-attempt0(1).in","r",stdin);
	freopen("sol.out","w",stdout);
	int t,T,a,b,i,j;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
	    long double mn,nwp=1.0,p;
		scanf("%d%d",&a,&b);
		mn=b+2;
		rep(i,a)
		{
            scanf("%llf",&prob);
            mn=min(mn,nwp*(a-i+b-i+1)+(1-nwp)*(a-i+b-i+1+b+1));
            nwp*=prob;
		}
		mn=min(mn,nwp*(b-a+1)+(1-nwp)*(b-a+1+b+1));
		printf("Case #%d: ",t);
		printf("%.9llf\n",mn);
	}
	return 0;
}


