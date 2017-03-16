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
#define LD long double
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
map<LL, LL> f;
queue<LL> Q;
LL trans(LL x) {
	LL ans = 0;
	while (x) {
		ans = ans * 10ll + x % 10;
		x /= 10;
	}
	return ans;
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int T, cas;
	cin >> T;
	Q.push(1);
	f[1] = 1;
	while (!Q.empty()) {
		LL head = Q.front();
		Q.pop();
		if (head > INF) continue;
		LL t1 = head + 1;
		LL t2 = trans(head);
		if (f.find(t1) == f.end() || f[head] + 1 < f[t1]) {
			f[t1] = f[head] + 1;
			Q.push(t1);
		}
		if (f.find(t2) == f.end() || f[head] + 1 < f[t2]) {
			f[t2] = f[head] + 1;
			Q.push(t2);
		}
	}
	for (cas = 1; cas <= T; cas++) {
        LL n;
		cin >> n;
		printf("Case #%d: %I64d\n", cas, f[n]);
	}
}
