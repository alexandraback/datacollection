#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <cstring>
#include <cmath>
#include <queue>
#include <functional>
#include <cstdio>
#include <cassert>
#include <stack>
#include <unordered_set>

#define mp make_pair
#define mt(x,y,z) mp((x), mp((y), (z)))
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

// globals starts here

const ll INF = 4e18;

ll mindif = INF;
ll minc = INF;
ll minj = INF;

string sc;
string sj;

string coder, jammer;

void rec()
{
	ll c = 0;
	for (int i = 0; i < coder.size(); ++i)
	{
		if (coder[i] == '?')
		{
			for (int x = 0; x <= 9; ++x)
			{
				coder[i] = x + '0';
				rec();
				coder[i] = '?';
			}
			return;
		}
		else
		{
			c = c * 10 + coder[i] - '0';
		}
	}

	ll j = 0;
	for (int i = 0; i < jammer.size(); ++i)
	{
		if (jammer[i] == '?')
		{
			for (int x = 0; x <= 9; ++x)
			{
				jammer[i] = x + '0';
				rec();
				jammer[i] = '?';
			}
			return;
		}
		else
		{
			j = j * 10 + jammer[i] - '0';
		}
	}

	ll dif = abs(c - j);
	if (dif < mindif)
	{
		mindif = dif;
		minc = c;
		sc = coder;
		minj = j;
		sj = jammer;
	}
	else if (dif == mindif)
	{
		if (c < minc)
		{
			minc = c;
			sc = coder;
			minj = j;
			sj = jammer;
		}
		else if (c == minc)
		{
			if (j < minj)
			{
				j = minj;
				sj = jammer;
			}
		}
	}
}

void solvestupid()
{
	cin >> coder >> jammer;
	mindif = INF;
	minc = INF;
	minj = INF;
	rec();
	cout << sc << " " << sj << endl;
}

void solve()
{
	string coder, jammer;
	cin >> coder >> jammer;

}

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#elif defined(CONTEST)
	freopen(CONTEST ".in", "r", stdin);
	freopen(CONTEST ".out", "w", stdout);
#endif

	cin.sync_with_stdio(false);
	int tests;
	cin >> tests;

	for (int tc = 1; tc <= tests; ++tc)
	{
		cout << "Case #" << tc << ": ";
		solvestupid();
	}

	return 0;
}