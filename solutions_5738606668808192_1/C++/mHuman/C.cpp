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

ll n, k, fl, st[111], o[11];
vector <ll> ans, pr;

int main()
{
	fin("t.in");
	fout("t.out");
	sync;
	cin >> n;
	cin >> n >> k;
	cout << "Case #1:" << endl;
	pr.pb(2);
	pr.pb(3);
	pr.pb(5);
	pr.pb(7);
	pr.pb(11);
	pr.pb(13);
	pr.pb(17);
	for (ll i = ((ll)1 << (n - 1)) + 1; i < ((ll)1 << n); i += (ll)2)
	{
		fl = 1;
		ans.clear();
		fj(2, 10)
		{
			clean(o);
			fq(0, 6)
				st[q] = 1;
			fw(0, n - 1)
			{
				fq(0, 6)
					o[q] = (o[q] + st[q] * ((i & (1 << w)) > 0)) % pr[q]; 
				fq(0, 6)
					st[q] = (st[q] * j) % pr[q];
			}
			fl = 0;
			fq(0, 6)
				if (o[q] == 0)
				{
					fl = 1;
					ans.pb(pr[q]);
					break;
				}
			if (!fl)
				break;
		}
		if (fl)
		{
			ej(n - 1, 0)
			{
				cout << (int)((i & (1 << j)) > 0); 
			}
			space;
			rj(0, ans.size())
				cout << ans[j] << " ";
			enter;
			k--;
			if (k == 0)
				return 0;
		}
	}
	return 0;
}
