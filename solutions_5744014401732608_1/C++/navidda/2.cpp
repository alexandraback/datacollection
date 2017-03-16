#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second
#define Sz size()
#define mp make_pair
#define foreach(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define Say(x) cerr << #x << " = " << x << endl
#define For(i, n) for(int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vint;
typedef pair <int,int> pii;

const int M = 100 + 4, Inf = 1e9 + 10;

/////////////////////////////////////////////////////////////////////////

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n;
		ll m;
		cin >> n >> m;
		vector < vector <bool> > a;
		a.resize(n);
		for (int i = 0; i < n; i++)
			a[i].resize(n);
		for (int i = 0; i < n - 1; i++)
			for(int j = i + 1; j < n - 1; j++)
				a[i][j] = 1;
		for (int i = n - 2; i > 0; i --)
			if (m >= (1ll << (i - 1))) {
				a[i][n - 1] = 1;
				m -= (1ll << (i - 1));
			}
		if (m >= 1) {
			a[0][n - 1] = 1;
			m--;
		}
		if (m)
			cout << "Case #" << t << ": IMPOSSIBLE\n";
		else {
			cout << "Case #" << t << ": POSSIBLE\n";
			for (int i = 0; i < n; i ++, cout << endl)
				for (int j = 0; j < n; j++)
					cout << a[i][j];
		}
	}
	return 0;
}
