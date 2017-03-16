// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000000000 + 7;
const int maxn = 100 + 10;

int n;
int f[maxn];
int c[maxn][maxn];
string s[maxn];
int out[26], inc[26], cnt[26];
int lck, hot, mark;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	f[0] = 1;
	fer(i, 1, maxn) f[i] = f[i-1] * (ll)i % mod;

	rep(i, maxn) {
		c[i][0] = c[i][i] = 1 % mod;
		fer(j, 1, i) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
	}

	int tt; cin >> tt;
	for(int tc = 1; tc <= tt; tc++) {
		cin >> n;
		rep(i, n) cin >> s[i];

		cout << "Case #" << tc << ": ";

		memset(out, -1, sizeof out);
		memset(inc, 0, sizeof inc);
		memset(cnt, 0, sizeof cnt);

		lck = hot = mark = 0;
		bool imp = false;

		rep(i, n) {
			if(count(all(s[i]), s[i].front()) == sz(s[i]))
				cnt[s[i].front() - 'a']++;
			else {
				if(out[s[i].front() - 'a'] != -1) imp = true;
				out[s[i].front() - 'a'] = s[i].back() - 'a';
				inc[s[i].back() - 'a']++;
				hot |= 1 << (s[i].front() - 'a');
				hot |= 1 << (s[i].back() - 'a');
				while(s[i][0] == s[i][1]) s[i] = s[i].substr(1);
				s[i] = s[i].substr(1);
				while(s[i].back() == s[i][sz(s[i])-2]) s[i] = s[i].substr(0, sz(s[i])-1);
				s[i] = s[i].substr(0, sz(s[i])-1);
				rep(j, sz(s[i])) if(j == 0 || s[i][j] != s[i][j-1]) {
					int id = s[i][j] - 'a';
					if(lck >> id & 1) imp = true;
					lck |= 1 << id;
				}
			}
		}

		rep(i, 26) if(cnt[i] && (lck >> i & 1)) imp = true;
		imp |= ((hot & lck) != 0);

		if(imp || *max_element(inc, inc+26) >= 2) {
			cout << 0 << endl;
			continue;
		}

		int pc = 0;
		rep(i, 26) if((hot >> i & 1) && inc[i] == 0) {
			int cur = i;
			mark |= 1 << cur;
			while(out[cur] != -1) cur = out[cur], mark |= 1 << cur;
			pc++;
		}

		rep(i, 26) if((hot >> i & 1) && !(mark >> i & 1)) {
			cout << 0 << endl;
			imp = true;
			break;
		}
		if(imp) continue;

		int ans = f[pc];
		rep(i, 26) {
			ans = ans * (ll)f[cnt[i]] % mod;
			if(!(hot >> i & 1) && cnt[i]) {
				ans = ans * (ll)(pc+1) % mod, pc++;
			}
		}

		cout << ans << endl;
	}

	{ return 0; }
}

