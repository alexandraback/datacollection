#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 3005;
const double eps = 1e-10;

vector <int> seq;
int t;
int n, x, y;
int no;
double dp[Maxm][Maxm];

double Get(int has, int h, int need)
{
	for (int i = 0; i <= has; i++)
		for (int j = 0; j <= has; j++) dp[i][j] = 0.0;
	dp[0][0] = 1.0;
	for (int i = 0; i < has; i++)
		for (int j = 0; j < h; j++) if (i - j < h && dp[i][j] > eps)
			if (j + 1 == h) dp[i + 1][j] += dp[i][j];
			else if (i - j + 1 == h) dp[i + 1][j + 1] += dp[i][j];
			else {
				dp[i + 1][j] += dp[i][j] / 2.0;
				dp[i + 1][j + 1] += dp[i][j] / 2.0;
			}
	double res = 0.0;
	for (int i = need + 1; i < h; i++)
		res += dp[has][i];
	return res;
}

int main()
{
	seq.push_back(1);
	for (int i = 1; seq.back() < Maxn; i++)
		seq.push_back(seq.back() + 4 * i + 1);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d %d", &n, &x, &y);
		int got = upper_bound(seq.begin(), seq.end(), n) - seq.begin() - 1;
		no = (abs(x) + abs(y)) / 2;
		if (no <= got) printf("Case #%d: 1.000000000\n", tc);
		else if (no > got + 1) printf("Case #%d: 0.000000000\n", tc);
		else printf("Case #%d: %.9lf\n", tc, Get(n - seq[got], 2 * (got + 1) + 1, y));
	}
	return 0;
}