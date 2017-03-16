#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <numeric>
#include <array>
#include <map>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <thread>
#include <sstream>
#include <atomic>

using namespace std;


int fun (long long x) {
	if (x<10) return x;
	if (x%10==0) return fun(x-1) + 1;
	int d = 0;
	long long tx = x;
	while (tx>0) {
		d++;
		tx/=10;
	}
	
	long long x10 = 1;
	long long x1=0;
	long long x2=0;
	for (int i=d/2; i<d; i++) {
		x1+=(x%10)*x10;
		x10*=10;
		x/=10;
	}
	
	for (int i=0; i< d/2; i++) {
		x2*=10;
		x2+=(x%10);
		x/=10;
	}
	if (x2!=1) x2++;
	x=1;
	for (int i=1; i<d; i++) x*=10;
	x--;
	return x1+x2+fun(x);
}


int main () {
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		long long N;
		scanf("%lld", &N);
		
		printf("Case #%d: %d\n", t, fun(N));
	}
	return 0;
}
