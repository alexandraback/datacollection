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

struct node
{
	int a,b,get1;
}
a[2000];
int test,I,i,p,n,ans,star;
bool cmp(const node &a,const node &b)
{
	if (a.b==b.b)
		return a.a<b.a;
	return a.b<b.b;
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&test);
	for (I=1; I<=test; ++I)
	{
		ans = 0;
		star =0;
		scanf("%d",&n);
		for (i = 1; i<=n; ++i)
		{
			scanf("%d%d",&a[i].a,&a[i].b);
			a[i].get1 = 0;
			
		}
		sort(a+1,a+n+1,cmp);
		
		for (i = 1; i<=n; ++i)
		{
			if (a[i].b<=star)
			{
				++ans;
				if (a[i].get1 ==1)
					star++;
				else
					star+=2;
			}
			else
			{
				p = n;
				while (a[i].b>star && p>=i)
				{
					if (a[p].get1==0 && a[p].a<=star)
					{
						a[p].get1 = 1;
						star+=1;
						ans++;
					}
					p--;
				}
				if (a[i].b<=star)
				{
					ans++;
					if (a[i].get1==1)
						star+=1;
					else
						star+=2;
				}
				else
				{
					printf("Case #%d: Too Bad\n",I);
					goto _;
				}
			}
		}
		printf("Case #%d: %d\n",I,ans);
		_: ;
	}
	
	
}













