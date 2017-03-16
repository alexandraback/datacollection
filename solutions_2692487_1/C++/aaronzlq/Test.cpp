#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

#define  rep(i, n)  for(int i = 0; i < (n); i++)
#define  repu(i, l, r)  for(int i = (l); i <= (r); i++)
#define  repd(i, r, l)  for(int i = (r); i >= (l); i--)
#define  MP  make_pair
#define  clr(a, x)  memset(a, x, sizeof(a))
#define  reget(str)  freopen(str, "r", stdin)

typedef long long llg;

const int N = 105;
llg x, n, w[N];
llg cal(int lim) {
	int now = x, ans = 0;
	repu(i, 0, lim) {
		while(now <= w[i]) {
			if(now == 1)  return  n;
			now += (now-1);
			ans++;
		}
		now += w[i];
	}
	return  ans+n-1-lim;
}
void run() {
	int T;
	cin >> T;
	repu(Case, 1, T) {
		cin >> x >> n;
		rep(i, n)  cin >> w[i];
		sort(w, w+n);
		llg ans = n, tmp;
		repu(i, 0, n-1) {
			tmp = cal(i);
			ans = min(ans, tmp);
		}
		printf("Case #%d: %lld\n", Case, ans);
	}
}

int main() {
    reget("data.in");
	freopen("data.out", "w", stdout);
    run();
	return  0;
}
















