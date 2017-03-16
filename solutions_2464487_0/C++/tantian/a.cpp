#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		double R,t;
		scanf("%lf %lf", &R,&t);
		R=2*R-1;
		int l=1, r=1000000000;
		int ans=1;
		while (l<=r){
			int m=(l+r)/2;
			double tt=m;
			tt=2*tt*tt+R*tt;
			if (tt<t+1e-6){
				l=m+1; ans=m;
			} else
				r=m-1;
		}
		printf("Case #%d: %d\n", T, ans);
	}
}
