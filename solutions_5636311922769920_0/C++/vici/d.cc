#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("d-ans-small", "w", stdout);
	
	int T, k, c, s, ca = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &k, &c, &s);
		printf("Case #%d:", ca++);
		Rep(i, s) printf(" %d", i);
		puts("");
	}
	return 0;
}

