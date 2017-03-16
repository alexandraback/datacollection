#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const double EPS = 1e-9;
const ll INF = 1e17;

inline void del(multiset<char> & t, const string & s) {
	for (auto u : s) {
		t.erase(t.find(u));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);

	int n;
	cin >> n;

	for (int num = 1; num <= n; num++) {
		string s;
		cin >> s;

		multiset<char> letts;
		vector<int> ans;

		for (int i = 0; i < (int)s.size(); i++) {
			letts.insert(s[i]);
		}

		while (letts.find('Z') != letts.end()) {
			del(letts, "ZERO");
			ans.push_back(0);
		}

		while (letts.find('W') != letts.end()) {
			del(letts, "TWO");
			ans.push_back(2);
		}

		while (letts.find('U') != letts.end()) {
			del(letts, "FOUR");
			ans.push_back(4);
		}

		while (letts.find('O') != letts.end()) {
			del(letts, "ONE");
			ans.push_back(1);
		}

		while (letts.find('F') != letts.end()) {
			del(letts, "FIVE");
			ans.push_back(5);
		}

		while (letts.find('R') != letts.end()) {
			del(letts, "THREE");
			ans.push_back(3);
		}

		while (letts.find('X') != letts.end()) {
			del(letts, "SIX");
			ans.push_back(6);
		}

		while (letts.find('S') != letts.end()) {
			del(letts, "SEVEN");
			ans.push_back(7);
		}

		while (letts.find('G') != letts.end()) {
			del(letts, "EIGHT");
			ans.push_back(8);
		}

		while (!letts.empty()) {
			del(letts, "NINE");
			ans.push_back(9);
		}

		sort(all(ans));

		cout << "Case #" << num << ": ";
		for (auto u : ans) {
			cout << u;
		}
		cout << "\n";
	}

	return 0;
}
