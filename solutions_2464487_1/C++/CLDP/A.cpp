#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxlen = 100;


int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    double a, b, c;
    long long p, q;
	int n;
    long long ans;
	cin >> n;
	for (int t = 1; t <= n; ++t) {
	    cin >> q >> p;
	    a = 2;
	    b = 2 * q + 3;
	    c = 2 * q + 1 - p;
		cout << "Case #" << t << ": ";
		if (2 * q + 1 > p) {
            cout << 0 << endl;
            continue;      
        }
		ans = (- 1.0 * b + sqrt(1.0 * b * b - 4 * a * c) - 0.0001) / (2.0 * a);
		++ans;
		if (2*q*(ans+1) + (2*ans+1)*(ans+1) <= p) ++ans;
		cout << ans << endl;
	}
    
    
    
    return 0;    
}
