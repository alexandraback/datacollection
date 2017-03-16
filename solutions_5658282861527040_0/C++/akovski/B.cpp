#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second

LL A, B, K, a[100][2][2], b[100][2][2];
int aa[100], bb[100], k[100];
LL res[100][2][2];
void solve(){
	A --; B --; K --;
	LL ans = 0;
	memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
	memset(res, 0, sizeof(res));
	for (int i = 0; i < 30; i ++) aa[i] = 1 & (A >> i), bb[i] = 1 & (B >> i), k[i] = 1 & (K >> i);
	res[31][1][1] = 1;
	for (int i = 30; i >= 0; i --) {
		for (int x = 0; x < 2; x ++) 
			for (int y = 0; y < 2; y ++) {
				for (int kk = 0; kk < 2; kk ++) 
					for (int l = 0; l < 2; l  ++) {
						if (res[i + 1][kk][l] == 0) continue;
						if ((x & y) == 1) continue;
						if (kk && x > aa[i]) continue;
						if (l && y > bb[i]) continue;
						res[i][kk && x == aa[i]][l && y == bb[i]] += res[i + 1][kk][l];
					}
			}
		if (k[i]) {
			for (int l = 0; l < 2; l ++) 
				for (int r = 0; r < 2; r ++) {
					LL ll, rr;
					if (l) ll = 1 + (A & ((1LL << i) - 1)); else ll = 1LL << i;
					if (r) rr = 1 + (B & ((1LL << i) - 1)); else rr = 1LL << i;
					ans += ll * rr * res[i][l][r];
					res[i][l][r] = 0;
				}
			for (int l = 0; l < 2; l ++) 
				for (int r  = 0; r < 2; r ++) {
					if (l && !aa[i]) continue;
					if (r && !bb[i]) continue;
					res[i][l && aa[i]][r && bb[i]] += res[i + 1][l][r];
				}
		}
	}
	for (int l = 0; l < 2; l ++) for (int r = 0; r < 2; r ++) 
		ans += res[0][l][r];
	cout << ans << endl;
}
int main() {
	#ifdef _TEST_
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	for (int i = 0; i < t; i ++) {
		cin >> A >> B >> K;
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return 0;
}
