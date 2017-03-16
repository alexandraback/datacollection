#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <sstream>
#include <ctime>
#include <functional>
#define pi 3.14159265358979323846264338327950288
#define pb push_back
#define mp make_pair
#define LL long long
#define LD LL double
#define INF 1000000
#define INFll 1000000000000000000ll
#define Vi vector<int>
#define VI Vi::iterator
#define Mi map<int, int>
#define MI Mi::iterator
#define Si set<int>
#define SI Si::iterator
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define mid (l + r) / 2
#define Left k * 2, l, mid
#define Right k * 2 + 1, mid + 1, r
#define N 1111111
using namespace std;
LL p[32];
LL trans(LL x) {
	LL ans = 0;
	while (x) {
		ans = ans * 10ll + x % 10;
		x /= 10;
	}
	return ans;
}
LL get(LL now) {
	if (now == 1) return 1;
	LL cur, cnt, num, ans, upp;
	cur = cnt = num = 1;
	ans = now;
	int i;
	while (cur <= now) {
	ans = min(ans, cnt + now - cur);
	if (cur == now) return ans;
	for (i = 0; i <= 17; i++)
		if (p[i] > cur) break;
	upp = p[i];
	if (upp <= now) {
		if (cur == 1) {
			cur = cnt = 10;
			++ num;
			continue;
		}
		cur += p[num >> 1] - 1; cur = trans(cur);
		cnt += p[num >> 1] + upp - cur; cur = upp;
		++ num;
	}
	else {
		if (now % 10 == 0)
			++ cnt,
			-- now;
		LL tmp = trans(now);
        tmp %= p[num >> 1];
        cur += tmp; cnt += tmp;
        cur = trans(cur); cnt += 1 + now - cur;
        cur = now;
       }
	}
    return ans;
 }
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int T, cas;
	cin >> T;
	p[0] = 1;
	for (int i = 1; i <= 17; i++)
		p[i] = p[i - 1] * 10;
	for (cas = 1; cas <= T; cas++) {
        LL n;
		cin >> n;
		printf("Case #%d: %I64d\n", cas, get(n));
	}
}
