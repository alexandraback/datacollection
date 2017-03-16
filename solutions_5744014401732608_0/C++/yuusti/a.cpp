#include <iostream> 
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <functional>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <ctime>
#include <unordered_map>

using namespace std;

void solve() {
	int b;
	cin >> b;

	long long m;
	cin >> m;

	if ((1ll << (b - 2)) < m) {
		printf("IMPOSSIBLE\n");
		return;
	}

	--m;

	printf("POSSIBLE\n");

	vector<vector<int>> ans(b, vector<int>(b));

	ans[0][b - 1] = 1;
	for (int i = 1; i < b - 1; ++i) {
		ans[0][i] = (m>>(b-2-i))&1;
	}

	for (int i = 1; i < b; ++i) {
		for (int j = i + 1; j < b; ++j) {
			ans[i][j] = 1;
		}
	}

	for (int i = 0; i < b; ++i)
		for (int j = 0; j < b; ++j)
			printf("%d%s", ans[i][j], (j == b - 1) ? "\n" : "");
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		solve();
	}


}