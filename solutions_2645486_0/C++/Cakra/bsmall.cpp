#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
#define INF 2000000000
#define EPS 1e-9
#define sz(c) (int) (c).size()
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define uniq(c) sort(all(c)); (c).resize(unique(all(c)) - (c).begin())
#define lobo(c, x) (int) (lower_bound(all(c), (x)) - (c).begin())
#define upbo(c, x) (int) (upper_bound(all(c), (x)) - (c).begin())
 
#define PB push_back
#define MP make_pair
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;

int T, E, R, N, v[15];
int ans;

void solve(int pos, int eleft, int gain) {
	if(pos == N) {
		ans = max(ans, gain);
		return;
	}
	
	for(int i = 0; i <= eleft; i++) {
		solve(pos+1, min(E, eleft-i+R), gain + v[pos]*i);
	}
}

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; tc++) {
		scanf("%d%d%d", &E, &R, &N);
		
		for(int i = 0; i < N; i++) {
			scanf("%d", &v[i]);
		}
		
		ans = -1;
		solve(0, E, 0);
		
		printf("Case #%d: ", tc+1);
		printf("%d\n", ans);
	}
	
	return 0;
}
