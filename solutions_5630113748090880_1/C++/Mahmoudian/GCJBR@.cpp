//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
ofstream fout("a.out");
#define cout fout
const int N = 2505;

int read() { int x; cin >> x; return x; }

int cnt[N];


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc = read();
	rep(t, tc) {
		cout << "Case #" << t + 1 << ": ";
		memset(cnt, 0, sizeof cnt);
		int n = read();
		rep(i, n + n - 1)
			rep(j, n) {
				int x = read();
				cnt[x]++;
			}
		rep(i, N)
			if (cnt[i] & 1)
				cout << i << ' ';
		cout << '\n';
	}
}













