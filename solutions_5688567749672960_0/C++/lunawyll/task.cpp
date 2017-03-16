#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>

#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <utility>
#include <numeric>

using namespace std;

#ifdef LUNAWYLL
#define dbg(x) cout << #x << " = " << (x) << endl;
#define dbg2(a, b) cout << #a << " = " << (a) << "; " <<\
	#b << " = " << (b) << endl;
#else
#define dbg(x) (void(0));
#define dbg(x) (void(0));
#endif

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


void task();

int main(){
#ifdef LUNAWYLL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	task();

#ifdef LUNAWYLL
	cout << "\n==================\n";
	cout << fixed << setprecision(3) << (double)clock() / CLOCKS_PER_SEC << "ms" << endl;
#endif
	return 0;
}
const int INF = (int)1e9;
int dp[(int)1e6 + 10];

void task(){
	int t;
	scanf("%d", &t);
	fill(dp, dp + (int)1e6 + 10, INF);
	dp[1] = 1;
	for (int i = 1; i <= (int)1e6; ++i){
		dp[i] = min(dp[i], dp[i-1] + 1);
		int num = 0, a = i, deg = 1;
		while (a != 0){
			num = num * 10 + a % 10;
			a /= 10;
		}
		if (num <= (int)1e6){
			dp[num] = min(dp[num], dp[i] + 1);
		}
	}
	for (int i = 1; i <= t; ++i){
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", i, dp[n]);
	}
	
}