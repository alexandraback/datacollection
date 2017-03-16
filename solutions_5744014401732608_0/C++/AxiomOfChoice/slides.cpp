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

void work() {
	int b;
	ll m;
	scanf("%d%lld", &b, &m);

	if(m > (1ll << (b - 2))) {
		printf("IMPOSSIBLE\n");
		return;
	}

	printf("POSSIBLE\n");

	printf("0");
	range(j, 1, b - 1) {
		ll cur = 1ll << (b - 2 - j);
		if(m >= cur) {
			m -= cur;
			printf("1");
		} else {
			printf("0");
		}
	}
	if(m) {
		m--;
		printf("1");
	} else {
		printf("0");
	}
	printf("\n");

	range(i, 1, b) {
		rep(j, b) {
			printf(j <= i ? "0" : "1");
		}
		printf("\n");
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
