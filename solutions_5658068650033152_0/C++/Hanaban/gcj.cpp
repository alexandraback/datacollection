#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <ctime>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#include <iostream>
using namespace std;

const int MAXN = 101;
const long long MOD = 1000000007ll;
int G[20][20];

int N, M, K;

int count_enclose()
{
	int ret = 0;
	
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (G[y][x] == 0) continue;
			bool enclose = false;
			if (y == 0 || G[y - 1][x] == 0) enclose = true;
			if (y == N - 1 || G[y + 1][x] == 0) enclose = true;
			if (x == 0 || G[y][x - 1] == 0) enclose = true;
			if (x == M - 1 || G[y][x + 1] == 0) enclose = true;
			if (enclose) ret++;
		}
	}
	
	return ret;
}

int solve()
{
	memset(G, 0, sizeof(G) );
	int midx = M / 2;
	int midy = N / 2;
	
	int nstone = 0;
	vector<vector<pair<int, int> > > dpoint(M + N);
	
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			int d = abs(y - midy) + abs(x - midx);
			dpoint[d].push_back(make_pair(y, x) );
		}
	}
	
	int mark = 0;
	int maxdist = 0;
	for (int i = 0; i < M + N && mark < K; ++i) {
		for (int j = 0; j < dpoint[i].size() && mark < K; ++j) {
			G[dpoint[i][j].first][dpoint[i][j].second] = 1;
			++mark;
		}
		maxdist = i;
	}
	
	bool changed = true;
	vector<pair<int, int> > dp = dpoint[maxdist];
	
	while (changed) {
		changed = false;
		for (int i = 0; i < dp.size(); ++i) {
			if (G[dp[i].first][dp[i].second] == 0) continue;
			int prev = count_enclose();
			for (int j = 0; j < dp.size(); ++j) {
				if (G[dp[j].first][dp[j].second] == 1) continue;
				G[dp[i].first][dp[i].second] = 0;
				G[dp[j].first][dp[j].second] = 1;
				int next = count_enclose();
				if (prev > next) {
					changed = true;
					break;
				}
				G[dp[i].first][dp[i].second] = 1;
				G[dp[j].first][dp[j].second] = 0;
			}
		}
	}
	int ret = count_enclose();
	
	return ret;
}

int main()
{
	int T;
	
	cin >> T;
	
	for (int t = 1; t <= T; ++t) {
		cin >> N >> M >> K;
		
		int ans = 0;
		ans = solve();
		printf("Case #%d: %d\n", t, (int) ans);
		
		
	}
	
    return 0;
}
