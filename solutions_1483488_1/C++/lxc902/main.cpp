/*
ID: lxc9021
PROG: runround
LANG: C++
*/
/** @author starLeo
 *  Standard C++ Header File For Contests
 */
 //niubi
#include <iostream>
#include <fstream>
//#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <utility> //pair
#include <map>
//#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstring>
//#include <malloc.h>
using namespace std;
#define R(x) scanf("%d",&(x)) //read int
#define RS(x) scanf("%s",(x)) //read string
#define PL(x) printf("%d\n",(x)) //println int
#define REP(i,n) for(int i(0),_n(n);i<_n;++i)
#define FOR(i,l,h) for(int i(l),_h(h);i<=_h;++i)
#define FORD(i,h,l) for(int i(h),_l(l);i>=_l;--i)
#define RESET(a,b) memset((a),b,sizeof(a))
#define DEBUG(exp) (cout<<(#exp)<<" = "<<(exp)<<endl)
//#define oo (1234567890LL) // 64bits
#define oo (1<<29) // 32bits
//#define oo 9999999999.0 // Double
#define eps 1e-7
typedef long long Int;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;

#define N ( 102+10 )
#define E ( N*N )

int n,d;
int goleft(int t)
{
	return ((t%d)*10+t/d);
}
char vis[2000001];
int main()
{
#ifndef MyComputer
//    freopen("runround.in","r",stdin);
//    freopen("runround.out","w",stdout);
#endif

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

	int T; scanf("%d\n",&T);
	RESET(vis,0);
	FOR(ka,1,T)
	{
		int a,b;
		R(a),R(b);
		n=1,d=1;
		for(int t=a/10; t; t/=10)
		{
			n++;
			d*=10;
		}
		int ans=0;
		FOR(i,a,b-1)
		{
			int t=i,tn=n,now[9],k=0;
			while(--tn)
			{
				t=goleft(t);
				if(t>i && t<=b && !vis[t])
				{
					++ans;
					vis[t]=1;
					now[k++]=t;
				}
			}
			REP(j,k) vis[now[j]]=0;
		}
		printf("Case #%d: ",ka);
		PL(ans);
	}

    return 0;
}
