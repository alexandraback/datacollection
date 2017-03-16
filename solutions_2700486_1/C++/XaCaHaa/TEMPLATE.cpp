#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#include <utility>
#include <set>
#include <functional>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
using namespace std;

#define FOR(_i,_n) for(int (_i)=0;(_i)<(_n);(_i)++)
#define iss istringstream
#define oss ostringstream
#define mp make_pair
#define pb push_back
#define px first
#define py second
#define pi 3.141592653589793
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> Pair;

bool check(int K, int X, int Y) {
	if(K > Y && K - Y - 1 >= abs(X)) return true;
	else return false;
}

double dp[2000][2000];
double f(int k, int N, int X, int Y) {
	memset(dp, 0, sizeof(dp));
	
	dp[0][0] = 1.0;
	
	FOR(i, k + 3) FOR(j, k + 3) {
		if(i == k + 1 && j == k + 1)  continue;
		else if(i == k + 1) dp[i][j + 1] += dp[i][j];
		else if(j == k + 1) dp[i + 1][j] += dp[i][j];
		else {
			dp[i][j + 1] += dp[i][j] * 0.5;
			dp[i + 1][j] += dp[i][j] * 0.5;
		}
	}
	
	double res = 0.0;
	FOR(i, k + 3) FOR(j, k + 3) {
		if(i + j == N && i > Y) {
			res += dp[i][j];
		}
	}
	return res;
}

double solve(int N, int X, int Y) {
	int k = 1;
	while(k * (k + 1) / 2 <= N) {
		k += 2;
	}
	k -= 2;
	
	if(check(k, X, Y)) {
		return 1.0;
	}
	
	if(!check(k+2, X, Y)) {
		return 0.0;
	}
	
	N -= k * (k + 1) / 2;
	return f(k, N, X, Y);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for(int tt=1;tt<=T;tt++) {
		int N, X, Y;
		cin >> N >> X >> Y;
		
		cout.setf(ios::fixed);
		cout.precision(8);
		cout << "Case #" << tt << ": " << solve(N, X, Y) << endl;
	}

	return 0;
}
