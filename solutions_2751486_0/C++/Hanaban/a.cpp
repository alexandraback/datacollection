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
		
		int a[l][l];
		int ans = 0;
		bool ok = false;
		memset(a, 0, sizeof(a) );
		for (int i = 0; i < l; ++i) {
			ok = false;
			if (z[x[i]]) {
				a[i][i] = 1;
				if (a[i][i] >= n) ok = true;
				if (ok) ++ans;
			}
			for (int j = i + 1; j < l; ++j) {
				if (z[x[j]]) {
					a[i][j] = a[i][j - 1] + 1;
					if (a[i][j] >= n) ok = true;
				} else {
					a[i][j] = 0;
				}
				if (ok) ++ans;
			}
		}
		printf("Case #%d: %d\n", c, ans);
		
	}
	
	return 0;
}
