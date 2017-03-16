#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <set>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <complex>
#include <hash_map>
#include <hash_set>

using namespace std;

#define pb push_back
#define pob pop_back
#define rs resize
#define as assign
#define lwb lower_bound
#define upb upper_bound
#define mp make_pair
#define x first
#define y second

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <string> vs;
typedef vector <char> vc;
typedef vector <vc> vvc;
typedef vector <vvi> vvvi;
typedef vector <vvl> vvvl;
typedef vector <vvb> vvvb;
typedef double db;
typedef long double ldb;
typedef vector <db> vdb;
typedef vector <ldb> vldb;
typedef pair <int, int> ii;
typedef pair <ll, ll> lll;
typedef pair <int, ll> il;
typedef pair <ll, int> li;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef vector <lll> vll;
typedef vector <vll> vvll;
typedef set <int> si;
typedef set <ii> sii;
typedef vector <si> vsi;
typedef map <string, int> msi;
typedef map <char, int> mci;
typedef queue <int> qi;
typedef deque <int> di;
typedef stack <int> sti;

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		db c, f, x, ans = 0.0;
		scanf("%lf %lf %lf", &c, &f, &x);
		db v = 2;
		for (; ;)
		{
			if (x / v <= c / v + x / (v + f))
			{
				ans += x / v;
				break;
			}
			else
			{
				ans += c / v;
				v += f;
			}
		}
		printf("Case #%d: %.8lf\n", i, ans);
	}
	return 0;
}