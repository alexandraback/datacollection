//
// b.cpp -- B
//
// Siwakorn Sriakaokul - ping128
// Written on Saturday, 13 April 2013.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>

#define MAXN 15
#define MAXE 15

using namespace std;

void reset(){
	// reset values for the each testcase
}

int V[MAXN];
int N, E, R;
int dp[MAXN][MAXE];
void solve(){
	reset();
	cin >> E >> R >> N;
	for(int i = 0; i < N; i++ ){
		cin >> V[i];
	}
	for(int i = 0; i < MAXN; i++ ){
		for(int j = 0; j < MAXE; j++ ){
			dp[i][j] = -1000000000;
		}
	}
	dp[0][E] = 0;
	for(int i = 0; i < N; i++ ){
		for(int j = 0; j <= E; j++ ){
			for(int k = 0; k <= j; k++ ){
				dp[i + 1][min(E, j - k + R)] = max(dp[i + 1][min(E, j - k + R)], dp[i][j] + V[i] * k);
			}
		}
	}
	int maxx = 0;
	for(int i = 0; i <= E; i++ ){
		maxx = max(maxx, dp[N][i]);
	}
	cout << maxx << endl;
}


int main()
{
	int test;
	cin >> test;
	for(int tt = 0; tt < test; tt++ ){
		printf("Case #%d: ", tt + 1);
		solve();
	}
	return 0;
}
