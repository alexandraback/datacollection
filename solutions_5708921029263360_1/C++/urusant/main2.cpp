#include <bits/stdc++.h>
using namespace std;

set <string> precomputed;

void precalc() {
	system("ls solutions/ >computed");
	ifstream in("computed");
	string s;
	while (in >> s) {
		precomputed.insert(s);
	}
}

string to_str(int a) {
	string s = "";
	while (a > 0) {
		s += '0' + a % 10;
		a /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

string to_str(int a, int b, int c, int d) {
	return to_str(a) + '-' + to_str(b) + '-' + to_str(c) + '-' + to_str(d);
}

void solved(int a, int b, int c, int d) {
	string file = "solutions/" + to_str(a, b, c, d);
	ifstream in(file);
	int n;
	in >> n;
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		in >> x >> y >> z;
		cout << x << ' ' << y << ' ' << z << endl;
	}
	return;
}

void solve() {
	int J, P, S, K;
	cin >> J >> P >> S >> K;
	if (precomputed.count(to_str(J, P, S, K))) {
		solved(J, P, S, K);
		return;
	}
	if (S <= K) {
		cout << J * P * S << endl;
		for (int j = 1; j <= J; ++j) {
			for (int p = 1; p <= P; ++p) {
				for (int s = 1; s <= S; ++s) {
					cout << j << ' ' << p << ' ' << s << endl;
				}
			}
		}
		return;
	}
	vector <vector <int> > best_ans;
	for (int test = 0; test < 100000000; ++test) {
		vector <vector <int> > A(J + 1, vector <int> (P + 1, 0));
		vector <vector <int> > B(J + 1, vector <int> (S + 1, 0));
		vector <vector <int> > C(P + 1, vector <int> (S + 1, 0));
		vector <vector <vector <int> > > D(J + 1, vector <vector <int> >(P + 1, vector <int> (S + 1, 0)));
		vector <vector <int> > ans;
		bool f = 1;
		for (int j = 1; j <= J && f; ++j) {
			for (int p = 1; p <= P && f; ++p) {
				for (int i = 0; i < K && f; ++i) {
					vector <int> possible;
					for (int s = 1; s <= S; ++s) {
						if (A[j][p] >= K || B[j][s] >= K || C[p][s] >= K || D[j][p][s] >= 1) {
							continue;
						}
						possible.push_back(s);
					}
					if (possible.size() > 0) {
						int s = possible[rand() % possible.size()];
						ans.push_back(vector <int> {j, p, s});
						A[j][p]++;
						B[j][s]++;
						C[p][s]++;
						D[j][p][s]++;
					} else {
						//f = 0;
					}
				}
			}
		}
		if (ans.size() > best_ans.size()) {
			best_ans = ans;
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); ++i) {
			for (auto e: ans[i]) {
				cout << e << ' ';
			}
			cout << endl;
		}
		return;
	}

	cout << best_ans.size() << endl;
	for (int i = 0; i < best_ans.size(); ++i) {
		for (auto e: best_ans[i]) {
			cout << e << ' ';
		}
		cout << endl;
	}
	return;
}

int main() {
	precalc();
	srand(time(NULL));
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
}