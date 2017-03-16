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
double p[100100];
double pr[100100];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	FOR(test,1,t+1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		double res=2+b;
		FOR(i,0,a)
			scanf("%lf",&p[i]);
		double prob=1;
		pr[0]=1;
		FOR(i,0,a)
		{
			prob*=p[i];
			pr[i+1]=prob;
		}
		double res1=(b-a+1)*prob+(1-prob)*(b-a+1+b+1);
		res=MIN(res,res1);
		FOR(i,0,a)
		{
			double prob=1-pr[i];
			double res1=prob*(a-i+b-i+1+b+1)+(1-prob)*(a-i+b-i+1);
			res=MIN(res,res1);
		}
		printf("Case #%d: %.10lf\n",test,res);
	}
	return 0;
}