#include <stdio.h>

double timeNeed(double targ,double inc){
	return targ/inc;
}

int main(){

	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int test,tc=1;
	double ans,c,f,x,inc;
	
	for( scanf("%d",&test) ; test-- ; printf("Case #%d: %.7lf\n",tc++,ans) ){
		ans=0.0;
		inc=2.0;
		scanf("%lf%lf%lf",&c,&f,&x);
		
		// whiel upgrade < not upgrade-
		while( c/inc+x/(inc+f) < x/inc ){
			ans+=c/inc;
			inc+=f;
		}
		ans+=x/inc;		
	}
	
	return 0;
}

