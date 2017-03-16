#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	for (int c = 1; c <= t; ++c) {
		long long a;
		int n;
		cin >> a >> n;
		vector<long long> x(n);
		for (int i = 0; i < n; ++i) cin >> x[i];
		sort(x.begin(), x.end() );
		
		int ans = 0;
		int minans = n;
		int ca = 0;
		for (int i = 0; i < n; ++i) {
			minans = min(ca + n - i, minans);
			if (a == 1 && a <= x[i]) break;
			while (a <= x[i]) {
				a += a - 1;
				++ca;
			}
			a += x[i];
			if (i == n - 1) minans = min(minans, ca);
		}
		printf("Case #%d: %d\n", c, minans);
	}
	
	return 0;
}
