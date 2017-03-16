#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <sstream>
#include <cassert>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int M = 1000;
	vector<vector<int> > l(M + 1, vector<int>(M + 1, 1000));
	for (int i = 1; i <= M; ++i) {
		int cur = i;
		for (int j = i; j <= M; ++j)
			l[i][j] = 0;
		for (int j = i - 1; j >= 1; --j) {
			for (int k = i - 1; k >= 1; --k)
				l[i][j] = min(l[i][j], 1 + l[k][j] + l[i - k][j]);
		}
	}
	int T;
	cin >> T;
	vector<int> cur_ans(M + 1);
	for (int t = 0; t < T; ++t) {
		int d;
		cin >> d;
		for (int i = 1; i <= M; ++i)
			cur_ans[i] = i;
		for (int i = 0; i < d; ++i) {
			int x;
			cin >> x;
			for (int j = 1; j <= M; ++j) {
				if (x >= j)
					cur_ans[j] += l[x][j];
			}
		}
		int ans = 1000;
		for (int j = 1; j <= M; ++j)
			ans = min(ans, cur_ans[j]);
		cout << "Case #" << t + 1 << ": " << ans << "\n"; 
	}
    return 0;
}