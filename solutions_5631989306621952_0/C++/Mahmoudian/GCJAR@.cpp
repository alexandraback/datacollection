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

int read() { int x; cin >> x; return x; }

const int N = 1e5 + 5;
char res[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc = read();
	rep(t, tc) {
		cout << "Case #" << t + 1 << ": ";
		string s;
		cin >> s;
		int n = (int) s.size();
		int ed = n, p = 0, pt = n;
		while (ed > 0) {
			char ch = 'A';
			int id = -1;
			rep(i, ed)
				if (s[i] >= ch)
					id = i, ch = s[i];
			res[p++] = ch;
			for (int i = ed - 1; i > id; --i)
				res[--pt] = s[i];
			ed = id;
		}
		rep(i, n)
			cout << res[i];
		cout << '\n';
	}
}













