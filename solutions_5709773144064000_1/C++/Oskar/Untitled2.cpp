#include <cstdio>

int t;
double c, f, x;

int main(){
	freopen("zy.txt", "w", stdout);
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%lf %lf %lf", &c, &f, &x);
		double p = 2, t = 0, ans = x / p;
		while(true){
			t += c / p;
			p += f;
			if(ans < t + x / p){
				printf("Case #%d: %.7lf\n", i, ans);
				break;
			}else ans = t + x / p;
		}
		
	}
	
	scanf("\n");
}
