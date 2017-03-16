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
char Buf[1 << 20];
void solve(int num) {
	int S;
	cin >> S >> Buf;
	int cum = 0;
	int ans = cum;
	for (int i = 0; Buf[i]; ++i) {
		int need = i;
		if (cum < need) {
			ans += need - cum;
			cum += need - cum;
		}
		cum += Buf[i] - '0';
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
