#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int t, n, m, ok, bad;
double result, prop[100100], p[100100];

int main () {
	cin >> t;
	int tt = 1;
	while (t--) {
		result = 1000000000;
		
		cin >> n >> m;
		for (int i=1; i<=n; i++)
			cin >> p[i];
		
		prop[0] = 1;
		for (int i=1; i<=n; i++) {
			prop[i] = prop[i-1] * p[i];

			ok = n - i + m - i + 1;
			bad = ok + m + 1;
			
			result = min(result, ok * prop[i] + bad * (1 - prop[i]));
		}
		result = min(result, m+2.);
		printf("Case #%d: %.6lf\n", tt++, result);
	}
}
