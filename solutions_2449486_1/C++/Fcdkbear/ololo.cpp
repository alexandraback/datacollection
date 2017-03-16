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

int max1[110];
int max2[110];
int a[110][110];
int main()
{
#ifdef Fcdkbear
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    double beg=clock();
#else
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

	int t;
	scanf("%d",&t);
	FOR(it,0,t)
	{
		printf("Case #%d: ",it+1);
		bool f=true;
		MEMS(max1,0);
		MEMS(max2,0);
		int n,m;
		scanf("%d%d",&n,&m);
		FOR(i,0,n)
			FOR(j,0,m)
			{
				scanf("%d",&a[i][j]);
				max1[i]=MAX(max1[i],a[i][j]);
				max2[j]=MAX(max2[j],a[i][j]);
			}
		FOR(i,0,n)
			FOR(j,0,m)
				if ((a[i][j]!=max1[i]) && (a[i][j]!=max2[j]))
					f=false;
		if (f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}