#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> dp;

multiset<int> calc_keys(int n, multiset<int> startkeys, int state, const vector<int>& open, const vector<vector<int>>& inside)
{
	multiset<int> result = startkeys;
	for (int i = 0; i < n; ++i) if (state & 1 << i) {
		for (int j = 0, jlen = inside[i].size(); j < jlen; ++j) {
			result.insert(inside[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) if (state & 1 << i) {
		result.erase(result.find(open[i]));
	}
	return result;
}

bool dfs(int n, multiset<int> startkeys, int state, const vector<int>& open, const vector<vector<int>>& inside, int from = -1)
{
	static int calls = 0;
	++calls;
	if (calls % 100000 == 0) {
		cerr << calls << endl;
	}

	if (dp[state] != -1) return false;
	dp[state] = from;
	if (state == (1 << n) - 1) {
		return true;
	}
	auto keys = calc_keys(n, startkeys, state, open, inside);
	for (int i = 0; i < n; ++i) if (!(state & 1 << i) && keys.find(open[i]) != keys.end() && dp[state | 1 << i] == -1) {
		if (dfs(n, startkeys, state | 1 << i, open, inside, i)) {
			return true;
		}
	}
	return false;
}

string solve(int n, multiset<int> keys, const vector<int>& open, const vector<vector<int>>& inside)
{
	dp.assign(1 << n, -1);
	dfs(n, keys, 0, open, inside);
	if (dp[(1 << n) - 1] != -1) {
		stringstream ss;
		vector<int> path;
		for (int c = (1 << n) - 1; dp[c] != -1; c = c ^ (1 << dp[c])) {
			path.push_back(dp[c]);
		}
		reverse(path.begin(), path.end());
		for (int i = 0; i < n; ++i) {
			if (i) ss << " ";
			ss << path[i] + 1;
		}
		return ss.str();
	} else return "IMPOSSIBLE";
}

int main()
{
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test) {
		int k, n;
		cin >> k >> n;
		vector<int> keys(k), open(n);
		vector<vector<int>> inside(n);
		for (int i = 0; i < k; ++i) cin >> keys[i];
		for (int i = 0; i < n; ++i) {
			cin >> open[i];
			int ninside;
			cin >> ninside;
			inside[i].assign(ninside, 0);
			for (int j = 0; j < ninside; ++j) {
				cin >> inside[i][j];
			}
		}
		cerr << "Case #" << test + 1 << endl;
		cout << "Case #" << test + 1 << ": " << solve(n, multiset<int>(keys.begin(), keys.end()), open, inside) << endl;
	}
}
