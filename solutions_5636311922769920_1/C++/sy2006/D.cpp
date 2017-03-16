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
int k, c, s;
void run() {
	scanf("%d%d%d", &k ,&c, &s);
	vector<ll> ans;
	int _k = k;
	while (k) {
		ll cur = 0;
		for (int i=0; k && i<c; ++i)
			cur *= _k, cur += (--k);
		ans.pb(cur + 1);
	}
	if ((int)ans.size() > s)
		printf("IMPOSSIBLE"); else
	for (ll x : ans)
		printf("%lld ", x);
	puts("");
}
int main() {
	int T; scanf("%d", &T);
	for (int i=1; i<=T; ++i) {
		printf("Case #%d: ", i);
		run();
	}
	return 0;
}