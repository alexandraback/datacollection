#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <cassert>
#include <ctime>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define pr(x) printf("%d ", x)
#define nl() printf("\n")
#define mp(x, y) make_pair(x, y)
#define forn(i, a, b) for(int i=a; i<b; ++i)
#define ford(i, a, b) for(int i=b-1; i>=a; --i)
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9;

string flip(string s, int cnt)
{
	string t = s.substr(0, cnt);
	reverse(t.begin(), t.end());
	for (int i = 0; i < cnt; ++i)
	{
		if (t[i] == '-') t[i] = '+';
		else t[i] = '-';
	}
	return t + s.substr(cnt);
}

string generate()
{
	int n = rand() % 100;
	string s(n, '-');
	for (int i = 0; i < n; ++i)
		if (rand() & 1)
			s[i] = '+';
	return s;
}

void solve()
{
	int t;
	cin >> t;
	forn(tt, 0, t)
	{
		string s;
		cin >> s;
		int steps = 0;

		int right = s.size() - 1;
		while (right >= 0 && s[right] == '+') right--;
		while (right >= 0)
		{
			if (s[0] != '-')
			{
				int left = 0;
				while (s[left] == '+') left++;
				s = flip(s, left);
				steps++;
			}
			s = flip(s, right + 1);
			steps++;
			while (right >= 0 && s[right] == '+') right--;
		}

		cout << "Case #" << tt + 1 << ": " << steps << endl;
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
	solve();

	return 0;
}