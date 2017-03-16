#include <iostream>
#include <cstdio>
using namespace std;

int mod(int p){
	if(p < 0) return -1 * p;
	return p;
}

long long factorial(int n){
	if(n==1 || n==0) return 1;
	long long t = n * factorial(n-1);
	return t;
}

long long NCR(int n, int r){
	long long p = factorial(n);
	long long q = factorial(n-r) * factorial(r);
	return p / q;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int m=0; m<n; m++){
		int l,x,y;
		scanf("%d %d %d", &l, &x, &y);

		int arr = 1; // = 1,2,3,4 :: 1,6,15,28

		while(4*arr*arr - 2*arr < 2*l) {
			arr += 1;
		}

		int vals = 1 + (arr-1)*4; // number fo values -> 3 -> 9

		x = mod(x);
		y = mod(y);

		if (x + y < ((arr-1)*2)) {
			printf("Case #%d: 1.0\n", m+1);
			continue;
		}

		if ( x + y >= (arr*2)) {
			printf("Case #%d: 0.0\n", m+1);
			continue;
		}

		// y axis is coordniate
		// x + y == arr - 1 * 2
		int ar = arr-1;
		int at = l - (ar * (2 + (ar-1)*4)) / 2;

		if (vals == at) {
			printf("Case #%d: 1.0\n", m+1);
			continue;			
		}

		double p = 1 / 2.0;
		int t = y + 1;

		while (at > vals / 2) {
			at -= 2;
			t -= 1;
		}

		if (t < 0) {
			printf("Case #%d: 1.0\n", m+1);
			continue;
		}

		double sum = 0;
		for (int i=t; i<=at; i++) {
			sum += NCR(at, i);
		}

		for (int i=0; i<at; i++) {
			sum *= p;
		}

		printf("Case #%d: %lf\n", m+1, sum);
	}
	return 0;
}