#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct attack {
	int w, e, s;
};

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		int N;
		cin >> N;
		map<int, vector<attack> > a;
		for (int k = 0; k < N; k++) {
			int d, n, w, e, s, d_d, d_p, d_s;
			cin >> d >> n >> w >> e >> s >> d_d >> d_p >> d_s;
			for (int i = 0; i < n; i++) {
				attack t;
				t.e = e + d_p * i;
				t.w = w + d_p * i;
				t.s = s + d_s * i;
				a[d + i * d_d].push_back(t);
			}
		}

		int base = 500;
		vector<int> w(base * 2);

		int ans = 0;
		map<int, vector<attack> >::iterator it;
		for (it = a.begin(); it != a.end(); ++it) {
			bool found = false;
			for (int i = 0; i < it->second.size(); i++) {
				attack &t = it->second[i];
				for (int i = t.w * 2; i <= t.e * 2; i++) {
					if (w[i + base] < t.s) {
						found = true;
						ans++;
						break;
					}
				}
			}
			if (!found) continue;
			for (int i = 0; i < it->second.size(); i++) {
				attack &t = it->second[i];
				for (int i = t.w * 2; i <= t.e * 2; i++)
					w[i + base] = max(w[i + base], t.s);
			}
		}

		printf("Case #%d: %d\n", ti, ans);
	}
	return 0;
}
