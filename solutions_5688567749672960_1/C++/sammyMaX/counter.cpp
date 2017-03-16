#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ifstream fin("A-large.in");
ofstream fout("al.out");

const int SZ = 1e6 + 6;
ll p10[16] = {1};
int dp[SZ];
vll good;

inline ll rev(ll a) {
	ll res = 0;
	while (a) res = 10 * res + a%10, a /= 10;
	return res;
}

int solve2(ll a) {
	if (a < 5000) return dp[a];
	
	ll gd = *(--upper_bound(good.begin(), good.end(), a));
	return a - gd + solve2(rev(gd)) + 1;
}

int solve() {
	ll t;
	fin >> t;
	return solve2(t);
}

int main() {
	for (int i = 1; i < 16; i++) p10[i] = 10 * p10[i - 1];

	for (int n0 = 0; n0 <= 6; n0++) {
		ll mul = p10[n0 + 1];
		ll start = 2, end = p10[n0 + 1];
		if (n0 > 0) start = p10[n0 - 1] + 1;
		for (ll a = start; a < end; a++)
			if (a != p10[n0])
				good.push_back(a * mul + 1);
	}
	cout << good.size() << '\n';
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < SZ; i++) dp[i] = 1 << 30;
	for (int i = 1; i < SZ - 1; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		int r = rev(i);
		if (r < SZ) dp[r] = min(dp[r], dp[i] + 1);
	}
//	for (int i = 1; i < 230000; i++)
//		if (dp[i] < dp[i - 1]) cout << i << ' ' << dp[i] << '\n';

	int a;
	fin >> a;
	for (int i = 0; i < a; i++)
		fout << "Case #" << i+1 << ": " << solve() << endl;
}
