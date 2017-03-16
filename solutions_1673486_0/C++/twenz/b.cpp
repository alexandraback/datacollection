#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 100002
int main()
{
		freopen("A-small-attempt0.in","r",stdin);
//	freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,t,a,b;
	double p;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d",&a,&b);
		double ans = b+2;
		double pp = 1;
		for(j=1;j<=a;j++){
			scanf("%lf",&p);
			pp *= p;
			double e = pp*(b+1-j)+(1-pp)*(b+2-j+b);
			if(ans > e+a-j)ans=e+a-j;
		}
		printf("Case #%d: %.6lf\n",i,ans);
	}
	return 0;
}