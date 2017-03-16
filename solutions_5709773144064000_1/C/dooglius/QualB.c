#include <math.h>
#include <stdio.h>

double go(void){
	double c,f,x;
	scanf("%lf %lf %lf",&c,&f,&x);
	int n = (int)(floor(x/c-2/f));
	if(n<0) n=0;
	double ans = 0;
	int i;
	for(i=0; i<n; i++){
		ans += c/(2+f*i);
	}
	return ans+x/(2+f*n);
}

int main(int argc, char** argv){
	int t;
	scanf("%d",&t);
	int i;
	for(i=1; i<=t; i++){
		double ans = go();
		printf("Case #%d: %.7lf\n",i,ans);
	}
	return 0;
}
