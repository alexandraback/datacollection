#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <map>
#include <ctime>
#include <iomanip>

using namespace std;

#define PATH "C:\\Users\\ValenKof\\Desktop\\"

#define forn(i, n) for(int i = 0; i < n; ++i)
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl

#define print(x) cout << x; // cerr << x; //cout << x;

#define all(x) begin(x), end(x)


char ans[50][51];

int R, C, M;

int ways;


bool openned[50][50];

int di[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dj[] = {-1, 0,   1, -1, 1, -1, 0, 1};

inline bool inside(int i, int j) {
	return 0 <= i && i < R
      && 0 <= j && j < C;	
}

int dfs(int i, int j) {
	if (openned[i][j] || ans[i][j] == '*') {
		return 0; 
	}
	
	openned[i][j] = true;
	int res = 1;
	int cnt = 0;

	for (int k = 0; k < 8; ++k) {
		int ii = i + di[k];
		int jj = j + dj[k];
		if (inside(ii, jj) && ans[ii][jj] == '*') {
			cnt++;
		}
	}
	
	if (cnt != 0) {
		return res;
	}
	
	for (int k = 0; k < 8; ++k) {
		int ii = i + di[k];
		int jj = j + dj[k];
		if (inside(ii, jj) && !openned[ii][jj]) {
			res += dfs(ii, jj);
		}
	}
	return res;
}

bool f(int d, int can_max, int need_place) {
	if (d != 0 && can_max == 1 && C != 1 && need_place > 0) {
		return false;
	}
	
	// cout << "d=" << d << " max=" << can_max << " need=" << need_place << endl;
	
	if (d == R) {		
		forn (i, R) fill(openned[i], openned[i] + C, false);
		int cnt = dfs(0, 0);
		// debug(cnt);
		return cnt == R * C - M;
	}
	
	int k = min(can_max, need_place);
	fill(ans[d], ans[d] + k, '.');
	fill(ans[d] + k, ans[d] + C, '*');
	for (int i = k; i >= 0; --i) {
		if (i < C) ans[d][i] = '*';
		if ((R - d) * i < need_place) break;
		// if (d == 1 && i != 0 && i < can_max) continue;
		if (f(d + 1, i, need_place - i)) {
			return true;
		}
	}
	return false;
}

int main() {
	freopen(PATH"C-large.in", "r", stdin);
	freopen(PATH"out.txt", "w", stdout);
	int nTests;
	cin >> nTests;
	for (int iTest = 0; iTest < nTests; ++iTest) {
		print("Case #" << iTest + 1 << ":" << endl);
	
		cin >> R >> C >> M;
		int F = R * C - M;
		
		ways = 0;
		if (!f(0, C, F)) {
			cout << "Impossible" << endl;
			continue;
		}
		ans[0][0] = 'c';
		forn (i, R) {
			ans[i][C] = '\0';
			cout << ans[i] << endl;
		}
	}
	return 0;
}