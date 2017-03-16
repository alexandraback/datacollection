#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
using namespace std;
typedef long long ll;

template <typename T> inline void R(T &x) {
	char ch = getchar(); x = 0;
	for (; ch<'0' || ch>'9'; ch = getchar());
	for (; ch<='9' && ch>='0'; ch=getchar()) x = x*10 + ch-'0';
}
const int pn = 8, p[] = {2,3,5,7,11,13,17,19};
int n, m, h, po[pn][11][40], fr[11];
int get(int pi, int base, int mask) {
	int r = po[pi][base][0] + po[pi][base][n - 1];
	for (int i=0; i<n-2; ++i)
		if ((mask >> i) & 1)
		r += po[pi][base][i + 1];
	return r % p[pi];
}
bool check(int mask) {
	for (int b=2; b<=10; ++b) {
		bool flag = 0;
		for (int pi=0; !flag && pi<pn; ++pi)
			if (!get(pi, b, mask)) {
				flag = 1;
				fr[b] = p[pi];
			}
		if (!flag) return 0;
	}
	return 1;
}
void print(int mask) {
	putchar('1');
	for (int i=n-3; i>=0; --i)
		printf("%d", (mask >> i) & 1);
	putchar('1');
	for (int i=2; i<=10; ++i)
		printf(" %d", fr[i]);
	puts("");
}
void run() {
	scanf("%d%d", &n, &m);
	h = (n - 1) >> 1;
	for (int pi=0; pi<pn; ++pi)
		for (int i=2; i<=10; ++i) {
			po[pi][i][0] = 1;
			for (int j=1; j<=n; ++j)
				po[pi][i][j] = po[pi][i][j-1] * i % p[pi];
		}
	int cnt = 0;
	for (int i=0; ; ++i) {
		if (check(i)) {
			print(i);
			if (++cnt == m)
				break;
		}
	}
		
}
int main() {
	int T; scanf("%d", &T);
	for (int i=1; i<=T; ++i) {
		printf("Case #%d:\n", i);
		run();
	}
	return 0;
}