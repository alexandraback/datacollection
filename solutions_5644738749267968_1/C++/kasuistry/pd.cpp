
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int sol(double *a, double *b, int n){
	int ans = 0;
	int aptr = 0, bptr = 0;
	while(aptr < n && bptr < n){
		if(a[aptr] < b[bptr]){
			++ ans;
			aptr ++;
			bptr ++;
		}else{
			bptr ++;
		}
	}
	return n-ans;
}

int sol2(double *a, double *b, int n){
	int ans = 0;
	int aptr = 0, bptr = 0;
	while(aptr < n && bptr < n){
		if(a[aptr] < b[bptr]){
			++ aptr;
		}else{
			++ ans;
			aptr ++;
			bptr ++;
		}
	}
	return ans;
}

int main(){
	
	int testcase; scanf("%d", &testcase);
	int n;
	double a[1000], b[1000];

	for(int t=1; t<=testcase; ++t){
		scanf("%d", &n);
		for(int i=0; i<n; ++i){
			scanf("%lf", &a[i]);
		}
		for(int i=0; i<n; ++i){
			scanf("%lf", &b[i]);
		}

		sort(a, a+n);
		sort(b, b+n);

		printf("Case #%d: %d %d\n", t, sol2(a, b, n), sol(a, b, n));
	}
	return 0;
}
