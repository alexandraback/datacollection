#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;++i)
#define FOR(i, a, b) for(int i = a;i < b;++i)
#define F first
#define S second
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int, int> ii;

const int MAX = 1e7;
const int INF = 1e9;
int n;
int dp[MAX];

int flip(int x) {
	int y = 0;
	while(x) {
		y += x % 10;
		x /= 10;
		y *= 10;
	}
	return y/10;
}

bool invalid(int x) {
	return !(x % 10);
}

int f(int x) {
	if(x >= MAX) return INF;
	if(x == 1) return 1;
	if(dp[x]) return dp[x];
	if(flip(x) >= x || invalid(x)) return dp[x] = f(x - 1) + 1;
	return dp[x] = min(f(x - 1) + 1, f(flip(x)) + 1);
}

int main() {
	int t;
	cin >> t;
	REP(i, t) {
		cin >> n;
		cout << "Case #" << i + 1 << ": " << f(n) << "\n";
	}
}