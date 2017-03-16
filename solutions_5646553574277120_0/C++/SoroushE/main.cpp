#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 110;

int a[MAXN];
bool mark[MAXN];

int ans;

bool knap[MAXN];
bool check(int c, int v, int n) {
	memset(knap, 0, sizeof knap);
	knap[0] = true;
	for (int i = 0; i < n; i++)
		for (int j = v; j - a[i] >= 0; j--)
			knap[j] |= knap[j - a[i]];
	for (int i = 1; i <= v; i++)
		if (!knap[i])
			return false;
	return true;
}

void bt(int lvl, int c, int v, int n) {
	if (lvl > 5)
		return;
//	cerr << " lvl " << lvl << " n: " << n << endl;
//	for (int i = 0; i < n; i++)
//		cerr << a[i] << " ";
//	cerr << endl;
	if (check(c, v, n)) {
		ans = ans == -1 ? lvl : min(ans, lvl);
//		cerr << " good " << ans << endl;
		return;
	}
	for (int j = (lvl == 0 ? 1 : a[n - 1]); j <= v; j++)
		if (!mark[j]) {
			mark[j] = true;
			a[n] = j;
			bt(lvl + 1, c, v, n + 1);
			mark[j] = false;
		}
}

int main() {
	int tt;
	cin >> tt;
	for (int o = 1; o <= tt; o++) {
		memset(a, 0, sizeof a);
		memset(mark, 0, sizeof mark);
		int c, d, v;
		cin >> c >> d >> v;
		for (int i = 0; i < d; i++)
			cin >> a[i], mark[a[i]] = true;
		ans = -1;
		bt(0, c, v, d);
		cout << "Case #" << o << ": " << ans << endl;
	}
	return 0;
}
