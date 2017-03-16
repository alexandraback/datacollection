#include <bits/stdc++.h>
using namespace std;

void solve() {
	int J, P, S, K;
	cin >> J >> P >> S >> K;
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
	while (1) {
		vector <vector <int> > A(J + 1, vector <int> (P + 1, 0));
		vector <vector <int> > B(J + 1, vector <int> (S + 1, 0));
		vector <vector <int> > C(P + 1, vector <int> (S + 1, 0));
		vector <vector <vector <int> > > D(J + 1, vector <vector <int> >(P + 1, vector <int> (S + 1, 0)));
		vector <vector <int> > ans;
		for (int j = 1; j <= J; ++j) {
			for (int p = 1; p <= P; ++p) {
				for (int i = 0; i < K; ++i) {
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
					}
				}
			}
		}
		if (ans.size() < J * P * K) {
			continue;
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
}

int main() {
	srand(time(NULL));
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
}