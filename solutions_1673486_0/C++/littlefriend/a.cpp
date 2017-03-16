#include<cstdio>
void cmin(long double &a,long double b) {if (b<a) a=b;}
int main(){
	long double now,q,res;
	double p;
	int i,j,t,a,b;
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d",&t);
	for (j=1;j<=t;j++){
		scanf("%d%d",&a,&b);
		res=2+b;
		now=1;
		for (i=0;i<a;i++){
			scanf("%lf",&p);
			q=(long double)p;
			now*=q;
			cmin(res,(a-i-1)+now*(b-i)+(1-now)*(2*b-i+1));
		}
		printf("Case #%d: %.6lf\n",j,(double)res);
	}
	return 0;
}
