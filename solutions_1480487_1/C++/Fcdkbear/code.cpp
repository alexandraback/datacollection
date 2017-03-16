#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

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

using namespace std;
int a[210];
double y[210];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	FOR(it,1,t+1)
	{
		int n;
		scanf("%d",&n);
		int sum=0;
		int max1=0;
		FOR(i,0,n)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			max1=MAX(max1,a[i]);
		}
		double l=0,r=1e35;
		FOR(itt,0,200)
		{
			if (itt==199)
			{
				int k=1;
			}
			double m=(l+r)/2;
			double sum1=0;
			FOR(i,0,n)
			{
				if (a[i]>=m)
					continue;
				sum1+=(100*m-100*a[i])/(double)sum;
			}
			if (sum1>100)
				r=m;
			else
				l=m;
		}
		double mid=(l+r)/2;
		FOR(i,0,n)
		{
			if (a[i]>=mid)
				y[i]=0;
			else
				y[i]=(100*mid-100*a[i])/(double)sum;
		}
		printf("Case #%d:",it);
		FOR(i,0,n)
			printf(" %.10lf",y[i]);
		printf("\n");
	}
	return 0;
}