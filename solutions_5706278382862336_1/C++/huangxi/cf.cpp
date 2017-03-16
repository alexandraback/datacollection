#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#define RD(x)      scanf("%d", &x)
#define REP(i, n)  for (int i=0; i<(n); i++)
#define REP1(i, n) for (int i=1; i<=(n); i++)
#define pii        pair<int, int>
#define mp         make_pair

using namespace std;
#define  N   111
#define  M   22222
#define  eps 1e-9
#define  pi  acos(-1.0)
#define  inf 0XFFFFFFFll
#define  mod 1000000007ll
#define  LL  long long
void get(LL &p, LL &q, char s[]) {
	p = q = 0;
	int i = 0;
	while (s[i] >= '0' && s[i] <= '9') {
		p = p * 10 + s[i] - '0';
		i++;
	}
	i++;
	while (s[i] >= '0' && s[i] <= '9') {
		q = q * 10 + s[i] - '0';
		i++;
	}
}

int main() {
	freopen("A-large.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int T; RD(T);
	REP1(TT, T) {
		char s[100]; scanf("%s", s);
		LL p, q;
		get(p, q, s);
		LL g = __gcd(p, q);
		p /= g;
		q /= g;
		LL m = 1ll << 40ll;
		bool impossible = true;
		int ans = 0;
		if (m % q == 0) {
			impossible = false;
			p *= m / q;
			while (m > p) {
				m /= 2;
				ans++;
			}
		}
		cout << "Case #" << TT << ": ";
		if (impossible) cout << "impossible" << endl;
		else cout << ans << endl;
	}
}
