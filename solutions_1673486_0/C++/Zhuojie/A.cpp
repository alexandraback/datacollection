#include<cstdio>

using namespace std;

int T,a,b;
double p[1000000];
int I=0;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&a,&b);
		for (int i=0;i<a;++i){
			scanf("%lf",&p[i]);
		}
		double ans = 1+b+1;
		double total = 1;
		for (int i=0;i<=a;++i){
			double tans = (a-i)+(b-i+1)+(1-total)*(b+1);
			total*=p[i];
			if (tans<ans) ans=tans;
		}
		printf("Case #%d: %.10lf\n", ++I, ans);
	}
}
