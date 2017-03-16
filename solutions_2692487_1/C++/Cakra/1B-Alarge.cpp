#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define sz(a) int((a).size())
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define uniq(c) sort(all((c))); (c).resize(unique(all((c))) - (c).begin())
#define lobo(c, x) (int) (lower_bound(all((c)), (x)) - (c).begin())
#define upbo(c, x) (int) (upper_bound(all((c)), (x)) - (c).begin())
#define mii(a, b) if(b < a) a = b
#define maa(a, b) if(b > a) a = b

#define INF 2000000000
#define EPS 1e-5
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define X first
#define Y second
#define DEBUG(x) printf("debugging.. %d\n", x);
#ifdef TEST
#define deb(...) fprintf(stderr, __VA_ARGS__)
#else 
#define deb(...)
#endif
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

string tobin(int x, int len) {
	string c;
	while(x) { c.PB(x%2+'0'); x /= 2; }
	while(sz(c) < len) c.PB('0');
	reverse(all(c));
	return c;
}
//------------------------------

const int MXN = 100;
int T, A, N, ar[MXN+5];

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; tc++) {
		scanf("%d%d", &A, &N);
		
		for(int i = 0; i < N; i++) 
			scanf("%d", &ar[i]);
		
		sort(ar, ar + N);
		
		if(A == 1) {
			printf("Case #%d: %d\n", tc+1, N);
			continue;
		}
		
		int ans = INF, cnt = 0;
		for(int i = 0; i < N; i++) {
			ans = min(ans, cnt+(N-i));	// hapus ke i dst
//			printf("i=%d, cnt=%d, N-i=%d, ari=%d, A=%d\n", i, cnt, N-i, ar[i], A);
			if(A <= ar[i]) {
				int k = (int) floor(log2(1.0 + (ar[i]-A)/(A-1.0))) + 1;
				A += ar[i] + ((1 << k)-1)*(A-1);
//				printf("k=%d, log=%.5lf, dalam=%d\n", k, log2(1 + (ar[i]-A)/(A-1)), 1 + (ar[i]-A)/(A-1));
				cnt += k;
			}
			else {
				A += ar[i];	// makan
			}
		}
		
		ans = min(ans, cnt);
		
		printf("Case #%d: %d\n", tc+1, ans);
	}
	
	return 0;
}
