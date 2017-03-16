#include <stdio.h>

double p[100000];

int main(){
	int T;
	int a, b;
	scanf("%d", &T);
	for(int TT = 1; TT<=T; TT++){
		scanf("%d%d", &a, &b);
		double mini = 1e100;
		double v = 1, t;
		for(int i = 0; i < a; i++){
			t = v*((a-i)+b-i+1) + (1-v)*((a-i)+b-i+1+b+1);
			if(t < mini)
				mini = t;
			scanf("%lf", &p[i]);
			v *= p[i];
		}
		t = v*(b-a+1) + (1-v)*(b-a+1+b+1);
		if(t < mini)
			mini = t;
		t = 1 + b + 1;
		if(t < mini)
			mini = t;
		printf("Case #%d: %.16lf\n", TT, mini);
	}
}