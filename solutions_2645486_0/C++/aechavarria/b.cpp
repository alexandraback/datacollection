using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

const int MAXN = 15;
const int MAXE = 15;
int v[MAXN];
int dp[MAXN][MAXE];

int main(){
	int cases;
	cin >> cases;
	for (int run = 1; run <= cases; ++run){
		int e, r, n;
		cin >> e >> r >> n;
		
		for (int i = 0; i < n; ++i) cin >> v[i];
		
		for (int j = 0; j <= e; ++j){
			dp[n][j] = 0;
		}
		
		for (int i = n-1; i >= 0; --i){
			for (int j = 0; j <= e; ++j){
				dp[i][j] = 0;
				for (int k = 0; j - k >= 0; ++k){
					dp[i][j] = max (dp[i][j], v[i] * k + dp[i+1][min(e, j-k+r)]);
				}
			}
		}
		
		// for (int i = 0; i < n; ++i){
		// 	for (int j = 0; j <= e; ++j){
		// 		printf("%d ", dp[i][j]);
		// 	}
		// 	printf("\n");
		// }
		
		printf("Case #%d: %d\n", run, dp[0][e]);
	}
	
    return 0;
}
