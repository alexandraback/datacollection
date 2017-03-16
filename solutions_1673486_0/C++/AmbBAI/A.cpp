#include<cstdio>
#include<cstring>
using namespace std;

double val[100010];
double sum[1000010];
int main(){
	freopen("A-small-attempt0.in","r",stdin) ;
	freopen("smallA.out","w",stdout) ;
	
	int t, cas=1;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d%d",&n,&m);
		sum[0]=1;
		for(int i=1;i<=n;i++){
			scanf("%lf",&val[i]);
			sum[i]=sum[i-1]*val[i];
		}

		double ans;
		if(n<m) ans = m+2;
		else ans = sum[m]*1.0+(1-sum[m])*(m+2);
		for(int i=n;i>=0;i--){
			double tmp = n-i+sum[i]*(m-i+1)+(1-sum[i])*(m*2-i+2);
			if (tmp<ans) ans=tmp;
		}
		printf("Case #%d: %.6f\n",cas++,ans);
	}
}