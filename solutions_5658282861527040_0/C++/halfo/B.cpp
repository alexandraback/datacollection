/* in the name of ALLAH, most gracious, most merciful */

#include <bits/stdc++.h>
using namespace std;

int main () {
#ifdef Local
	freopen ("B-small.in", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;

	for (int cs = 1; cs <= t; ++cs) {
		int a, b, k;
		cin >> a >> b >> k;

		int ans = 0;
		for (int i = 0; i < a; ++i)
			for (int j = 0; j < b; ++j)
				if ((i & j) < k) ++ans;

		cout << "Case #" << cs << ": " << ans << endl;
	}

	return 0;
}

