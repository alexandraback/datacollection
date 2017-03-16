#include <stdio.h>

int main(){
	int n;
	int i,l;
	double c,f,x;
	double coef, ans;
	scanf("%d",&n);
	for(l=1;l<=n;l++){
		scanf("%lf %lf %lf",&c,&f,&x);
		ans = 0;
		coef = (x-c)/x;
		for(i=0;coef > (2+i*f)/(2+(i+1)*f);i++){ ans += (c/(2+i*f)); }
		ans += (x/(2+i*f));
		printf("Case #%d: %.7lf\n",l,ans);
	}
	return 0;
}
