#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

typedef long long LL;

using namespace std;

double p[100100];

int main()
{
	int T;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> T;
	for(int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; ++i) {
			cin >> p[i];
		}
		double all_right_p = 1, max_e = m + 2;
		for(int i = 1, cnt_op; i <= n; ++i) {
			all_right_p *= p[i];
			cnt_op = n - i + m - i + 1;
			max_e = min(max_e, cnt_op * all_right_p + (cnt_op + m + 1) * (1 - all_right_p));
		}
		printf("%.6lf\n", max_e);
	}
	return 0;
}
