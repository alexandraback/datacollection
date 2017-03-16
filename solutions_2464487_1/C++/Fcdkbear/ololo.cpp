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

double eps=1e-9;

int main()
{
#ifdef Fcdkbear
    double beg=clock();
#endif
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	
	int t;
	scanf("%d",&t);
	FOR(it,1,t+1)
	{
		LL r,T;
		cin>>r>>T;
		double have=T;
		LL le=1;
		LL ri=1514213562ll;
		LL best=0;
		while (le<=ri)
		{
			LL m=le+(ri-le)/2;
			double val=(4*m-2)*m/2+(double)m*2*(double)r;
			if (val-eps<=have)
			{
				best=m;
				le=m+1;
			}
			else
				ri=m-1;
		}
		printf("Case #%d: %d\n",it,best);
	}
	
#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}