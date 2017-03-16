#include <cstdlib>
#include <map>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> v[2];

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		v[0].clear(); v[1].clear();
		map<string, int> m1, m2;
		for (int i = 0; i < n; ++i) {
			string s1, s2;
			cin >> s1 >> s2;
			if (m1.find(s1) != m1.end()) {
				m1[s1]++;
			} else {
				m1[s1] = 1;
			}
			if (m2.find(s2) != m2.end()) {
				m2[s2]++;
			} else {
				m2[s2] = 1;
			}
			v[0].push_back(s1);
			v[1].push_back(s2);
		}
		int ok = 0;
		for (int i = 0; i < n; ++i) {
			if (m1[v[0][i]] == 1 || m2[v[1][i]] == 1) ++ok;
			else {
				m1[v[0][i]]--;
				m2[v[1][i]]--;
			}
		}
		cout << "Case #" << t << ": " << n-ok << "\n";
	}
	return 0;
}