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

int hash[2000000],i,j,test,I,loop,n,s,get,k;
int a[20],f[20];
int main()
{
	freopen("C-small-attempt0.in","r",stdin); freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin); freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin); freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-small-attempt3.in","r",stdin); freopen("C-small-attempt3.out","w",stdout);
//	freopen("C-small-attempt4.in","r",stdin); freopen("C-small-attempt4.out","w",stdout);
//	freopen("C-large.in","r",stdin); 		  freopen("C-large.out","w",stdout);
//	freopen("C.in","r",stdin);
	
	scanf("%d",&test);
	for (I=1; I<=test; ++I)
	{
		printf("Case #%d:\n",I);
		scanf("%d",&n);
		get = -1;
		for (i=0; i<n; ++i)
		{
			f[i]  =0;
		}
		loop = 1<<n;
		for (i=0; i<n; ++i)
			scanf("%d",a+i);
		memset(hash,0,sizeof(hash));
		memset(f,0,sizeof f);
			
		for (i=0; i<loop; ++i)
		{
			s = 0;
			for (j =0; j<20; ++j)
				if (f[j])
				s+=a[j];
			if (hash[s])
			{
				get = s;
				break;
			}
			else
			{
				hash[s] = 1;
			}
			if (i!=loop-1)
			{
				j = 0;
				while (f[j]==1) j++;
				f[j] = 1;
				for (k=0; k<j; ++k)
					f[k]  =0;
			}
		}
		if (get==-1)
		{
			printf("Impossible\n");
		}
		else
		{
			int flag = 0;
			for (int z = 0; z<20; ++z)
			{
				if (f[z])
				{
					if (flag)
						printf(" ");
					else
						flag  = 1;
					printf("%d",a[z]);
				}
				
			}
			printf("\n");
			memset(f,0,sizeof f);

			for (i=0; i<loop; ++i)
			{
				s = 0;
				for (j =0; j<20; ++j)
					if (f[j])
						s+=a[j];
				if (s==get)
				{
					int flag = 0;
					for (int z = 0; z<20; ++z)
					{
						if (f[z])
						{
							if (flag)
								printf(" ");
							else
								flag  = 1;
							printf("%d",a[z]);
						}
				
					}
					printf("\n");
					break;
				}
			
				if (i!=loop-1)
				{
					j = 0;
					while (f[j]==1) j++;
					f[j] = 1;
					for (k=0; k<j; ++k)
						f[k]  =0;
				}
			}
		}
	}
}


















