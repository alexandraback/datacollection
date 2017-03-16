#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

int dfs(const vector<vector<int>> v, const vector<int>& was, int cur, int iter, int prev) {
	int res = 1;
	for (int next : v[cur]) {
		if (was[next] != iter && cur != prev) {
			res = max(res, dfs(v, was, next, iter, cur)+1);
		}
	}
	return res;
}

int main()
{
	ifstream ifs("c.in");
	ofstream ofs("c.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int res = 0;
		int n;
		ifs >> n;
		vector<int> f(n);
		vector<vector<int>> b(n, {});
		for (int i = 0; i < n; ++i) {
			ifs >> f[i];
			f[i]--;
			b[f[i]].push_back(i);
		}

/*
		vector<int> a;
		for (int i = 0; i < n; ++i) {
			a.push_back(i);
		}

		do {
			for (int i = 1; i < a.size(); ++i) {
				int fr = f[a[i]];
				if (fr == a[0] || fr == a[i-1] && f[a[0]] == a[1]) {
					res = max(res, i+1);
				}
				if (a[i-1] != fr && (i+1 == a.size() || a[i+1] != fr)) {
					break;
				}
			}
		} while (next_permutation(a.begin(), a.end()));
*/

		map<pair<int,int>, int> m;
		vector<int> was(n, 0);
		int iter = 0;
		for (int i = 0; i < n; ++i) {
			++iter;
			vector<int> way;
			way.push_back(i);
			was[i] = iter;
			int j = i;
			while (true) {
				j = f[j];
				if (was[j] == iter) {
					int len;
					if (j == way[way.size()-2]) {
						len = way.size() + (dfs(b, was, way.back(), iter, -1) - 1);
						m[{min(j, way.back()), max(j, way.back())}] = max(m[{min(j, way.back()), max(j, way.back())}], len);
					} else  {
						len = way.size() - (find(way.begin(), way.end(), j) - way.begin());
					}
					res = max(res, len);
					break;
				}
				way.push_back(j);
				was[j] = iter;
			} 
		}

		
		vector<int> chains;
		for (auto mi : m) chains.push_back(mi.second);
		res = max(res, accumulate(chains.begin(), chains.end(), 0));
		cout << test + 1 << endl;
		ofs << "Case #" << test+1 << ": " << res << endl;
	}
	return 0;
}
