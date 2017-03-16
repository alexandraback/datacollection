#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

const long double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int TESTS, CASE;
int n, x, y;
long double dp[2005][2005];

void solve() {
	cout << "Case #" << CASE << ": ";
	
	int c = 1;
	while(c*(2*c-1) <= n) {
		c++;
	}
	c--;
	
	int d = (abs(x) + y)/2 + 1;
	
	cout << fixed << setprecision(12);
	if(d <= c) {
		cout << 1. << endl;
		return;
	} else if(d > c+1) {
		cout << 0. << endl;
		return;
	}
	
	int m = n-c*(2*c-1);
	int k = y+1;
	if(m < k) {
		cout << 0. << endl;
		return;
	}
	
	int len = 2*c;
	
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= m; i++) {
		for(int a = 0; a <= min(len, i-1); a++) {
			int b = (i-1)-a;
			if(a == len) {
				dp[i][len] += dp[i-1][len];
			} else if(b == len) {
				dp[i][a+1] += dp[i-1][a];
			} else {
				dp[i][a+1] += 0.5*dp[i-1][a];
				dp[i][a] += 0.5*dp[i-1][a];
			}
		}
	}
	
	long double ans = 0;
	for(int i = k; i <= len; i++) {
		ans += dp[m][i];
	}
	cout << ans << endl;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	cin >> TESTS;
	for(CASE = 1; CASE <= TESTS; CASE++) {
		cin >> n >> x >> y;
		solve();
	}
}
