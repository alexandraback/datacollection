#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:133217728")
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); --i)
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define pi acos(-1.0)

const int MOD = 1000000007;
const int INF = 1000000007;

int d[1010];
int m[1010];
int h[1010];
int n;

long long solve()
{
	if (n == 1) return 0;
	
	long long f = d[0];
	long long s = d[1];

	long long m1 = m[0];
	long long m2 = m[1];

	long long t1 = (360 - f)*m1;
	long long t2 = (360 - s)*m2;

	if (t1 > t2)
	{
		swap(t1, t2);
		swap(m1, m2);
		swap(s, f);
	}

	if (m1 < m2 && t1+m1*360<=t2)
	{
		return 1;
	}

	return 0;
}

int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;

	FOR(T, 0, t)
	{
		cin >> n;
		FOR(i, 0, n)
			cin >> d[i] >> h[i] >> m[i];
		cout << "Case #" << T + 1 << ": " << solve() << endl;
	}

	return 0;
}