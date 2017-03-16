#include<stdio.h>
#include<math.h>
#define INF 100000000

double min(double a,double b){return a<b?a:b;}

int main(){
	int dn;
	scanf("%d",&dn);
	for(int di=0;di<dn;di++){
		double c,f,x;
		scanf("%lf %lf %lf",&c,&f,&x);
		double ans=x/2;
		double sum=0;
		for(int i=0;i<100000;i++){
			sum+=c/(f*i+2);
			ans=min(ans,sum+x/(f*(i+1)+2));
		}
		printf("Case #%d: %.7lf\n",di+1,ans);
	}
	return 0;
}
