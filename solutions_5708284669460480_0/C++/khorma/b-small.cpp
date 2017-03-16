//In the name of God
//...
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double LD;
const int N = 100 + 10;

int k, n, m, cnt;
string al, s;

int main() {
	int test = 0;
	cin >> test;
	for (int tt = 1; tt <= test; tt++) {
		cin >> k >> n >> m;
		cin >> al >> s;
		vector<string> v;
		int mx = 0, num = 0;
		for (cnt = 0; ; cnt++) {
			int tmp = cnt, y = 0;
			string a;
			for (int i = 0; i < m; i++) {
				a.push_back(al[tmp % k]);
				tmp /= k;
			}
			if (tmp)
				break;
			for (int i = 0; i <= m - n; i++)
				if (a.substr(i, n) == s)
					y++;
			mx = max(mx, y), num += y;
		}
		cerr << mx << ' ' << num << '\n';
		cout << setprecision(7) << fixed;
		cout << "Case #" << tt << ": " << (1. * mx)  - 1. * num / cnt << '\n';
	}
	return 0;
}
