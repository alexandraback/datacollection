#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

const int nm = 2016;

int n;
char s[nm];
int dem[nm], kq[nm];

void solve(int test) {
	cout << "Case #" << test << ": ";
	scanf("%s", s);
	n = strlen(s);
	memset(dem, 0, sizeof(dem));
	for (int i = 0; i < n; ++i)
		dem[s[i]]++;
	kq[0] = dem['Z'];
	kq[2] = dem['W'];
	kq[4] = dem['U'];
	kq[6] = dem['X'];
	kq[8] = dem['G'];
	kq[1] = dem['O'] - kq[0] - kq[2] - kq[4];
	kq[3] = dem['H'] - kq[8];
	kq[5] = dem['F'] - kq[4];
	kq[7] = dem['S'] - kq[6];
	kq[9] = dem['I'] - kq[5] - kq[6] - kq[8];
	string res = "";
	for (int i = 0; i <= 9; ++i)
		while (kq[i]--)
			res = res + char(i + 48);
	cout << res << "\n";
}

int main() {
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
	freopen("A-large (2).in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		solve(i);
}
