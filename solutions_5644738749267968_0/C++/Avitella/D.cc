#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int _t;
	cin >> _t;
	for (int t = 1; t <= _t; ++t) {
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		vector<double> a(n), b(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int ans_cheat = 0, ans_war = 0;
		reverse(b.begin(), b.end());
		for (int i = 0; i < n; ++i) {
			int buf = 0;
			reverse(a.end() - i - 1, a.end());
			for (int i = 0; i < n; ++i)
				buf += a[i] > b[i];
			ans_cheat = max(ans_cheat, buf);
			reverse(a.end() - i - 1, a.end());
		}
		cout << ans_cheat << " ";
		reverse(a.begin(), a.end());
//		cerr << t << ": " << endl;
		for (int i = 0; i < n; ++i) {
			int p = n;
			for (int j = 0; j < (int) b.size(); ++j) {
				if ((p == n && b[j] > a[i]) || (b[j] > a[i] && b[p] > b[j]))
					p = j;
			}
			if (p != n) {
//				cerr << "::: " << a[i] << ' ' << b[p] << " - " << p << endl;
				swap(b.back(), b[p]);
				b.pop_back();
			} else {
				ans_war++;
				for (int j = 0; j < (int) b.size(); ++j) {
					if (p == n || b[j] < b[p])
						p = j;
				}
				swap(b.back(), b[p]);
				b.pop_back();
			}
		}
		cout << ans_war << endl;
	}
	return 0;
}
