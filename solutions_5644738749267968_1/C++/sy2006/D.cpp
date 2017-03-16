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
const int N = 1005;
int n;
double a[N], b[N];
void run(int C) {
	printf("Case #%d: ", C);
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%lf", &a[i]);
	for (int i=1; i<=n; ++i) scanf("%lf", &b[i]);
	sort(a+1, a+n+1); reverse(a+1, a+n+1);
	sort(b+1, b+n+1); reverse(b+1, b+n+1);
	int p = 1, cnt = 0;;
	for (int i=1; i<=n; ++i) {
		for (; p<=n && b[p]>=a[i]; ++p);
		if (p<=n && b[p]<=a[i]) {
			++cnt;
			++p;
		}
	}
	printf("%d ", cnt);
	p = 1, cnt = 0;
	for (int i=1; i<=n; ++i) {
		if (b[p] > a[i])
			++p; else
			++cnt;
	}
	printf("%d\n", cnt);
}
int main() {
	int T; R(T);
	for (int i=1; i<=T; ++i) run(i);
	return 0;
}
