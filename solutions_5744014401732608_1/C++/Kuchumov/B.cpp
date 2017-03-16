#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define debug_flag true
#else
	#define debug_flag false
#endif

#define dbg(args...) { if (debug_flag) { _print(_split(#args, ',').begin(), args); cerr << endl; } else { void(0);} }

vector<string> _split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return v;
}

void _print(vector<string>::iterator) {}
template<typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
    string name = it -> substr((*it)[0] == ' ', it -> length());
    if (isalpha(name[0]))
	    cerr << name  << " = " << a << " ";
	else
	    cerr << name << " ";
	_print(++it, args...);
}

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42;
#endif

typedef long long int int64;

const int64 INF = (int64)1e18 + 1000;

int64 add(int64 a, int64 b)
{
	return min(a + b, INF);
}

const int N = 60;
int n;
int64 dp[N];
int mx[N][N];

int64 calc()
{
	fill(dp, dp + n, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (mx[i][j] == 1)
				dp[j] = add(dp[j], dp[i]);
	return dp[n - 1];
}

void solve(int test)
{
	int64 m;
	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			mx[i][j] = 0;
		for (int j = i + 1; j < n; j++)
			mx[i][j] = 1;
	}
	
	if (calc() < m)
	{
		printf("Case #%d: IMPOSSIBLE\n", test);
		return;
	}

	printf("Case #%d: POSSIBLE\n", test);
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			assert(mx[j][i] == 1);
			mx[j][i] = 0;
			if (calc() < m)
				mx[j][i] = 1;
		}
	}
	assert(calc() == m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d", mx[i][j]);
		printf("\n");
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

    int tests;
    scanf("%d", &tests);
    for (int test = 0; test < tests; test++)
    {
        dbg(test);
        solve(test + 1);
    }

	return 0;
}
