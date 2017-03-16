#pragma comment(linker, "/STACK:640000000")
#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<algorithm>

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)

using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);

const int inf = (int)1e6;

int n,m,w;

int dp[1 << 20];
int dp2[22][22][22];

int get2(int len, int l, int r) {
	if (len < w) return -inf;
	if (r - l + 1 == w) return 0;
	int &res = dp2[len][l][r];
	if (res != -1) return res;
	res = inf;
	for (int i = 0; i < l; i++) {
		if (r - i + 1 > w) continue;
		res = min(res,max(get2(len,i,r) + l - i,get2(len - i - 1,l - i - 1,r - i - 1) + 1));
	}
	for (int i = r + 1; i < len; i++) {
		if (i - l + 1 > w) continue;
		res = min(res,max(get2(len,l,i) + i - r,get2(i,l,r) + 1));
	}
	return res;
}

int get(int mask) {
	int &res = dp[mask];
	if (res != -1) return res;
	int cur = 0;
	for (int i = 0; i < m; i++) {
		if ((mask & (1 << i)) == 0) {
			cur++;
		} else {
			cur = 0;
		}
		if (cur >= w) break;
	}
	if (cur < w) return res = -inf;
	res = inf;
	for (int i = 0; i < m;) {
		if ((mask & (1 << i)) != 0) {
			i++;
			continue;
		}
		int j = i;
		while(j < m && (mask & (1 << j)) == 0) j++;
		for (int k = i; k < j; k++) {
			res = min(res,max(get(mask | (1 << k)),get2(j - i,k - i,k - i)) + 1);
		}
		i = j;
	}
	return res;
}

void solve() {
	cin >> n >> m >> w;
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	cout << get(0) + (n - 1) * (m / w) << endl;
}

int main() {
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif	

	int Cases; cin >> Cases;

	for (int Case = 1; Case <= Cases; Case++) {
		printf("Case #%d: ",Case);
		solve();
	}
		
	return 0;
}
