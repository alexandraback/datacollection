#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>

using namespace std;

int a[1000];
vector<int> r[1000];
int n;
int mem[10][(1<<10)];
int f;
int prv;
int m;
bool stop;
bitset<1000> bs;

int cc(int m) {
	int a = 0;
	for (int i = 0; i < n; i++) {
		if (bs[i]) a++;
	}
	return a;
}

int dp(int l) {
	//cout << l+1 << " " << f+1 << " " << a[l]+1 << " " << (m & (1 << a[l])) << endl;
	if ((a[l] == f) || (a[l] == prv)) {
		if (a[l] == f) stop = true;
		if (a[l] == prv) prv = l;
		//cout << "dor " << cc(m) << " " << prv+1 << endl;
		return cc(m);
	}
	if (cc(m) == n) return 0;
	prv = l;
	int ans = 1;
	if (!bs[a[l]]) {
		bs[a[l]] = 1;
		ans = dp(a[l]);
	} else {
		return 0;
	}
	mem[l][m] = ans;
	return ans;
}

int cc2(int l) {
	int ans = 1;
	for (int i = 0; i < r[l].size(); i++) {
		if (!bs[r[l][i]]) {
			bs[r[l][i]] = 1;
			ans = max(ans, 1+cc2(r[l][i]));
			bs[r[l][i]] = 0;
		}
	}
	return ans;
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int t = 1; t <= tt; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			r[i].clear();
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			a[i]--;
			r[a[i]].push_back(i);
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
			bs.reset();
			f = i;
			bs[i] = 1;
			bs[a[i]] = 1;
			prv = i;
			stop = false;
			int tmp = dp(a[i]);
			int ans2 = 0;
			if (!stop) {
				for (int j = 0; j < r[prv].size(); j++) {
					if (!bs[r[prv][j]]) {
						bs[r[prv][j]] = 1;
						ans2 = max(ans2, cc2(r[prv][j]));
						bs[r[prv][j]] = 0;
					}
				}
				for (int j = 0; j < r[f].size(); j++) {
					if (!bs[r[f][j]]) {
						bs[r[f][j]] = 1;
						ans2 = max(ans2, cc2(r[f][j]));
						bs[r[f][j]] = 0;
					}
				}
			}
			//cout << ans2 << endl;
			ans = max(ans, tmp+ans2);
		}
		printf("Case #%d: %d\n", t, ans);
	}
}