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
#pragma comment(linker, "/STACK:640000000")
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
int a[33],b[33],c[33];
ll dp[33][2][2][2];
ll get(int pos, int aa, int bb, int cc) {
	if (pos == 30) return aa;
	ll &res = dp[pos][aa][bb][cc];
	if (res != -1) return res;
	res = 0;
	if (aa == 0) {
		for (int i = 0; i <= (bb == 1 || b[pos] == 1 ? 1 : 0); i++) {
			for (int j = 0; j <= (cc == 1 || c[pos] == 1 ? 1 : 0); j++) {
				int w = i & j;
				if (w > a[pos]) continue;
				res += get(pos + 1,a[pos] == 1 && w == 0,bb | (b[pos] == 1 && i == 0),cc | (c[pos] == 1 && j == 0));
			}
		}
	} else {
		for (int i = 0; i <= (bb == 1 || b[pos] == 1 ? 1 : 0); i++) {
			for (int j = 0; j <= (cc == 1 || c[pos] == 1 ? 1 : 0); j++) {
				res += get(pos + 1,aa,bb | (b[pos] == 1 && i == 0),cc | (c[pos] == 1 && j == 0));
			}
		}
	}
	return res;
}
void solve() {
	int A,B,C; cin >> B >> C >> A;
	B--;
	C--;
	for (int i = 0; i < 30; i++) {
		a[i] = A & 1; A >>= 1;
		b[i] = B & 1; B >>= 1;
		c[i] = C & 1; C >>= 1;
	}
	reverse(a,a + 30);
	reverse(b,b + 30);
	reverse(c,c + 30);
	memset(dp,-1,sizeof(dp));
	cout << get(0,0,0,0) << endl;
}
int main() {
	#ifndef ONLINE_JUDGE
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
