#include <iostream>
#include <vector>
using namespace std;

const int nmax = 500, nmod = 5;
const int mod[nmod] = {
/* 9999047,
 9999049,
 9999053,
 9999071,
 9999083,*/
 99047,
 99049,
 99053,
 99071,
 99083,
};
typedef vector<short> vi;
typedef long long ll;
ll s[nmax];
typedef vector<ll> vll;

void walk(vector<vi> &vm, int t, vll &o) {
	do {
		int is = vm[t].back();

		o.push_back(s[is]);
		t = (t - s[is] + vm.size()) % vm.size();
	} while (t);
}

int main() {
	int nt, it;

	cin >> nt;
	for (it = 1; it <= nt; it++) {
		int n, i, j, k, r = 0;
		vector<vi> v[nmod];
		bool found = false;

		for (i = 0; i < nmod; i++) {
			v[i].resize(mod[i]);
			v[i][0].push_back(-1);
		}
		
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> s[i];
			if (found) continue;
			
			bool rep[nmod] = {};
			int nrep = 0;
			
			for (j = 0; j < nmod; j++) {
				for (k = 0; k < mod[j]; k++) if (v[j][k].size() && (v[j][k].back() != i || v[j][k].size() > 1)) {
					int t = (k + s[i]) % mod[j];

					if (v[j][t].size()) nrep += !rep[j]++, r = t;
					v[j][t].push_back(i);
				}
			}

			if (nrep == nmod) found = true;
		}

		cout << "Case #" << it << ":\n";
		if (found) {
			vll o[2];
			
			walk(v[nmod - 1], r, o[0]);
			v[nmod - 1][r].pop_back();
			walk(v[nmod - 1], r, o[1]);
			for (j = 0; j < 2; j++) {
				for (k = 0; k < o[j].size(); k++) {
					cout << o[j][k] << ' ';
				}
				cout << '\n';
			}
		} else {
			cout << "Impossible\n";
		}
	}

	return 0;
}
