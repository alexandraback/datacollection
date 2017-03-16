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
	mindif = INF;
	minc = INF;
	minj = INF;
	rec();
	cout << sc << " " << sj << endl;
}

void fillnum(string &str, int num)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '?')
		{
			str[i] = num + '0';
		}
	}
}

void updscore()
{
	ll c = 0;
	for (int i = 0; i < coder.size(); ++i)
	{
		c = c * 10 + coder[i] - '0';
	}

	ll j = 0;
	for (int i = 0; i < jammer.size(); ++i)
	{
		j = j * 10 + jammer[i] - '0';
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

void coolrec(int pos)
{
	int sz = coder.size();
	while (pos < sz && coder[pos] == jammer[pos] && coder[pos] != '?')
	{
		++pos;
	}

	if (pos == sz)
	{
		updscore();
		return;
	}
	

	if (coder[pos] == '?' && jammer[pos] == '?')
	{
		// equals
		coder[pos] = '0';
		jammer[pos] = '0';
		coolrec(pos + 1);
		coder[pos] = '?';
		jammer[pos] = '?';

		string tcoder = coder;
		string tjammer = jammer;

		// coder bigger
		coder[pos] = '1';
		jammer[pos] = '0';
		fillnum(coder, 0);
		fillnum(jammer, 9);
		updscore();

		coder = tcoder;
		jammer = tjammer;

		// jammer bigger
		jammer[pos] = '1';
		coder[pos] = '0';
		fillnum(jammer, 0);
		fillnum(coder, 9);
		updscore();

		coder = tcoder;
		jammer = tjammer;
	}
	else if (coder[pos] == '?')
	{
		// equals
		coder[pos] = jammer[pos];
		coolrec(pos + 1);
		coder[pos] = '?';

		string tcoder = coder;
		string tjammer = jammer;

		// coder bigger
		if (jammer[pos] != '9')
		{
			coder[pos] = jammer[pos] + 1;
			fillnum(coder, 0);
			fillnum(jammer, 9);
			updscore();

			coder = tcoder;
			jammer = tjammer;
		}

		// coder lesser
		if (jammer[pos] != '0')
		{
			coder[pos] = jammer[pos] - 1;
			fillnum(coder, 9);
			fillnum(jammer, 0);
			updscore();

			coder = tcoder;
			jammer = tjammer;
		}
	}
	else if (jammer[pos] == '?')
	{
		// equals
		jammer[pos] = coder[pos];
		coolrec(pos + 1);
		jammer[pos] = '?';

		string tcoder = coder;
		string tjammer = jammer;

		// jammer bigger
		if (coder[pos] != '9')
		{
			jammer[pos] = coder[pos] + 1;
			fillnum(jammer, 0);
			fillnum(coder, 9);
			updscore();

			coder = tcoder;
			jammer = tjammer;
		}

		// jammer lesser
		if (jammer[pos] != '0')
		{
			jammer[pos] = coder[pos] - 1;
			fillnum(jammer, 9);
			fillnum(coder, 0);
			updscore();

			coder = tcoder;
			jammer = tjammer;
		}
	}
	else
	{
		string tcoder = coder;
		string tjammer = jammer;

		if (coder[pos] > jammer[pos])
		{
			fillnum(coder, 0);
			fillnum(jammer, 9);
		}
		else
		{
			fillnum(jammer, 0);
			fillnum(coder, 9);
		}

		updscore();
		coder = tcoder;
		jammer = tjammer;
	}
}

void solve()
{
	mindif = INF;
	minc = INF;
	minj = INF;
	coolrec(0);
	cout << sc << " " << sj << endl;
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

		cin >> coder >> jammer;
		solve();
	}

	return 0;
}