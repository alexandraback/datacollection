#include <cstdio>

int T;
double C,F,X,opt,now,nows;
double EPS=0.00000001;
int main() {
	scanf("%d",&T);
	for(int ts=1;ts<=T;ts++) {
		scanf("%lf%lf%lf",&C,&F,&X);
		opt=X/2;
		now=0;
		nows=2;
		while(opt-EPS>now&&opt*(-EPS+1)>now) {
			now+=C/nows;
			nows+=F;
			if(opt>now+X/nows) opt=now+X/nows;
		}
		printf("Case #%d: %.7lf\n",ts,opt);
	}
	return 0;
}
