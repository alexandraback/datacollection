#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <iterator>
#include <bitset>
#include <random>
#include <assert.h>

#ifdef _MSC_VER
#include <agents.h>
#endif

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> P;

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t){
		printf("Case #%d: ", t);

		int n, m, k;
		cin >> n >> m >> k;

		int ans = n*m;
		rep(tl, n) FOR(tr, tl, n) rep(bl, n) FOR(br, bl, n) rep(height, m){
			int stones = tr-tl+1;
			if (height) stones += br-bl+1;
			stones += max(2 * (height - 1), 0);
			int l = tl, r = tr;
			int cnt = stones;
			FOR(i, 1, height){
				--l, ++r;
				l = max({ l, 0, bl-(height-i)});
				r = min({ r, n-1, br+(height-i)});
				cnt += max(0, r - 1 - (l + 1) + 1);
				if (l == r) --stones, --cnt;
			}
			if (cnt >= k) ans = min(ans, stones);
		}

		cout << ans << endl;
	}

	return 0;
}