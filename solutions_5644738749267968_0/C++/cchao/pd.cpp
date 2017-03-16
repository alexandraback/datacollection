#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
double a[1010], b[1010];

int f() {
	int i = 0, j = 0, r = 0;
	while(i < n) { if(a[i] > b[j]) { i++; j++; r++; } else i++; }
	return r;
}

int g() {
	int i = 0, j = 0, r = n;
	while(i < n && j < n) {
		if(a[i] < b[j]) { ++i; ++j; --r; }
		else ++j;
	}
	return r;
}

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%lf", &a[i]);
		for(int i = 0; i < n; ++i) scanf("%lf", &b[i]);
		sort(a, a+n); sort(b, b+n);
		//for(int i = 0; i < n; ++i) printf("%.3f ", a[i]); puts("");
		//for(int i = 0; i < n; ++i) printf("%.3f ", b[i]); puts("");
		int a1, a2;
		a1 = f(); a2 = g();
		printf("Case #%d: %d %d\n", kase, a1, a2);
	}
	return 0;	
}