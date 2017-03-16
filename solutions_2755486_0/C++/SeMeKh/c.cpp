#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <valarray>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <complex>
#include <iomanip>
#include <cassert>
#include <bitset>

#define show(x) cerr << "# " << #x << " = " << (x) << endl

#define FR(i, a, b) for(__typeof(a) i = a; i != b; i++)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOREACH(i, t) FR(i, t.begin(), t.end())
#define SZ(x) ((int) (x).size())
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define X real()
#define Y imag()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef complex<double> point;

template<class T> ostream& operator << (ostream &o, const vector<T> &t)	
{
	o << "[" << SZ(t);
	int f = 0;
	FOREACH(i, t)
		o << (f++ ? ", " : ": ") << (*i);
	return o << "]";
}

template<class T1, class T2> ostream& operator << (ostream &o, const pair<T1, T2> &p)
{
	return o << "(" << p.F << ", " << p.S << ")";
}

const int MAXW = 210;
const int MAXN = 10 + 10;
const int MAXD = 676060 + 10;

int cd;
int _w[2*MAXW], _wn[2*MAXW];
int *ww = _w + MAXW;
int *wn = _wn + MAXW;

#define MAX(a, b) a = max(a, b)

struct tribe
{
	int d, n, w, e, s, dd, dp, ds;

	bool attack()
	{
		if(!n || cd < d || ((cd - d) % dd != 0))
			return false;
		bool suc = false;
		for(int i = w; i < e; i++)
		{
			MAX(wn[i], s);
			if(ww[i] < s)
				suc = true;
		}
//		show(pii(w, e));
//		show(suc);
		n--;
		w += dp;
		e += dp;
		s += ds;
		return suc;
	}
} t[MAXN];

int main()
{
	int TC;
	cin >> TC;
	FOR(T, TC)
	{
		memset(_w, 0, sizeof _w);
		memset(_wn, 0, sizeof _wn);
		cout << "Case #" << T + 1 << ": ";
		int N;
		cin >> N;
		FOR(i, N)
			cin >> t[i].d >> t[i].n >> t[i].w >> t[i].e >> t[i].s >> t[i].dd >> t[i].dp >> t[i].ds;

		int ans = 0;
		for(cd = 0; cd < MAXD; cd++)
		{
			FOR(j, N)
			{
				ans += t[j].attack();
			}

			for(int i = -MAXW + 1; i < MAXW; i++)
				MAX(ww[i], wn[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
