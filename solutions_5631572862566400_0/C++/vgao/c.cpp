#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t __; cin >> __;
	for (size_t _ = 0; _ < __; ++_) {
		size_t n; cin >> n;
		vector<size_t> v(n), f, t(n);
		for (size_t i = 0; i < n; ++i) {
			cin >> v[i];
			t[i] = i;
			--v[i];
		}
		size_t m = 0;
		for (size_t x = 0; x < (1 << n); ++x) {
			f.clear();
			for (size_t i = 0; i < n; ++i)
				if (x & (1 << i))
					f.push_back(t[i]);
			auto check = [&]() {
				for (size_t i = 0; i < f.size(); ++i) {
					size_t j = i == 0 ? (f.size() - 1) : (i - 1);
					size_t k = (i == f.size() - 1) ? 0 : i + 1;
					if (!(v[f[i]] == f[j] || v[f[i]] == f[k]))
						return false;
				}
				return true;
			};
			do {
				if (check())
					m = max(m, f.size());
				
			} while (next_permutation(f.begin(), f.end()));
		}
		cout << "Case #" << (_+1) << ": " << m << endl;
	}
	return 0;
}
