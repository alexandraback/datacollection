#include<stdio.h>
#include<stdlib.h>
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.txt","w",stdout);
	int t,T,a,b,i;
	double c[100010],d[100010],ans;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d%d",&a,&b);
		d[0]=1.0;
		for(i=1;i<=a;i++){
			scanf("%lf",&c[i]);
			d[i]=d[i-1]*c[i];
		}
		ans=(double)b+2;
		for(i=0;i<=a;i++){
			if((double)a-i+((double)b-i+1)*d[i]+(1.0-d[i])*((double)b-i+2+b)<ans)
				ans=(double)a-i+((double)b-i+1)*d[i]+(1.0-d[i])*((double)b-i+2+b);
		}
		printf("Case #%d: %.6lf\n",t,ans+1e-9);
	}
} 
