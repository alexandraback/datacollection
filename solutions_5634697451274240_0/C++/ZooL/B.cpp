#if 1
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }

// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> istream & operator >> (istream &, vector<T> &);
template<typename T> ostream & operator << (ostream &, const vector<T> &);

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "basket"

#include <unordered_set>

int getPos(const string &s, int last)
{
	while (last >= 0 && s[last] == '+')
		last--;
	return last;
}

void rev(string &s, int p)
{
	reverse(s.begin(), s.begin() + p);
	for (int i = 0; i < p; i++)
		s[i] = (s[i] == '+') ? '-' : '+';
}

void solve()
{
	int T;
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		cerr << q << endl;
		string s;
		cin >> s;
		int cnt = 0;
		int last = int(s.size()) - 1;

		while ((last = getPos(s, last)) != -1)
		{
			int add = 0;
			while (add < s.size() && s[add] == '+')
				add++;
			rev(s, add);
			if (add)
				cnt++;
			rev(s, last + 1);
			cnt++;
		}

		cout << "Case #" << q + 1 << ": " << cnt << endl;
	}
}

int main()
{

	//START
	//freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
	freopen("C:/Users/Vlad/Downloads/B-small-attempt1.in", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	solve();
	//END
	return 0;
}
/*******************************************
*******************************************/

template<typename T> istream & operator >> (istream &is, vector<T> &v)
{
	forn(i, v.size())
		is >> v[i];
	return is;
}
template<typename T> ostream & operator << (ostream &os, const vector<T> &v)
{
	forn(i, v.size())
		os << v[i];
	return os;
}
#endif