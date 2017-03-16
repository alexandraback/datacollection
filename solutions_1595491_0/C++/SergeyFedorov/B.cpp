#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int t[20][50][20], dp[1000][1000];
int sc[1000];

int solve(){
	int n, s, p;
	cin >> n >> s >> p;
	forn(i, n)
		cin >> sc[i];
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= s; j ++){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if (t[p][sc[i]][0] || t[p][sc[i]][1])
				dp[i+1][j] = max(dp[i+1][j], dp[i][j] + 1);
			if (t[p][sc[i]][2])
				dp[i+1][j + 1] = max(dp[i+1][j + 1], dp[i][j] + 1);
		}
	return dp[n][s];
}

int main ()
{
	for (int i = 0; i <= 10; i ++)
		for (int j = i; j <= 10; j ++)
			for (int k = j; k <= 10; k ++)
				t[k][i + j + k][k - i] ++;
	
	for (int i = 10; i >= 0; i --)
		for (int j = 0; j <= 30; j ++)
			for (int w = 0; w <= 10; w ++)
				if (t[i+1][j][w])
					t[i][j][w] = 1;

	int tst;
	cin >> tst;
	forn(i, tst)
		printf("Case #%d: %d\n", i + 1, solve());

	
	return 0;
}
