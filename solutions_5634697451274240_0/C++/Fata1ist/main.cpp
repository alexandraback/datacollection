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
const int MAXN = 10;

int T;
string s;
int ans;

int main() {

	cin >> T;
	forn(tt, T) {
		cin >> s;
		printf("Case #%d: ", tt + 1);

		ans = 0;
		forn(i, s.size() - 1)
			if (s[i] != s[i + 1])
				ans++;
		if (s.back() == '-')
			ans++;

		cout << ans << '\n';		
	}
		
	return 0;
}                  