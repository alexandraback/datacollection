#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <bitset>

#define sqr(x) ((x) * (x))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define y0 ywuerosdfhgjkls
#define y1 hdsfjkhgjlsdfhgsdf
#define j1 j924
#define j0 j2834
#define sqrt(x) (sqrt(abs(x)))
#define re return
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = ((n) - 1); i >= 0; i--)
#define fill(a, x) memset(a, x, sizeof(a))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef double D;
typedef vector <string> vs;

template <class T> inline T abs(T a) {
	return a > 0 ? a : -a;
}

int n;
int m;

bool Wins(vs s, char who) {
	rep(i, 4) {
		bool kpyto = true;
		rep(j, 4)
			if (s[i][j] != who && s[i][j] != 'T')
				kpyto = false;
		if (kpyto)
			re true;
		kpyto = true;
		rep(j, 4)
			if (s[j][i] != who && s[i][j] != 'T')
				kpyto = false;
		if (kpyto)
			re true;
	}
	bool kpyto = true;
	rep(i, 4)
		if (s[i][i] != who && s[i][i] != 'T')
			kpyto = false;
	if (kpyto)
		re true;
	kpyto = true;
	rep(i, 4)
		if (s[i][3 - i] != who && s[i][3 - i] != 'T')
			kpyto = false;
	if (kpyto)
		re true;
	re false;
}

bool Completed(vs s) {
	rep(i, 4)
		rep(j, 4)
			if (s[i][j] == '.')
				re false;
	re true;
}

int main() {
	cin >> n;
	rep(i, n) {
		vector <string> s;
		s.resize(4);
		rep(j, 4) {
			cin >> s[j];
		}
		if (Wins(s, 'O'))
			cout << "Case #" << i + 1 << ": O won" << endl;
		else if (Wins(s, 'X'))
			cout << "Case #" << i + 1 << ": X won" << endl;
		else if (!Completed(s))
			cout << "Case #" << i + 1 << ": Game has not completed" << endl;
		else
			cout << "Case #" << i + 1 << ": Draw" << endl;
	}
	return 0;
}
