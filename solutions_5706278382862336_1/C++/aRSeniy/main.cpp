#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

long long gcd (long long x, long long y) {
	return y ? gcd(y, x % y) : x;
}

bool is2d(long long x) {
    return !(x & (x - 1));
}

int get2d(long long x) {
    int res = -1;
    while (x) {
        x >>= 1LL;
        ++res;
    }
    return res;
}

void precalc () {

}

void solve () {
    long long p, q;
    scanf("%I64d/%I64d", &p, &q);

    long long ans = q;
    while (p) {
        long long g = gcd(p, q);
        p /= g;
        q /= g;

        if (!is2d(q)) {
            cout << "impossible" << endl;
            return;
        }

        p -= 1;
        ans = q;
    }
    cout << get2d(ans) << endl;
}

int main() {
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);

  precalc();

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
    
    solve();
	}
	return 0;
}
