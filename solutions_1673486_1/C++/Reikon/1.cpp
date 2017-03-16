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

int test,I,i,j,have,all,back;
double a[100001],f[100001],ans,t;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	
	scanf("%d",&test);
	for (I=1; I<=test; ++I)
	{
		scanf("%d%d",&have,&all);
		for (i = 1; i<=have; ++i)
		{
			scanf("%lf",a+i);
			
		}
		f[0] = 1;
		for (i = 1; i<=have; ++i)
		{
			f[i] = f[i-1]*a[i];
		}
		
		ans = all+2;
		for (back = 0; back<=have; ++back)
		{
			i = have-back;
			t = f[i]*(back+1+all-have+back) + 
				(1-f[i])*(back+1+all-have+back+all+1);
			checkmin(ans,t);
		}
		printf("Case #%d: %f\n",I,ans);
	}
	
}

















