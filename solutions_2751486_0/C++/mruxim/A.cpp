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

const int maxl = 1000000 + 100;

char s[maxl];
int a[maxl];
int l, n;


int main()
{
	ios::sync_with_stdio (false);

	int ttt; cin >> ttt;
	for (int ttc = 1; ttc <= ttt; ttc++)
	{
		cin >> s >> n;
		l = strlen (s);
		rep (i, l) if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') s[i] = 0; else s[i] = 1;
		rep (i, l) if (s[i]) a[i] = 1 + (i ? a[i-1] : 0); else a[i] = 0;
		ll ans = 0;
		int pos = -9999999;
		rep (i, l)
		{
			if (a[i] >= n) pos = i-n+1;
			ans += max(0,pos+1);
		}
		cout << "Case #" << ttc << ": " << ans << endl;
	}

	{ int _; cin >> _; return 0; }
}
