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

int x, y;

int main()
{
	ios::sync_with_stdio (false);

	int ttt; cin >> ttt;
	for (int ttc = 1; ttc <= ttt; ttc++)
	{
		cin >> x >> y;
		string str;
		while (y > 0) str += "SN", y--;
		while (y < 0) str += "NS", y++;
		while (x > 0) str += "WE", x--;
		while (x < 0) str += "EW", x++;
		cout << "Case #" << ttc << ": " << str << endl;
	}

	{ int _; cin >> _; return 0; }
}
