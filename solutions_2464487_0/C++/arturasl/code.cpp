#include      <algorithm>
#include      <cmath>
#include      <cstdarg>
#include      <cstdio>
#include      <cstdlib>
#include      <iomanip>
#include      <iostream>
#include      <iterator>
#include      <limits>
#include      <list>
#include      <map>
#include      <set>
#include      <vector>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
typedef unsigned long long ll;
using namespace std;

long double const pi = acos(-1);

ll t, r;

ll left(ll i) {
	return r * (i + 1) * 2;
}

ll right(ll i) {
	return (i + 1) * (2 * i + 1);
}

ll solve() {
    ll l = 0, h = 10000000000ll, m;
    while (l < h) {
        m = l + ((h - l) / 2);
        if (left(m) + right(m) > t) h = m;
        else l = m + 1;
	}
	return l;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i += 1) {
		cin >> r >> t;
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}
