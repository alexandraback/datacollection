#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

using namespace std;

#define pb push_back
#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define clr(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll,ll> pll;

int A, B;

int bintodec(int a[32])
{
	int r = 0;
	int poww = 1;
	forn(i, 32)
	{
		r += a[i] * poww;
		poww = poww * 2;
	}
	return r;
}

int var(int i, int *k, int *a, int *b)
{
	//cout << "var start" << endl;
	int r = 0;
	if (k[i] == 1)
	{
		a[i] = 1;
		b[i] = 1;

		if (bintodec(a) < A && bintodec(b) < B)
		{
			if (i == 31)
			{
				r += 1;
			}
			else
			{
				r += var(i+1, k, a, b);
			}
		}
	}
	else
	{
		a[i] = 0;
		b[i] = 1;
		if (bintodec(a) < A && bintodec(b) < B)
		{
			if (i == 31)
			{
				r += 1;
			}
			else
			{
				r += var(i+1, k, a, b);
			}
		}

		a[i] = 1;
		b[i] = 0;
		if (bintodec(a) < A && bintodec(b) < B)
		{
			if (i == 31)
			{
				r +=  1;
			}
			else
			{
				r +=  var(i+1, k, a, b);
			}
		}
		
		a[i] = 0;
		b[i] = 0;
		if (bintodec(a) < A && bintodec(b) < B)
		{
			if (i == 31)
			{
				r +=  1;
			}
			else
			{
				r +=  var(i+1, k, a, b);
			}
		}
	}

	a[i] = 0;
	b[i] = 0;
	//cout << "var end" << endl;
	return r;
}

void solve(int t)
{
	int K;
	cin >> A >> B >> K;
	int result = 0;

	int a[32];
	int b[32];
	int k[32];
	forn(i,32)
	{
		a[i] = b[i] = 0;
	}

	forn(i, K)
	{
		if (i > max(A,B))
			break;

		forn(j, 32)
			k[j] = (i >> j) % 2;

		int x = var(0, k, a, b);
		result += x;
		//cout << "for k ="<< i << ", count - " << x << endl;
	}
	//for (
	
	cout << "Case #" << t << ": " << result / 3 << endl;
	return;
}

void main()
{
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);
	}
}