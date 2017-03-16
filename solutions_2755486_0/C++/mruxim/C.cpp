// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

struct attack {
	int d, w, e, s;
};

bool cmp (const attack &A, const attack &B) { return A.d < B.d; }

int N;
vector <attack> v;

int oh[10000000], *h = oh+5000000;

int solve()
{
	int res = 0;
	rep (i, sz(v))
	{
		int j = i;
		while (j < sz(v) && v[j].d == v[i].d)
		{
			attack a = v[j];
			bool win = false;
			for (int k = a.w; k < a.e; k++) if (h[k] < a.s) win = 1;
			if (win) res++;
//			cerr << "day = " << a.d << ", (" << a.w << ", " << a.e << "), str = " << a.s << " --> " << win << endl;
			j++;
			
		}
		j = i;
		while (j < sz(v) && v[j].d == v[i].d)
		{
			attack a = v[j];
			for (int k = a.w; k < a.e; k++) h[k] = max (h[k], a.s);
			j++;
		}
		i = j-1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio (false);

	int ttt; cin >> ttt;
	for (int ttc = 1; ttc <= ttt; ttc++)
	{
		cin >> N;
		v.clear();
		rep (i, N)
		{
			int d, n, w, e, s, dd, dp, ds;
			cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
			rep (i, n)
			{
				v.pb ((attack){d, w, e, s});
				d += dd;
				w += dp, e += dp;
				s += ds;
			}
		}
		sort (all(v), cmp);
		rep (i, 10000000) oh[i] = 0;
//		cerr << " $$ " << endl;
		cout << "Case #" << ttc << ": " << solve() << endl;
	}

	{ int _; cin >> _; return 0; }
}
