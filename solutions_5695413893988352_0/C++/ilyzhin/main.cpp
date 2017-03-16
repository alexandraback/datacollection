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

vector<int> vars1, vars2;
string p1, p2;

void rec(int pos, string &p, vector<int> &vars, int val)
{
	if(pos==p.size())
	{
		vars.push_back(val);
		return;
	}
	if (p[pos] == '?')
		for (int i = 0; i <= 9; ++i)
			rec(pos + 1, p, vars, val * 10 + i);
	else rec(pos + 1, p, vars, val * 10 + (p[pos] - '0'));
}

string tostr(int x, int len)
{
	vector<int> digits;
	while(x>0)
	{
		digits.push_back(x % 10);
		x /= 10;
	}
	while (digits.size() < len)
		digits.push_back(0);
	string res = "";
	for (int i = len - 1; i >= 0; --i)
		res += char(digits[i] + '0');
	return res;
}

void solve()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt)
	{
		vars1.clear();
		vars2.clear();
		cin >> p1 >> p2;
		rec(0, p1, vars1, 0);
		rec(0, p2, vars2, 0);
		int bestC = 0, bestJ = 100000;
		for (int i = 0; i < vars1.size(); ++i)
			for (int j = 0; j < vars2.size(); ++j)
			{
				if(abs(vars1[i]-vars2[j]) < abs(bestC-bestJ))
				{
					bestC = vars1[i];
					bestJ = vars2[j];
				}
				else if(abs(vars1[i] - vars2[j]) == abs(bestC - bestJ) && vars1[i]<bestC)
				{
					bestC = vars1[i];
					bestJ = vars2[j];
				}
				else if(abs(vars1[i] - vars2[j]) == abs(bestC - bestJ) && vars1[i]==bestC && vars2[j]<bestJ)
				{
					bestC = vars1[i];
					bestJ = vars2[j];
				}
			}
		cout << "Case #" << tt << ":";
		cout << " " << tostr(bestC, p1.size()) << " " << tostr(bestJ, p2.size()) << endl;
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