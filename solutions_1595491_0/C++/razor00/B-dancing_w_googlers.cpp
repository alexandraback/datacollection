#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
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

int T, n, s, p, t, ans;
/*
void solve() {
	for(int n = 0; n <= 30; ++n) {
	printf("n=%d\n", n);
	for(int i = 0; i <= 10; ++i)
		for(int j = i; j <= 10; ++j)
			for(int k = j; k <= 10; ++k) {
				if(abs(i-j) > 2 || abs(i-k) > 2 || abs(k-j) > 2) continue;
				if(i+j+k == n) {
					int ma = max(i, max(j, k));
					printf("(%d, %d, %d)=%d\n", i, j, k, ma);
				}
			}
	}
}
*/
int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; ++tc) {
		scanf("%d%d%d", &n, &s, &p);
		
		ans = 0;
		int sleft = s;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &t);
			
			if(t < 2 || t > 28) {
				int val = (t + 1)/3;
				if(t == 1) val++;
				
				if(val >= p) ans++;
			}
			else {
				int mi = (t + 1)/3, ma = mi + 1;
				if(t%3 == 1) mi++;
				
				if(mi >= p) ans++;
				else if(ma == p && mi < p) {
					if(sleft > 0) {
						ans++;
						sleft--;	
					}	
				}
			}
		}
		
		printf("Case #%d: %d\n", tc + 1, ans);
	}
	
	return 0;
}
