#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int n, m;
string z[50];
vi g[50];

bool possible(vi x, vi s) {
	// bool e[50] = {};
	bool v[50] = {};
	vi q = s;
	int i;

	// cout << "possible(\n";
	for (i = 0; i < x.size(); i++) {
		// cout << x[i] << ' ';
		v[x[i]] = true;
	}
	// cout << endl;
	// for (i = 0; i < q.size(); i++) cout << q[i] << ' ';
	// cout << endl;

	for (i = 0; i < q.size(); i++) {
		for (int t: g[q[i]]) if (!v[t]++) {
			q.push_back(t);
		}
	}

	bool r = true;

	for (i = 0; i < n; i++) if (!v[i]) r = false;
	// cout << ") = " << r << endl;
	return r;
}

int main() {
	int nt, it;

	cin >> nt;
	for (it = 1; it <= nt; it++) {
		fill(g, g + 50, vi());

		int i;

		cin >> n >> m;
		for (i = 0; i < n; i++) {
			cin >> z[i];
		}
		for (i = 0; i < m; i++) {
			int a, b;

			cin >> a >> b;
			a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		string r, r1 = "999999";
		int i0;

		for (i = 0; i < n; i++) {
			vi t{i};
			if (possible(t, t) && z[i] <= r1) r1 = z[i], i0 = i;
		}
		// cout << "Starting: " << r1 << ' ' << i0 << '\n';
		r = r1;

		vi x{i0};
		vi s{i0};

		for (i = 1; i < n; i++) {
			vi x1 = x, s1 = s, xr, sr;
			r1 = "999999";
			while (s1.size()) {
				for (int t: g[s1.back()]) if (find(x1.begin(), x1.end(), t) == x1.end()) {
					s1.push_back(t);
					x1.push_back(t);
					if (possible(x1, s1) && z[t] <= r1) r1 = z[t], xr = x1, sr = s1;
					x1.pop_back();
					s1.pop_back();
				}
				x1.push_back(s1.back());
				s1.pop_back();
			}
			r += r1;
			x = xr;
			s = sr;
			// cout << "New: " << r1 << ' ' << s[s.size() - 2] << " -> " << s[s.size() - 1] << endl;
		}

		cout << "Case #" << it << ": " << r << endl;
	}
}
