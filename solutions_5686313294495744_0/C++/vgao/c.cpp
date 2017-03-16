#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t __;  cin >> __;
	for (size_t _ = 0; _ < __; ++_) {
		size_t n; cin >> n;
		vector<string> a(n), b(n);
		for (size_t i = 0; i < n; ++i)
			cin >> a[i] >> b[i];

		size_t mx = 0;
		for (size_t x = 0; x < (1 << n); ++x) {
			unordered_set<string> f, g;
			for (size_t i = 0; i < n; ++i)
				if (x & (1 << i)) {
					f.insert(a[i]);
					g.insert(b[i]);
				}
			size_t m = 0;
			for (size_t i = 0; i < n; ++i)
				if (!(x & (1 << i))) {
					if (f.find(a[i]) != f.end() && g.find(b[i]) != g.end())
						++m;
					else
						goto next;
						
				}
			mx = max(mx, m);
		next:
			;
		}

		cout << "Case #" << (_ + 1) << ": " << mx << endl;
	}
	return 0;
}
