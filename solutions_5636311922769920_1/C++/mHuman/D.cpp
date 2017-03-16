#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define ins insert
#define er erase
#define bg begin()
#define ed end()
#define X first
#define Y second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define files(name) fin(name".in"); fout(name".out")
#define enter cout << "\n"
#define space cout << " "
#define endl "\n"
#define fi(st,n) for (int i = (st); i <= (n); i++)
#define fj(st,n) for (int j = (st); j <= (n); j++)
#define fk(st,n) for (int k = (st); k <= (n); k++)
#define fq(st,n) for (int q = (st); q <= (n); q++)
#define fw(st,n) for (int w = (st); w <= (n); w++)
#define ff(i, st, n) for (int (i) = (st); (i) <= (n); (i)++)
#define ei(st,n) for (int i = (st); i >= (n); i--)
#define ej(st,n) for (int j = (st); j >= (n); j--)
#define ek(st,n) for (int k = (st); k >= (n); k--)
#define ri(st,n) for (int i = (st); i < (n); i++)
#define rj(st,n) for (int j = (st); j < (n); j++)
#define rk(st,n) for (int k = (st); k < (n); k++)
#define rq(st,n) for (int q = (st); q < (n); q++)
#define rf(i, st, n) for (int (i) = (st); (i) < (n); (i)++)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define y1 dsklmlvmd

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = (ll) 1000000000000;
const dbl eps = (dbl) 1e-8;
const int mod = (int) 1000000007;
const int maxn = (int) 1e5 + 5;
//const dbl M_PI = (dbl)2 * (dbl)acos(0);

//cout<<fixed<<setprecision(10);
//srand(time(0))

int T;
ll k, c, s, st[111], x, y;

int main()
{
	fin("t.in");
	fout("t.out");
	sync;
	cin >> T;
	ff(numT, 1, T)
	{
		cin >> k >> c >> s;
		if (k / c + (k % c > 0) > s)
		{
			cout << "Case #" << numT << ": " << "IMPOSSIBLE" << endl;
			continue;
		}
		st[0] = 1;
		fi(1, c)
		{
			st[i] = st[i - 1] * k;
		}
		x = (ll)1;
		cout << "Case #" << numT << ": ";
		fi(1, k / c + (k % c > 0))
		{
			y = (ll)1;
			ej(c - 1, 0)
			{
				y += (ll)(x - 1) * st[j];
				x = min(x + 1, k);
			}
			cout << y << " ";
		}
		enter;
	}
	return 0;
}
