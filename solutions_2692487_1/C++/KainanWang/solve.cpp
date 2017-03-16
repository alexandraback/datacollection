#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;


int s[105];

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("a2.out", "w", stdout);


	int nc;
	cin >> nc;
	for (int cs = 1; cs <= nc; ++cs) {
		int a, n;
		cin >> a >> n;
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		sort(s, s + n);
		int res = n;
		
		
		if (a != 1)
		for (int i = 0, cur = 0; i < n; ++i) {
			while (a <= s[i]) {
				a += a - 1;
				++cur;		
			}
			a += s[i];
			res = min(res, cur + n - i - 1);
		}
		printf("Case #%d: %d\n", cs, res);
	}
	return 0;
}

