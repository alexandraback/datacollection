#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#define dou double
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define LL long long
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define FI first
#define SE second
#define RI(a) scanf("%d", &(a))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))
#define RL(a) scanf("%lld", &(a))
#define RLL(a, b) scanf("%lld%lld", &(a), &(b))
#define RLLL(a, b, c) scanf("%lld%lld%lld", &(a), &(b), &(c)) 
#define PI(r) printf("%d\n", (r))
#define PL(r) printf("%lld\n", (r))
#define RS(s) scanf("%s", (s))
#define SL(a) strlen(a)
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FOR(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
//Segment tree
#define MID ((l + r) >> 1)
#define L (x << 1)
#define R ((x << 1) | 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define LB(x) ((x) & (-(x)))
#pragma warning (disable : 4996)
//#pragma comment(linker, "/STACK:102400000,102400000")
#define EPS 1e-8
#define INF 2000000000
#define LIM (1ll << 60)
#define MOD 1000000007
#define N 111111

using namespace std;

int n, m;
int bad[111], use[111], cnt[111][26];
LL fac[111];
string s[111];
vector<string> v;

int check(int x) {
	REP(i, s[x].size()) if (s[x][i] != s[x][0]) return 1;
	return 0;
}

int main(){
	int t, x, y, z, ca = 1, fl = 0;
	freopen("D:/Contest/in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	//ios :: sync_with_stdio(false);
	fac[0] = 1;
	REPP(i, 1, 105) fac[i] = fac[i - 1] * i % MOD;
	RI(t);
	while (t--) {
		RI(n);
		REPP(i, 1, n) cin >> s[i];
		REPP(i, 1, n) {
			REP(j, s[i].size()) cnt[i][s[i][j] - 'a'] = 1;
		}
		REPP(i, 1, n) {
			REPP(j, i + 1, n) {
				int tt = 0;
				REP(k, 26) if (cnt[i][k] && cnt[j][k]) tt++;
				if (tt > 1) {
					fl = 1;
					break;
				}
			}
			if (fl) break;
		}
		if (fl) {
			printf("Case #%d: 0\n", ca++);
			mem(cnt), mem(use), mem(bad);
			REPP(i, 1, n) s[i].clear();
			fl = 0;
			continue;
		}
		REPP(i, 1, n) bad[i] = check(i);
		LL tmp = 1;
		REPP(i, 1, n) if (!use[i]){
			int hehe = 0;
			REPP(j, i, n) if (!use[j]) {
				if (!bad[i] && !bad[j] && s[i][0] == s[j][0]) hehe++, use[j] = 1;
			}
			tmp = tmp * fac[hehe] % MOD;
		}
		mem(use);
		REPP(i, 1, n) if(!use[i]) {
			REPP(j, 1, n) if (j - i && !bad[j] && !use[j] && s[i][s[i].size() - 1] == s[j][0]) {
				s[i] += s[j];
				use[j] = 1;
			}
		}
		REPP(i, 1, n) if (!use[i]) v.push_back(s[i]);
		n = v.size();
		mem(use);
		REP(i, n) if (!use[i]) {
			REP(j, n) if (i != j && !use[j]) {
				if (v[i][v[i].size() - 1] == v[j][0]) v[i] += v[j], use[j] = 1;
			}
		}
		int tot = 0;
		REP(i, n) if (!use[i]) tot++;
		LL ans = tmp * fac[tot] % MOD;
		printf("Case #%d: %lld\n", ca++, ans);
		mem(cnt), mem(use), mem(bad);
		REPP(i, 1, n) s[i].clear();
		v.clear();
		fl = 0;
	}


	return 0;
}
