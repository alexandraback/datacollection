#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;
long long bsearch(long long a, long long n, long long t, long long r) {
	if (a == n - 1) return a;
	long long mid = (a+n)/2;
	//printf("XD: %lld\n", mid);
	if (2*mid*mid+ 2*r*mid - mid <= t) {
		return bsearch(mid, n, t, r);
	}else {
		return bsearch(a, mid, t, r);
	}
}

int main () {
	
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int T;
    cin >> T;
    long long r;
    long long t;

    for (int i = 1; i <= T; i++) {
    	cin >> r >> t;
		//long long used = 0;
    	long long n = 1;
    	while (n*n < t){
    		n = n*10;
    	}
    	// n > sqrt(t)
    	//cout <<"zz\n";
    	n *= 2;
    	if (n > t/r) n = t/r;
    	//cout << n << " = =\n";
    	long long ans = bsearch(1, n, t, r);
    	
    	printf("Case #%d: %lld\n", i, ans);
    }
    
    return 0;
}