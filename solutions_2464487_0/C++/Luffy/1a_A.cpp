#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main () {
	
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int T;
    cin >> T;
    long long r;
    long long t;

    for (int i = 1; i <= T; i++) {
    	cin >> r >> t;
		long long used = 0;
    	long long n;
    	for (n = 1; used <= t; n++) {
    		used += (2*r + 4*n - 3);
    		//printf("%lld\n", used);
    	}
    	printf("Case #%d: %lld\n", i, n-2);
    }
    
    return 0;
}