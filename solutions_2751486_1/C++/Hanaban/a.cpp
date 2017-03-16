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
	
	vector<int> z(256, 1);
	z['a'] = 0;
	z['e'] = 0;
	z['i'] = 0;
	z['o'] = 0;
	z['u'] = 0;
	
	for (int c = 1; c <= t; ++c) {
		string x;
		int l, n;
		cin >> x >> n;
		l = x.size();
		
		long long ans = 0;
		int k = 0;
		int ps = 0;
		for (int i = 0; i < l; ++i) {
			if (z[x[i]]) {
				k++;
				if (k == n) {
					ans += (long long) (l - i) * (i - n - ps + 2);
					ps = i - n + 2;
					k--;
				}
			} else k = 0;
		}
		printf("Case #%d: %lld\n", c, ans);
		
	}
	
	return 0;
}
