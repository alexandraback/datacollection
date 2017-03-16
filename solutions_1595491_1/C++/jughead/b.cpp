#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#define ll long long
#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define pii pair <int, int>
#define ff first
#define ss second
#define ldb long double
#define sqr(a) ((a) * (a))
#define nextLine() {int c = 0; while((c = getchar()) != 10 && c != EOF);}
#define addEdge(a, b) next[edges] = first[a]; first[a] = edges; end[edges] = a;
#define debug(a) cerr << #a << " = " << (a) << " ";
#define debugl(a) cerr << #a << " = " << (a) << "\n";
const ldb eps = 1e-9;
const ldb pi = fabsl(atan2l(0.0, -1.0));
const ll inf = 1 << 28;
using namespace std;
#define problem "b"

int n, S, p;
int t[123];

int surprise[31], notsurprise[31];

void init()
{
	memset(surprise, -1, sizeof surprise);
	memset(notsurprise, -1, sizeof notsurprise);
	for (int i = 0; i <= 10; i++)
	{
	 	for (int j = i; j <= 10; j++)
	 	{
	 		for (int k = j; k <= 10; k++)
	 		{
	 			if (k - i == 2)
	 				surprise[i + j + k] = max(surprise[i + j + k], k);
	 			else if (k - i < 2)
	 				notsurprise[i + j + k] = max(notsurprise[i + j + k], k);
	 		}
	 	}
	}
	for (int i = 0; i <= 30; i++)
	{
		cerr << surprise[i] << " ";
	}
	cerr << "\n";
	for (int i = 0; i <= 30; i++)
	{
		cerr << notsurprise[i] << " ";
	}
	cerr << "\n";
}

void load()
{
	cin >> n >> S >> p;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
	}
}
int dp[123][123];
int f(int i, int j)
{
	if (j < 0) return -inf;
	if (i == n)
	{
		if (j == 0)
			return 0;
		return -inf;
	}
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = -inf;
	if (surprise[t[i]] != -1 && f(i + 1, j - 1) > -inf)
		dp[i][j] = max(dp[i][j], f(i + 1, j - 1) + (surprise[t[i]] >= p));
	if (notsurprise[t[i]] != -1 && f(i + 1, j) > -inf)
		dp[i][j] = max(dp[i][j], f(i + 1, j) + (notsurprise[t[i]] >= p));
	return dp[i][j];
}

void solve(int test_number)
{
	cerr << "Case #" << test_number << "\n";
	memset(dp, -1, sizeof dp);
	cout << "Case #" << test_number << ": " << f(0, S) << "\n";
}

int main()
{
	freopen(problem ".in", "rt", stdin);
	freopen(problem ".out", "wt", stdout);
	init();
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		load();
		solve(i + 1);
	}
	return 0;
}

