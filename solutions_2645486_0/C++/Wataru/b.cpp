#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


long long e, r, n, z;
long long sum;
long a[11000];



void Load()
{
	cin >> e >> r >> n;
	if (r > e) 
		r = e;
	z = e-r;
	sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
}


long long calc(int l, int r, int w)
{
	int mj = l;
	int j;
	int num = 1;
	for (j = l+1; j <= r; j++)
	{
		if (a[j] < a[mj]) {
			mj = j;
			num = 1;
		} else if (a[j] == a[mj]) {
			num++;
		}
	}
	long long ans = z * (a[mj]-w);
//	cerr << l << ".." << r << " min = " << a[mj] << " hop = " << (a[mj]-w) << " gain = " << ans << "\n";
	w = a[mj];
	mj = l;
	for (j = l; j <= r; j++) {
		if (a[j] == w) {
			if (j > mj)
				ans += calc(mj, j-1, w);
			mj = j+1;
		}
	}
	if (r >= mj)
		ans += calc(mj, r, w);
	return ans;
}

int dp[20][20];

int f(int i, int h)
{
	int bst;
	if (dp[i][h] >= 0) return dp[i][h];
	if (i == n-1) return h * a[i];
	bst = 0;
	for (int j = 0; j <= h; j++) {
		int cur = j*a[i] + f(i+1, min(e, h-j + r));
		if (cur > bst)
			bst = cur;
	}
	dp[i][h] = bst;
	return bst;
}

void Solve()
{
	memset(dp, -1, sizeof(dp));
	cout << f(0, e) << "\n";
}

int main()
{
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		Solve(); 
	}
	return 0;
}
