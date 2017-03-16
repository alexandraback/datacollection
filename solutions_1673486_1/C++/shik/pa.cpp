// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
double p[N]={1};
int main()
{
	int t,cas=0,a,b;
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%d%d",&a,&b);
		for ( int i=1; i<=a; i++ ) scanf("%lf",p+i);
		double ans=1+b+1,now=1;
		for ( int i=0; i<=a; i++ ) {
			now*=p[i];
			double tmp=now*(a-i+b-i+1)+(1-now)*(a-i+b-i+1+b+1);
			ans=min(ans,tmp);
		}
		printf("Case #%d: %.9f\n",++cas,ans);
	}
	return 0;
}
