#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 1111;

int T;
int n, R;
string s, t, res, cur;
int lft[MAXN];
char maxC;

int main() {
	
	cin >> T;
	forn(tt, T) {
		printf("Case #%d: ", tt + 1);
		
		cin >> s;
		n = s.size();
		
		forn(i, n)
			lft[i] = 0;
		
		R = n;
		while (R != 0) {
			int pos = 0;
			forn(i, R)
				if (s[i] > s[pos])
					pos = i;

			for (int i = pos; i < R; i++)
				if (s[i] == s[pos])
					lft[i] = 1;
				else
					lft[i] = 0;
				
			R = pos;		
		}
		
		res = ""; 
		t = " ";
		forn(i, n)
			if (lft[i]) {
				t[0] = s[i];
				res = t + res;
			} else
				res += s[i];
				
		cout << res << '\n';		
	}
	
	return 0;
}                  