#pragma region predefinition
#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).size())
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, n) FOR(i, 1, (n))
#define rept(i, n) FOR(i, 0, (n)-1)
#define C(a) memset((a), 0, sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define rnd() ((rand() << 16) ^ rand())
#pragma endregion
//#define x first
//#define y second

int dp[111][111], scores[111], p;

int ok(int a, int b, int c) {
	return max(a, max(b, c)) - min(a, min(b, c)) <= 2;
}

bool suprising(int a, int b, int c) {
	return max(a, max(b, c)) - min(a, min(b, c)) > 1;
}

int f(int n, int l) {
	if (l < 0) return -INF;
	if (dp[n][l] >= 0) return dp[n][l]; 
	if (n == 0) {
		if (l == 0) return 0;
		else		return -INF;
	}
	int res = 0;
	rept(i, 11)
		rept(j, 11)
			rept(k, 11) 
				if (i + j + k == scores[n - 1] && ok(i, j, k)) {
					res = max(res, 
						f(n - 1, l - suprising(i, j, k)) 
					  + (max(i, max(j, k)) >= p));
				}

	return dp[n][l] = res;
}

int main()
{
	#ifndef ONLINE_JUDGE 
	freopen("input.txt","rt",stdin); freopen("output.txt","wt",stdout); 
	#endif
	int TC;
	scanf("%d", &TC);
	rept(tc, TC) {
		memset(dp, -1, sizeof(dp));
		int n, s;
		scanf("%d%d%d", &n, &s, &p);
		rept(i, n)
			scanf("%d", &scores[i]);
		printf("Case #%d: %d\n", tc + 1, f(n, s));
	}
	return 0;
}
