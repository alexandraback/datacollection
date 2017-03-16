#include <cstdio>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
using namespace std;
typedef long long ll;

inline void R(int &x) {
	char ch = getchar(); x = 0;
	for (; ch<'0'; ch=getchar());
	for (; ch>='0'; ch=getchar()) x = x*10+ch-'0';
}
const int N = 55;
int n, m, r, s;
bool rev, imp;
char a[N][N];
void print() {
	if (imp) {
		puts("Impossible");
		return;
	}
	if (rev)
		for (int i=1; i<=m; ++i) {
			for (int j=1; j<=n; ++j)
				putchar(a[j][i]);
			puts("");
		}
	else
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=m; ++j)
				putchar(a[i][j]);
			puts("");
		}
}
void solve1() {
	for (int i=1; i<=s-r; ++i) a[1][i] = '.';
	for (int i=s-r+1; i<=m; ++i) a[1][i] = '*';
	a[1][1] = 'c';
}
void solven() {
	r = s - r;
	if (r == 1) {
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=m; ++j)
				a[i][j] = '*';
		a[1][1] = 'c';
	} else
	if (r < 4)
		imp = 1;
	else {
		int t = r / 2 - 2;
		t = min(t, n + m - 4);
		int c = r - (t * 2 + 4);
		int wx = 0, wy = 0;
		for (int i=0; i<=t; ++i)
			if (i+2 <= n && t-i+2 <= m && (t-i) * i > wx*wy)
				wx = i, wy = t - i;
		if (wx * wy < c) {
			imp = 1;
			return;
		}
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=m; ++j)
				a[i][j] = '*';
		for (int i=1; i<=wx+2; ++i)
			a[i][1] = a[i][2] = '.';
		for (int i=1; i<=wy+2; ++i)
			a[1][i] = a[2][i] = '.';
		for (int i=1; i<=wx && c; ++i)
			for (int j=1; j<=wy && c; ++j)
				a[i+2][j+2] = '.', --c;
		a[1][1] = 'c';
	}
}
void run(int C) {
	printf("Case #%d:\n", C);
	R(n); R(m); R(r); rev = 0; s = n * m; imp = 0;
	if (m == 1) rev = 1, swap(n, m);
	if (n == 1)
		solve1(); else
		solven();
	print();
}
int main() {
	int T; R(T);
	for (int i=1; i<=T; ++i) run(i);
	return 0;
}
