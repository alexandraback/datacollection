#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
const int MAX=(int)1e5+5;
double p[MAX],s[MAX];
int main()
{
	int T,a,b;
	scanf("%d",&T);
	REP(tt,T) {
		scanf("%d%d",&a,&b);
		s[0]=1;
		sum[0]=0;
		for (int i=1; i<=a; i++) {
			scanf("%lf",p+i);
			s[i]=s[i-1]*p[i];
		}
		double ans=1.0*2*(b+1);
		ans=min(ans,1.0*(2*b-a+2)*(1-s[a])+(b-a+1)*s[a]);
		ans=min(ans,1.0*(b+2));
		for (int i=1; i<a; i++)
			ans=min(ans,1.0*(2*i+(b-a+1))*s[a-i]+1.0*(1-s[a-i])*(2*i+2*b-a+2));
		ans=min(ans,1.0*(b+a+1));
		printf("Case #%d: %.6lf\n",tt+1,ans);
	}
	return 0;
}
		
		
		
		
		
