#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
	long long a, b;
	int n, ans;
	cin >> n;
	for (int t = 1; t <= n; ++t) {
	    cin >> a >> b;
		cout << "Case #" << t << ": ";
		ans = 0;
		while (b > 0) {
		    int c = (a+1) * (a+1) - a * a;
			if (b >= c) {
			    ++ans;
			    b -= c;
			    a += 2;
			} else {
			    b = 0;
			}
		}
		cout << ans << endl;
	}
    
    
    
    return 0;    
}
