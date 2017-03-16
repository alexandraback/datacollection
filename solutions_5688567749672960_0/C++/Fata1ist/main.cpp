#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 111;

int t;
ll n, m, ans, cur, _10[MAXN];
int curdec, maxdec;
string s, ss;
int len;
bool f;

int main() {

	_10[0] = 1;
	for (int i = 1; i <= 16; i++)
		_10[i] = _10[i - 1] * 10;
		
	cin >> t;
	forn(ttt, t) {
		cin >> s;
		len = s.size();
		
		//cerr << len << '\n';
		
		n = 0;
		for (int i = 0; i < len; i++)
			n = n * 10 + s[i] - '0';
		
		m = n;
		f = 1;
		while (m % 10 == 0)
			m /= 10;
		if (n < 10) {
			ans = n;
			f = 0;
		} else if (m == 1) {
			ans = 1;
			len--;	
		} else {
			cur = 0;

			m = 0;
			for (int i = 1; i < len; i++) {
				m = m * 10 + s[i] - '0';
			}
			
			cur = m + 1 + _10[len - 1] * (s[0] - '1');
			ans = cur;
			
			curdec = (s[len - 1] == '0' ? 9 : s[len - 1] - '1');
			maxdec = min(_10[(len + 1) / 2] + 29, cur);
			
			cerr << maxdec << '\n';
			
			while (curdec < maxdec) {
				m = n - curdec;
				assert(m % 10 == 1);
				if (m % 10 == 0) {
					curdec++;
					continue;
				}					
				ss = "";
				while (m > 0) {
					ss += '0' + (m % 10);
					m /= 10;	
				}

				ll add = 0;								
				for (int i = 1; i < len; i++) {
					add = add * 10 + ss[i] - '0';
				}
				
				//ll val = curdec + 1 + add + _10[len - 1] * (ss[0] - '1') ;
				//cout << ss << ' ' << val << '\n';
				 
				ans = min(ans, curdec + 2 + add + _10[len - 1] * (ss[0] - '1'));
				
				curdec += 10;	
				//curdec++;
			}

			len--;			
		}
		
		for (int i = len; i >= 2; i--) {
			if ((i & 1) == 0) {
				ans += _10[i / 2] - 2; 
				ans++;
				ans += _10[i / 2];
			} else {
				ans += _10[(i + 1) / 2] - 2; 
				ans++;
				ans += _10[i / 2];
			}
		}

		if (f)
			ans += 9;
						
		printf("Case #%d: ", ttt + 1);
		cout << ans << '\n';
		cerr << ttt << '\n';			
	}
		    
	return 0;
}