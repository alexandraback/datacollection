#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
	int t; cin >> t;

	for (int e=1; e<=t; ++e) {
		cout << "Case #" << e << ": ";

        string s; cin >> s;
        replace(s.begin(), s.end(), '/', ' ');
        istringstream ssin(s);
        long long p,q; ssin >> p >> q;

        long long g = gcd(p, q);
        p /= g;
        q /= g;

        if (0 != (q & (q - 1))) {
            cout << "impossible" << endl;
            continue;
        }

        int ans = 0;
        while (p != q) {
            ++ans;
            long long mn = min(q - p, p);
            p += mn;

            //cerr << "p, q = " << p << ' ' << q << ", mn = " << mn << endl;

            long long g = gcd(p, q);
            p /= g;
            q /= g;
        }

        cout << ans << endl;
	}

	return 0;
}


