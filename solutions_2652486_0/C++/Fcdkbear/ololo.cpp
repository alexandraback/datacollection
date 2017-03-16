#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
 
using namespace std;
 
#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

int r,n,m,k;
vector<int> a,b;
bool go()
{
	if (a.size()==n)
	{
		bool ans=false;
		FOR(i,0,b.size())
		{
			ans=false;
			FOR(j,0,(1<<n))
			{
				int sum=1;
				FOR(k,0,n)
					if ((j>>k)&1)
						sum*=a[k];
				if (sum==b[i])
				{
					ans=true;
					break;
				}
			}
			if (!ans)
				return false;
		}
		return ans;
	}
	vector<int> c;
	FOR(i,2,m+1)
		c.push_back(i);
	random_shuffle(c.begin(),c.end());
	FOR(i,0,c.size())
	{
		a.push_back(c[i]);
		bool f=go();
		if (f)
			return true;
		a.pop_back();
	}
	return false;
}
int main()
{
#ifdef Fcdkbear
    double beg=clock();
#endif
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	
	int t;
	scanf("%d",&t);
	printf("Case #1:\n");
	cin>>r>>n>>m>>k;
	FOR(i,0,r)
	{
		a.clear();
		b.clear();
		b.resize(k);
		FOR(i,0,k)
			scanf("%d",&b[i]);
		bool f=go();
		if (!f)
			throw;
		FOR(i,0,a.size())
			printf("%d",a[i]);
		printf("\n");
	}
#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}