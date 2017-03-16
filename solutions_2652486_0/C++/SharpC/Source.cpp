#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void dfs(string& result, vector<int>& d, int n, int m, int k, const vector<int>& p, int idx, int from) {
	if (idx == n) {
		bool ok = true;
		//cout << "checking ";
		//for (int i = 0; i < n; ++i) cout << d[i] << " ";
		//cout << endl;
		for (int i = 0; i < k; ++i) {
			int pp = p[i];
			//cout << pp << " was" << endl;
			for (int j = n - 1; j >= 0; --j) {
				if (pp % d[j] == 0) pp /= d[j];
			}
			//cout << pp << " become" << endl;
			if (pp != 1) {
				ok = false;
				break;
			}
		}
		//cout << boolalpha << ok << endl;
		if (ok) {
			stringstream ss;
			for (int j = 0; j < n; ++j) {
				ss << d[j];
			}
			result = ss.str();
		}
		return;
	}
	for (int t = from; t <= m; ++t) {
		d[idx] = t;
		dfs(result, d, n, m, k, p, idx + 1, t);
	}
}

string solve(int n, int m, int k, const vector<int>& p)
{
	string result = string(n, '2');
	vector<int> d(n);
	dfs(result, d, n, m, k, p, 0, 2);
	return result;
}

int main()
{
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test) {
		int r, n, m, k;
		cin >> r >> n >> m >> k;
		vector<int> p(k);
		cout << "Case #1:" << endl;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < k; ++j) {
				cin >> p[j];
			}
			cout << solve(n, m, k, p) << endl;
		}
	}
}
