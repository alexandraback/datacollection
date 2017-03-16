#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <iterator>
#include <set>
using namespace std;

struct tdot {
	int x, y;
}	a[100000];

int cmp(tdot a, tdot b) {
	return a.x > b.x;
}

int b[100000], c[100000];

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T, TT = 0, E, R, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &E, &R, &n);
		set<int> st; st.clear();
		for (int i = 0; i < n; i++) scanf("%d", &a[i].x);
		for (int i = 0; i < n; i++) a[i].y = i;
		sort(a, a + n, cmp);
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			int nt, lt;
			if (!st.empty() && st.lower_bound(a[i].y) != st.end()) nt = * st.lower_bound(a[i].y);
			else nt = -1;
			if (!st.empty() && st.lower_bound(a[i].y) != st.begin()) {
				set<int>::iterator p = st.lower_bound(a[i].y);
				p--;
				lt = * p;
			}
			else lt = -1;
			// cout << lt << ' ' << nt << endl;
			long long s;
			if (lt == -1) s = E;
			else s = min((long long) E, c[lt] + ((long long) R) * (a[i].y - lt));
			b[a[i].y] = s;
			c[a[i].y] = 0;
			if (nt != -1) {
				c[a[i].y] = max(0LL, (long long) b[nt] - (long long) R * (nt - a[i].y));
				s -= c[a[i].y];
			}
			st.insert(a[i].y);
			// cout << s << ' ' << a[i].x << endl;
			ans += s * a[i].x;
		}
		cout << "Case #" << ++TT << ": " << ans << endl;
	}
	return 0;
}
