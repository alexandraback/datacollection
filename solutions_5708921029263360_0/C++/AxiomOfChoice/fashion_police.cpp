#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define clr1(i) CLR(i,-1)
#define bit(x,i) ((x>>i)&1)
#define M(x) ((x)%MOD)
#define acc(f,x,y) x=f(x,y)
#define fst first
#define snd second
#define tup make_tuple

char ab[9], ac[9], bc[9];

void work() {
	int a, b, c, k;
	scanf("%d%d%d%d", &a, &b, &c, &k);

	if(k >= c) {
		printf("%d\n", a * b * c);
		rep(x, a) rep(y, b) rep(z, c) {
			printf("%d %d %d\n", x + 1, y + 1, z + 1);
		}
		return;
	}

	int ans = 0, best = 0;
	rep(m, 1<<(a * b * c)) {
		clr0(ab);
		clr0(ac);
		clr0(bc);
		int tot = 0;
		rep(x, a) rep(y, b) rep(z, c)
		if(1 & (m >> (x + a * (y + b * z)))) {
			tot++;
			ab[x + a * y]++;
			ac[x + a * z]++;
			bc[y + b * z]++;
		}
		rep(i, a * b) if(ab[i] > k) tot = -1;
		rep(i, a * c) if(ac[i] > k) tot = -1;
		rep(i, b * c) if(bc[i] > k) tot = -1;
		if(tot > ans) {
			ans = tot;
			best = m;
		}
	}

	printf("%d\n", ans);

	rep(x, a) rep(y, b) rep(z, c)
	if(1 & (best >> (x + a * (y + b * z)))) {
		printf("%d %d %d\n", x + 1, y + 1, z + 1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	rep(t, n) {
		printf("Case #%d: ", t + 1);
		work();
	}
	return 0;
}
