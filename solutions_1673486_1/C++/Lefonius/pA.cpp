#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

double p[100005];

inline double MIN(double a, double b){
	return a<b?a:b;
}

int main(){
	int t, time=0, a, b, i, j;
	double ans, tmp;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		for(i=1, tmp=1; i<=a; i++){
			scanf("%lf", &p[i]);
			tmp*=p[i];
		}
		
		ans=b+2;
		
		for(i=1, tmp=1; i<=a; i++){
			tmp*=p[i];
			ans=MIN(ans, tmp*(a-i+b-i+1)+(1-tmp)*(a-i+b-i+1+b+1));
			//printf("now i=%d, tmp = %f, ans=%f\n", i, tmp*(a-i+b-i+1)+(1-tmp)*(a-i+b-i+1+b+1), ans); 
		}
		printf("Case #%d: %f\n", ++time, ans);
	}
	return 0;
}
