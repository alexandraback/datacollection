#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP1(i, n) for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define CLR(x, n) memset(x, n, sizeof(x))
using namespace std;
typedef long double lb;
const long double delta = 1e-8;

void setIO(string name) {
	string in_f = name + ".in";
	string out_f = name + ".out";
	freopen(in_f.c_str(), "r", stdin);
	freopen(out_f.c_str(), "w", stdout);
}

double r, s;

void init() {
	scanf("%lf%lf", &r, &s);//cout << r << ' ' << s << endl;
}

void solve() {
	long double a = lb(1), b = lb(2) * lb(r) + lb(1), c = lb(2) * lb(r) - lb(2) * lb(s);
	long double t = (-b + lb(sqrt(b * b - lb(4.0) * a * c))) / (lb(2.0) * a);//	cout << t << endl;
	int ans = int(floor(t) + delta);//cout << ans << endl;
	if (ans % 2 == 0) --ans;
	ans = (ans + 1) / 2;
	printf("%d\n", ans);
}

int main() {
	setIO("1");
	int TT;
	cin >> TT;
	REP1(i, TT) {
		printf("Case #%d: ", i);
		init();
		solve();
	}
	return 0;
}
