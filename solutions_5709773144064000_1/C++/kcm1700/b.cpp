#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		double C,F,X;
		scanf("%lf%lf%lf",&C,&F,&X);
		double ans = X / 2;
		double rate = 2;
		double elapsed = 0;
		while(elapsed < ans){
			ans = min(ans, X/rate + elapsed);
			elapsed += C/rate;
			rate += F;
		}
		printf("Case #%d: %.10f\n", testcase, ans);
	}
	return 0;
}
