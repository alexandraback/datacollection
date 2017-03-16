#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

struct outfit {
	int j, p, s;
	outfit(int j, int p, int s) : j(j), p(p), s(s) {}
	outfit() {}
};

class PV {
	int first, second;
	vector <int> data;
public:
	int &operator()(int i, int j) {
		return data[i * second + j];
	}
	PV() {}
	PV(int first, int second) : first(first), second(second), data(first * second) {}
	void clear() {
		fill(data.begin(), data.end(), 0);
	}
};
int main() {
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T; cin >> T;
	for (int t = 0; t < T; ++t) {
		cerr << t << endl;
		cout << "Case #" << (t + 1) << ": ";
		/**/
		int J, P, S;
		cin >> J >> P >> S;
		int K;
		cin >> K;
		vector <outfit> O;
		for (int j = 0; j < J; ++j) {
			for (int p = 0; p < P; ++p) {
				for (int s = 0; s < S; ++s) {
					O.push_back(outfit(j, p, s));
				}
			}
		}
		int mx = -1;
		ll mxmsk;
		PV JP(J, P), PS(P, S), SJ(S, J);
		for (ll mask = 0; mask < (1LL << O.size()); ++mask) {
			JP.clear();
			PS.clear();
			SJ.clear();
			int notnull = 0;
			for (ll bit = 0; bit < O.size(); ++bit) {
				if (mask & (1LL << bit)) {
					notnull++;
					outfit o = O[bit];
					JP(o.j, o.p)++;
					PS(o.p, o.s)++;
					SJ(o.s, o.j)++;
					if (JP(o.j, o.p) > K) {
						notnull = -1;
						break;
					}
					if (PS(o.p, o.s) > K) {
						notnull = -1;
						break;
					}
					if (SJ(o.s, o.j) > K) {
						notnull = -1;
						break;
					}
				}
			}
			if (notnull != -1 && notnull > mx) {
				mx = notnull;
				mxmsk = mask;
			}
		}
		cout << mx << endl;
		for (ll bit = 0; bit < O.size(); ++bit) {
			if (mxmsk & (1LL << bit)) {
				cout << O[bit].j + 1 << ' ' << O[bit].p + 1 << ' ' << O[bit].s + 1 << endl;
			}
		}
		/**/
	}
}