#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;

	for (int e=1; e<=t; ++e) {
		cout << "Case #" << e << ": ";

        int n; cin >> n;
        string s[11];

        for (int i=0; i<n; ++i)
            cin >> s[i];

        int d[11];
        for (int i=0; i<n; ++i)
            d[i] = i;

        int ans = 0;
        do {
            string total;
            for (int i=0; i<n; ++i)
                total += s[d[i]];

            bool used[123] = {};
            used[static_cast<int>(total[0])] = true;
            bool good = true;
            for (size_t i=1; i<total.size(); ++i) {
                if (used[static_cast<int>(total[i])] && total[i] != total[i-1]) {
                    good = false;
                    break;
                }
                used[static_cast<int>(total[i])] = true;
            }

            ans += good;
        } while (next_permutation(d, d+n));

        cout << ans << endl;
	}

	return 0;
}


