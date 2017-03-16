#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 100010;
int n, len;
double p[N], s[N];

void solve() {
	scanf("%d%d", &n, &len);
	s[0] = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%lf", p + i);
		s[i] = s[i - 1] * p[i];
	}
	double ans = len + 2;
	for (int i = 0; i <= n; ++i) {
		double cnt = (n - i) * 2 + len - n + 1;
		cnt += (1 - s[i]) * (len + 1);
//		printf("%lf\n", cnt);
		ans = min(ans, cnt);
	}
	printf("%.6lf\n", ans);
}

int main() {
//	freopen("in","r",stdin);
//	freopen("in.txt","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int cas;
	scanf("%d ", &cas);
	for (int i = 1; i <= cas; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
