#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <bitset>
#include <string>
#include <algorithm>

#define tr(c, i) for(typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define sz(c) int((c).size())
#define INF 1000000000
#define EPS 1e-9
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int T, n, m, A[105], B[105];
ll dp[105][105], a[105], b[105];

ll f(int i, int j) {
	if(i == n || j == m) return 0LL;
	
	ll &ret = dp[i][j];
	if(ret != -1LL) return ret;
	
	ret = max(f(i+1, j), f(i, j+1));
	
//	printf("f(%d, %d)\n", i, j);
//	for(int x = 0; x < 100000000; ++x);
	
	if(A[i] == B[j]) {	// tipe sama, bisa di assembly
		int ni = i, nj = j;
		ll ai = a[i], bj = b[j], tot = 0LL;
		
		while(true) {
//			printf("ni=%d, nj=%d, ai=%d, bj=%d, tot=%d\n", ni, nj, ai, bj, tot);
			if(ai == 0LL) {
				ni++;
				while(ni < n && A[ni] != A[i]) ni++;

				if(ni == n) break;
				
				ai = a[ni];
			}
			if(bj == 0LL) {
				nj++;
				while(nj < m && B[nj] != B[j]) nj++;
				
				if(nj == m) break;
				
				bj = b[nj];
			}
			
			// here, barang ni & nj sudah setipe
			
			if(ai >= bj) {		// b habis
				tot += bj;				
				ai -= bj;
				bj = 0LL;
				
				ret = max(ret, f(ni+1, nj+1) + tot);
			}
			else {				// a habis
				tot += ai;	
				bj -= ai;
				ai = 0LL;
				
				ret = max(ret, f(ni+1, nj+1) + tot);
			}
			
		}
	}	
	
	return ret;
}

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; ++tc) {
		scanf("%d%d", &n, &m);
		
		for(int i = 0; i < n; ++i)
			scanf("%lld%d", &a[i], &A[i]);
			
		for(int i = 0; i < m; ++i)
			scanf("%lld%d", &b[i], &B[i]);
			
		memset(dp, -1LL, sizeof(dp));
		printf("Case #%d: %lld\n", tc + 1, f(0, 0));	
	}
	
	return 0;
}
