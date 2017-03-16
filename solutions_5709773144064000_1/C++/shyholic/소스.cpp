#include<cstdio>

int T;
double C,F,X;

double process(){
	double cur = 0;
	double inc = 2.0;
	double time = 0;
	double tc = 0, tnf = 0;
	double mintime = X / inc;
	while(true){
		tc = (X - cur) / inc; // Time-to-complete
		tnf = (C - cur) / inc; // Time-to-next-farm

		if(time + tc <= mintime) mintime = time + tc;\
		else break;

		if(tc <= tnf) break;

		time = time + tnf;
		cur = 0;
		inc = inc + F;
	}
	return mintime;
}

int main(void){
	int t;
	double ans;
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%lf %lf %lf", &C, &F, &X);
		ans = process();
		printf("Case #%d: %lf\n",t, ans);
	}
	return 0;
}