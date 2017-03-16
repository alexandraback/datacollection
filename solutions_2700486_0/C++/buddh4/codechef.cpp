#define _CRT_SECURE_NO_WARNINGS
#include <numeric>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream> 
#include <stack>

#pragma comment(linker, "/STACK:256000000")
using namespace std;
typedef long long ll;
template<typename T> int size(T &a) {return (int)a.size();}
template<typename T> T sqr(T a)  { return a * a; }

#define fi first
#define se second
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,a,b) for(int i=(a);i<(b); ++i)
#define REPD(i,a,b)for(int i=(b)-1;i>=a;--i)
#define _(a,b) memset((a), (b), sizeof(a))
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back
#define ve vector

#define ndbg(x) 
//cout << #x << " = " << x << " ";
#define nldbg(x) 
//cout << #x << " = " << x << endl;

const int MAXN = 3000;
double prob[MAXN][MAXN];

int getMinStonesCount(int X, int Y, int N) {
	int step = (abs(X) + abs(Y)) / 2 + 1;
	
	if(X == 0) return (2 * step - 1) * step;

	step--;
	int x = step * 2;

	int currentStones = (2 * step - 1) * step;

	if(X < 0) {
		return currentStones + (x + X + 1);
	} else {
		return currentStones + (x - X + 1);
	} 
}

int getMaxStonesCount(int X, int Y, int N) {
	int step = (abs(X) + abs(Y)) / 2 + 1;
	
	if(X == 0) return (2 * step - 1) * step;

	step--;
	int x = step * 2;

	int currentStones = (2 * step - 1) * step;

	if(X < 0) {
		return currentStones + x + (x + X + 1);
	} else {
		return currentStones + x + (x - X + 1);
	} 
}

double solve() {
	int N, X, Y;
	cin >> N >> X >> Y;

	int minStones = getMinStonesCount(X, Y, N);
	int maxStones = getMaxStonesCount(X, Y, N);

	nldbg(minStones);
	nldbg(maxStones);

	if(minStones > N) return 0;
	if(maxStones <= N) return 1;

	if(X < 0) X = -X;

	int step = (X + Y) / 2;
	int len = 4 * step + 1;
	int pos = step * 2 - X + 1;

	ndbg(len); nldbg(pos);

	int cnt = (2 * step - 1) * step;
	N -= cnt;

	assert(N > 0);
	assert(N < MAXN);

	double ans = 0;

	REP(stones, 0, N + 1) REP(left, 0, N + 1) prob[stones][left] = 0;
	prob[0][0] = 1.0;

	REP(stones, 0, N) {
		REP(left, 0, stones + 1) {
			if(left * 2 + 1 > len) break;
			int right = stones - left;
			if(right * 2 + 1 > len) continue;
			double p = prob[stones][left];
			
			double mult = 1;
			if(left + 1 <= len / 2 && right + 1 <= len / 2)
				mult = 2;

			if(left + 1 <= len / 2) prob[stones + 1][left + 1] += p / mult;
			if(right + 1 <= len / 2) prob[stones + 1][left] += p / mult;
		}
	}
	REP(k, 0, pos) {
		ndbg(k); nldbg(prob[N][k]);
		ans += prob[N][k];
	}

	nldbg(ans);

	assert(ans < 1);

	return 1 - ans;
}

int main() {
#ifdef shindo
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

//	init();

	int tests;
	cin >> tests;
	REP(t, 0, tests) {
		double ans = solve();
		printf("Case #%d: %.10lf\n", t + 1, ans);
	}
		
#ifdef shindo
//	printf("---------------\n\n%lf\n", clock() * 1e-3);
#endif

	return 0;
}           