#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

double dp[2005][2005];

double fall(const int n, const int tar, const int maxx) {
	//cout << n << ' ' << tar << ' ' << maxx << endl;
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int left = 0; left <= maxx && left <= i; ++left) {
      int right = i - left;
      if (left == maxx) {
        dp[i + 1][left] += dp[i][left];
			} else if (right == maxx) {
				dp[i + 1][left + 1] += dp[i][left];
      } else {
      	dp[i + 1][left] += dp[i][left] / 2;
      	dp[i + 1][left + 1] += dp[i][left] / 2;
      }
		}
	}
	double ret = 0;
	for (int i = tar; i <= maxx; ++i) {
		ret += dp[n][i];
	}
	return ret;
}

int main() {
	int T, m, x, y;
	scanf("%d", &T);
	for (int V = 1; V <= T; ++V) {
	  scanf("%d %d %d", &m, &x, &y);
	  if (x < 0) x = -x;
	  int n = 0;
	  while ((2 * n - 1) * n <= m) ++n;
	  --n;
	  //cout << n << ' ' << m << ' ' << x << ' ' << y << ' ' << m - (2 * n - 1) * n << endl;
	  double ans;
	  if (x == 0) {
	    if (2 * (n - 1) >= y) ans = 1; else ans = 0;
		} else {
			if (2 * (n - 1) >= x + y) {
				ans = 1;
			} else if (2 * n < x + y) {
			  ans = 0;
			} else {
			  ans = fall(m - (2 * n - 1) * n, y + 1, n * 2);
			}
	  }
	  printf("Case #%d: %.12lf\n", V, ans);
	}
	return 0;
}

