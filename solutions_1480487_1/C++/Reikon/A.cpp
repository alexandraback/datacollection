#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#define REP(i,n)      for (i=0; i<(n); ++i)
#define FOR(i,l,r)    for (i=(l); i<=(r); ++i)
#define FOReach(it,c) for (__typeof(c.begin()) it=c.begin(); it!=c.end(); ++it)
#define foreach(c)    for (__typeof(c.begin()) it=c.begin(); it!=c.end(); ++it)
using namespace std;
typedef long long LL;
template <class T> inline void checkmin(T &a, T b) {if (b<a) a=b;}
template <class T> inline void checkmax(T &a, T b) {if (b>a) a=b;}
template <class T> inline T gcd(T a, T b) {if (!b) return a; return gcd(b,a%b);}

int test,i,n,a[200],b[200],I,sum,st;
double t;
int main()
{
//	freopen("A-small-attempt0.in","r",stdin); freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin); freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin); freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-small-attempt3.in","r",stdin); freopen("A-small-attempt3.out","w",stdout);
//	freopen("A-small-attempt4.in","r",stdin); freopen("A-small-attempt4.out","w",stdout);
	freopen("A-large.in","r",stdin); 		  freopen("A-large.out","w",stdout);
//	freopen("A.in","r",stdin);
	
	scanf("%d",&test);
	for (I=1; I<=test; ++I)
	{
		printf("Case #%d:",I);
		scanf("%d",&n);
		sum = 0;
		REP(i,n)
		{
			scanf("%d",a+i);
			b[i]  =a[i];
			sum+=a[i];
		}
		st = sum;
		sort(b,b+n);
		REP(i,n)
		{
			sum += b[i];
			t = (double)sum/(i+1);
			if (i==n-1 || t<b[i+1]) break;
		}
		REP(i,n)
		{
			if (a[i]>=t) printf(" %f",0.0);
			else		 printf(" %f",(t-a[i])/st*100);
		}
		printf("\n");
	}
}






















