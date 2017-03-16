#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>


using namespace std;

#pragma comment(linker, "/STACK:64000000")

typedef long long ll;

const int MAXK = 0;
const int MAXN = 1 << MAXK;
const int INF = (int)1e9;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";
		cerr << "Case #" << test << ": ";
		
		int n;
		cin >> n;
		vector<vector<int> > a(2 * n - 1, vector<int>(n));
		map<int, int> cnt;
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				cnt[a[i][j]]++;
			}
		}
		vector<int> ans;
		for (auto it : cnt) {
			if (it.second % 2 == 1) {
				ans.push_back(it.first);
			}
		}
		assert(ans.size() == n);
		sort(ans.begin(), ans.end());
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " \n"[i + 1 == n];
			cerr << ans[i] << " \n"[i + 1 == n];
		}
	}

	return 0;
}