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
char S[200];
void run() {
	scanf("%s", S);
	int n = strlen(S);
	S[n] = '+';
	int ans = 0;
	for (int i=1; i<=n; ++i)
		ans += (S[i] != S[i - 1]);
	printf("%d\n", ans);
}
int main() {
	int T; scanf("%d", &T);
	for (int i=1; i<=T; ++i) {
		printf("Case #%d: ", i);
		run();
	}
	return 0;
}