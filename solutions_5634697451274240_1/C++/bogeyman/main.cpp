#include <vector>
#include <stack>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <functional>
#include <set>
#include <cstring>
#include <queue>
#include <stdlib.h>
#include <time.h>
#define all(o) (o).begin(), (o).end()
#define mp(x, y) make_pair(x, y)
//#define x first
//#define y second
//#define pt pair <double, double>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int S = int(2e5) + 105;
const int INF = int(1e9) + 7;


int t;
string s;

int solve(string s)
{
	int res = 0, n = int(s.size());
	for(int i = 1; i < n; i++)
		if(s[i] != s[i - 1])
			res++;
	if(s.back() == '-')
		res++;
	return res;
}


int main()
{
	freopen("/Users/user/Downloads/B-large.in", "r", stdin);
	freopen("key.out", "w", stdout);
	cin >> t;
	for(int q = 0; q < t; q++)
	{
		cin >> s;
		printf("Case #%d: %d\n", q + 1, solve(s));
	}
	
	return 0;
}