//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 100010
#define MOD 1000000007

int n, a[N], pos[N], b[N];
bool mat[20][20];
bool mark[N];

int dfs(int k) {
	int ans = k;
	if (k) {
		Rep(i, k) {
			int x = b[i];
			int y1 = b[(i + 1) % k],
				y2 = b[(i + k - 1) % k];
			if (y1 != a[x] && y2 != a[x]) { 
				ans = 0; 
				if (i == 0 || i == k - 1) break; 
				else return 0;
			}
		}
	}
	if (k == n) return ans;
	Rep(i, n) {
		if (mark[i]) continue;
		mark[i] = true;
		b[k] = i;
		ans = max(ans, dfs(k + 1));
		mark[i] = false;
	}
	return ans;
}
int main() {
	int cas, tt = 0;
	cin >> cas;
	while (cas --) {
		cin >> n;
		memset(mat, 0, sizeof mat);
		Rep(i, n) {
			cin >> a[i];
			a[i] --;
		}
		printf("Case #%d: %d\n", ++tt, dfs(0));
	}
	return 0;
}
