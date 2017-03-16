#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 103;
const int inf = 0x3f3f3f3f;

int n;
std::vector<string> v;
//int cnt[maxn], clen;
//char a[maxn];

int cnt[maxn][maxn];
int len[maxn];
int g[maxn][maxn];

int solve () {
	for (int i = 0; i < n; i ++) {
		len[i] = 0;
		cnt[i][len[i]] = 1;
		g[i][len[i]] = v[i][0];
		for (int j = 1; j < v[i].size(); j ++) {
			if (v[i][j] != v[i][j - 1]) {
				cnt[i][++ len[i]] = 1;
				g[i][len[i]] = v[i][j];
			} else {
				cnt[i][len[i]] ++;
			}
		}
	}
	for (int i = 1; i < n; i ++) {
		if (len[i] != len[i - 1]) {
			return -1;
		}
	}
	int leng = len[0];
	for (int i = 0; i <= leng; i ++) {
		for (int j = 1; j < n; j ++) {
			if (g[j][i] != g[j - 1][i]) {
				return -1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= leng; i ++) {
		int minN = inf;
		for (int j = 1; j <= 100; j ++) {
			int sum = 0;
			for (int k = 0; k < n; k ++) {
				sum += abs(cnt[k][i] - j);
			}
			minN = min(minN, sum);
		}
		ans += minN;
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int cas;
	scanf ("%d", &cas);
	for (int t = 1; t <= cas; t ++) {
		scanf ("%d", &n);
		v.clear();
		string buf;
		for (int i = 0; i < n; i ++) {
			cin >> buf;
			v.push_back(buf);
		}
		int ans = solve();
		if (ans == -1) {
			printf("Case #%d: Fegla Won\n", t);
		} else {
			printf("Case #%d: %d\n", t, ans);
		}
	}

	return 0;
}