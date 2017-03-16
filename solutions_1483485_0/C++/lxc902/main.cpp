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

char maz[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
#ifndef MyComputer
//    freopen("runround.in","r",stdin);
//    freopen("runround.out","w",stdout);
#endif

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

	int t; scanf("%d\n",&t);
	FOR(i,1,t)
	{
		char s[333]; gets(s);
		printf("Case #%d: ",i);
		REP(j,strlen(s))
		{
			if(s[j]==' ') putchar(' ');
			else putchar(maz[s[j]-'a']);
		}
		puts("");
	}

    return 0;
}
