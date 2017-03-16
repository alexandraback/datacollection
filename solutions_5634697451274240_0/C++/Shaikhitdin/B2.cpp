/// izizi

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 110;

string s;
int a[N];
int dp[N][2];

int main() {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);	
	
	int t_num;
	
	cin >> t_num;
	
	for (int t = 1; t <= t_num; ++t) {
		cout << "Case #" << t << ": ";
		cin >> s;
		int n = s.size ();
		for (int i = 0; i < n; ++i)
			a[i] = (s[i] == '+');
		for (int i = 0; i <= n; ++i)
			dp[i][0] = dp[i][1] = oo;
		dp[0][0] = dp[0][1] = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == 0) {
				dp[i + 1][0] = min (dp[i][0], dp[i + 1][0]);
				dp[i + 1][1] = min (dp[i][0] + 1, dp[i + 1][1]);
			} else {
				dp[i + 1][0] = min (dp[i][1] + 1, dp[i + 1][0]);
				dp[i + 1][1] = min (dp[i][1], dp[i + 1][1]);			
			}
		}
		cout << dp[n][1] << "\n";
	}
	
	return 0;
}