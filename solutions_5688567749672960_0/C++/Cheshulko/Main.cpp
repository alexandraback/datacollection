#pragma comment(linker, "/STACK:100000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <locale>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define rep(x, a, b) for(int (x) = (a); (x) < int(b); ++(x))
#define sci(x) scanf("%d", &(x))
#define scii(x, y) scanf("%d %d", &(x), &(y))
#define pri(x) printf("%d ", (x))
#define prii(x, y) printf("%d %d", (x), (y))
#define pril(x) printf("%d\n", (x));
#define priil(x, y) printf("%d %d\n", (x), (y));
#define Wait cin.sync(); cin.get();
#define INF 0x3F3F3F3F
#define y1 qwerty 
#define EPS 1e-6
using namespace std;
typedef long long                  ll;
typedef pair<long long, long long> pll;
typedef pair<int, int>             pii;
typedef pair<double, int>          pdi;
typedef pair<double, double>       pdd;
typedef pair<string, string>       pss;

#define FILE

ll dp[1000005];

ll rev(ll x){
	ll ans = 0;
	while (x){
		ans = ans * 10ll + x % 10;
		x /= 10;
	}
	return ans;
}
/*
ll go(ll x){
	
	if (x == 1) return 1;
	if (dp[x]) return dp[x];
	cout << x << endl;
	ll f;
	if (dp[x - 1]) f = dp[x - 1]; else f = go(x - 1);
	ll r = rev(x);
	ll s = INF;
	//cout << r << " -> " << x << " ? " << endl;
	if (r < x && int(log10(0.0 + r)) == int(log10(0.0 + x))) {
		//cout << "ok : " << r << " - > " << x << endl;
		if (dp[r]) s = dp[r]; else s = go(r);
	}
	dp[x] = min(f, s) + 1;
	return dp[x];
}
*/
int main(){
#ifdef FILE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	int t;
	ll N;
	cin >> t;
	memset(dp, 63, sizeof dp);
	dp[1] = 1;
	rep(_t, 0, t){
		cin >> N;
		//cout << N << endl;
		//memset(dp, 0, sizeof dp);
		//
		rep(i, 2, N + 1) 
		{
			int xx = rev(i);
			dp[i] = min(dp[i], dp[i - 1] + 1);
			dp[xx] = min(dp[xx], dp[i] + 1);			
		}
		printf("Case #%d: %I64d\n", _t + 1, dp[N]);
		//rep(i, 0, 30) cout << i << " " << dp[i] << endl;
	}

#ifdef FILE
	//printf("TIME: %.3lf\n", (long double)(clock()) / CLOCKS_PER_SEC);
#endif
	Wait return 0;
}