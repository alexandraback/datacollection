#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef pair<string, string> ss;

map<string, int> m1, m2;

bool compare1(ss um, ss dois) {
	int val1 = m1[um.first] + m2[um.second];
	int val2 = m1[dois.first] + m2[dois.second];
	return val1 < val2;
}
bool compare2(ss um, ss dois) {
	int val1 = m1[um.first] + m2[um.second];
	int val2 = m1[dois.first] + m2[dois.second];
	return val1 > val2;
}

int main() {
	int T;
	cin >> T;

	for (int ct = 1; ct <= T; ct++) {
		int n;
		cin >> n;

		m1.clear();
		m2.clear();
		vector<ss> v(n);
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			m1[a]++;
			m2[b]++;
			v[i] = ss(a, b);
		}
		vector<ss> v1(v);
		vector<ss> v2(v);

		// sort(v1.begin(), v1.end(), compare1);
		// sort(v2.begin(), v2.end(), compare2);
		sort(v1.begin(), v1.end(), compare1);
		sort(v2.begin(), v2.end(), compare2);

		int ans1, ans2, ans3;
		ans1 = ans2 = ans3 =  0;
		map<string, int> m3(m1), m4(m2);
		map<string, int> m5(m1), m6(m2);

		vector<ss>::iterator it = v.begin();

		// cout << endl;
		while (it != v.end()) {
			// cout << it->first << " " << it->second << " ";
			if (m1[it->first] > 1 && m2[it->second] > 1) {
				// cout << "***";
				ans1++;
				m1[it->first]--;
				m2[it->second]--;
			}
			// cout << endl;
			it++;
		}

		it = v2.begin();
		while (it != v2.end()) {
			// cout << it->first << " " << it->second << " ";
			if (m3[it->first] > 1 && m4[it->second] > 1) {
				// cout << "***";
				ans2++;
				m3[it->first]--;
				m4[it->second]--;
			}
			// cout << endl;
			it++;
		}

		it = v1.begin();
		while (it != v1.end()) {
			// cout << it->first << " " << it->second << " ";
			if (m5[it->first] > 1 && m6[it->second] > 1) {
				// cout << "***";
				ans3++;
				m5[it->first]--;
				m6[it->second]--;
			}
			// cout << endl;
			it++;
		}

		int ans = (ans1 < ans2) ? ans2 : ans1;
		if (ans3 > ans) ans = ans3;
		cout << "Case #" << ct << ": " << ans << endl;
	}

	return 0;
}