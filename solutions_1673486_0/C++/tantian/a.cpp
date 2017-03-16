#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int test=0;
	scanf("%d",&test);
	for (int T=1; T<=test; ++T){
		int l1,l2;
		scanf("%d%d",&l1,&l2);
		double ans=l2+2;
		double tmp=1;
		for (int i=0; i<l1; ++i){
			double x;
			scanf("%lf", &x);
			tmp=tmp*x;
			double tt=tmp*(l1-i+l2-i-1)+(1-tmp)*(l1-i+l2-i+l2);
			//printf("%d %.6lf\n", i+1,tt);
			ans=min(ans,tt);
		}
		printf("Case #%d: %.6lf\n", T,ans);
	}
}
