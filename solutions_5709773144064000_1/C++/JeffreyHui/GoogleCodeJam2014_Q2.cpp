#include <cstdio>
#include <cstdlib>
int T,i;
double C,F,X,r,t,low,now;
int main (){
	freopen("B-large.in","r",stdin);
	freopen("GCJ14_Q_Q2_output.out","w",stdout);
	scanf("%d",&T);
	for (i=1;i<=T;i++){
		scanf("%lf %lf %lf",&C,&F,&X);
		r=2.0;
		t=0.0;
		now=t+X/r;
		low=X;
		while (low>now){
			low=now;
			t+=C/r;
			r+=F;
			now=t+X/r;
		}
		printf("Case #%d: %.7lf\n",i,low);
	}
	return 0;
}
