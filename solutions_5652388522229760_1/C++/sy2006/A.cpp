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
int n;
int get(int x) {
	int r = 0;
	while (x) {
		r |= 1 << (x % 10);
		x /= 10;
	}
	return r;
}
void run() {
	scanf("%d", &n);
	if (!n) {
		puts("INSOMNIA");
		return;
	}
	int i, S = 0;
	for (i=1; S != (1<<10)-1; ++i)
		S |= get(i * n);
	printf("%d\n", (i - 1) * n);
}
int main() {
	int T; scanf("%d", &T);
	for (int i=1; i<=T; ++i) {
		printf("Case #%d: ", i);
		run();
	}
	return 0;
}