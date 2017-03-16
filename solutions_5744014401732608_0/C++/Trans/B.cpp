//This is getting accepted!
#include<bits/stdc++.h>

using namespace std;

#define FI first
#define SE second
#define pb push_back
#define mp make_pair
#define ll long long
#define sz(a) ((int)(a).size())
#define __builtin_popcount __builtin_popcounll

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const double EPS = 1e-8;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const double foo = 1e30;

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcounll(s);}

int ans, T, tc, a[100][100], B, M, n;

void go(int u) {
	if (u == n) {
		ans++;
		return;
	}
	for (int i=u+1; i<=n; i++) {
		if (ans == M) break;
		go(i);
		a[u][i] = 1;
		if (ans == M) break;
	}
}

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("inp.txt", "r", stdin);
//    freopen("out1.txt", "w", stdout);
//#endif

	cin >> T;
	while (T--) {
		cin >> B >> M;
		n = B;
		ans = 0;
		cout << "Case #" << ++tc << ": ";
		for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) a[i][j] = 0;
		go(1);
		if (ans < M) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << "POSSIBLE" << endl;
//			if (ans != M ) cout << "FAK" << endl;
			for (int i=1; i<=n; i++) {
				for (int j=1; j<=n; j++) cout << a[i][j];
				cout << endl;
			}
		}
	}
//	B = 4;
//	n = 4;
//	ans = 0;
//	go(1);
//	cout << ans << endl;

}

