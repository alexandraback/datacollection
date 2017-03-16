#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define size(x) (int) x.size()

const int maxn = 1005;
const int logn = 18;
const int inf = (int) 1e9 + 5;
const long long mod = (int) 1e9 + 7;
const long long base = 2204234849;
const long long l_inf = (long long) 4e18;
const long double pi = acos(-1.0);
const long double eps = 1e-12;

int T;

int n;
string topic[maxn][2];
int dp[1 << logn];
map<string, int> first, second;

int process() {
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i))
				continue;
			if ((first[topic[i][0]] & mask) != 0 && (second[topic[i][1]] & mask) != 0) {
				dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + 1);
			}
		}
	}
	return dp[(1 << n) - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	srand(566);

#ifdef LOCAL
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		first.clear();
		second.clear();
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i++) {
			cin >> topic[i][0] >> topic[i][1];
			first[topic[i][0]] |= 1 << i;
			second[topic[i][1]] |= 1 << i;
		}

		cout << "Case #" << t << ": ";
		cout << process() << '\n';
	}

	return 0;
}
