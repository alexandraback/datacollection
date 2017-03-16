// -Wl,--stack,9001 
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;

int D, P[1 << 20], P1[1 << 20];

// 3
// 1..3 - 1
// 4..6 - 2
// 7..9 - 3

int check(int t) {
	int res = t;
	for (int i = 0; i < D; ++i) {
		res += (P[i] + t - 1) / t - 1;
	}
	return res;
}

void solve(int num) {
	cin >> D;
	for (int i = 0; i < D; ++i) {
		cin >> P[i];
	}
	sort(P, P + D);
	reverse(P, P + D);
	int ans = 1 << 30;	
	for (int i = 1; i <= P[0]; ++i) {
		int tmp = check(i);
		//printf("- %d %d\n", i, tmp);
		ans = min(ans, tmp);
	}	
	printf("Case #%d: %d\n", num, ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i) {
		solve(i);
	}
    return 0;
}
