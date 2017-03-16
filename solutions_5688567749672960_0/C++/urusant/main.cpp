#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rs resize
#define mp make_pair
#define pi 3.1415926535897932384626433832795
#define sz(a) (int)(a).size()
#define Sort(a) sort((a).begin(), (a).end())
#define Reverse(a) reverse((a).begin(), (a).end())
#define sf scanf
#define pf printf
#define ms(a, x) memset((a), (x), sizeof(a))
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <vvb> vvvb;
typedef vector <vvvb> vvvvb;
typedef long long ll;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <vvl> vvvl;
typedef vector <vvvl> vvvvl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef pair <int, ll> il;
typedef vector <il> vil;
typedef vector <vil> vvil;
typedef pair <ll, int> li;
typedef vector <li> vli;
typedef vector <vli> vvli;
typedef set <int> si;
typedef set <li> sli;
typedef set <il> sil;
typedef vector <string> vs;
typedef vector <vs> vvs;
typedef vector <vvs> vvvs;
typedef map <char, int> mci;
typedef pair <ll, ll> pll;
typedef vector <pll> vll;
const int inf = (int)1e9;
ll reverse(ll n) {
	ll ans = 0;
	while (n > 0) {
		ans = ans * 10 + n % 10;
		n /= 10;
	}
	return ans;
}

int N = 1000000 + 1;
vi d(N, inf);

void solve() {
	d[1] = 1;
	queue <int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x < N && d[x + 1] > d[x] + 1) {
			d[x + 1] = d[x] + 1;
			q.push(x + 1);
		}
		if (reverse(x) < N && d[reverse(x)] > d[x] + 1) {
			d[reverse(x)] = d[x] + 1;
			q.push(reverse(x));
		}
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	solve();
	for (int test = 1; test <= T; ++test) {
		int n;
		cin >> n;
		cout << "Case #" << test << ": " << d[n] << endl;
	}
}