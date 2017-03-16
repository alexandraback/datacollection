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
string s;

string dzen(int l, int r)
{
	if (l > r)
		return "";
	string o = "", o1 = "";
	int x = l, tl = l, tr = l;
	fi(l, r)
	{
		if (s[i] > s[x])
		{
			x = i;
			tl = i;
		}
		if (s[i] == s[x])
			tr = i;
	}
	fi(tl, tr)
	{
		if (s[i] == s[x])
			o += s[i];
	}
	fi(tl, r)
	{
		if (s[i] != s[x])
			o1 += s[i];
	}
	return o + dzen(l, tl - 1) + o1;
}

int main()
{
	fin("t.in");
	fout("t.out");
	sync;
	cin >> T;
	ff(numT, 1, T)
	{
		cin >> s;
		cout << "Case #" << numT << ": " << dzen(0, (int)s.size() - 1) << endl; 
	}
	return 0;
}
