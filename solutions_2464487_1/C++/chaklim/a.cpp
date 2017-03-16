#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

ll T, c, r, t, u, l, mid, t2, a;
const double PI = acos(-1.0);

ll cal(ll k) {
	return (2*r+2*k-1);
}

int main() {
	cin >> T;

	int c = 0;
	while (T--) {
		printf("Case #%d: ", ++c);

		cin >> r >> t;
		l = 1, u = 707106780;

		while (l <= u) {
			mid = (l + u) / 2;

			t2 = cal(mid);
			if (t2 <= t/mid) {
				a = mid;
				l = mid + 1;
			}
			else
				u = mid - 1;
		}

		cout << a << endl;
	}	

	return 0;
}
