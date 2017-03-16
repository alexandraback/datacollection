#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
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
typedef long double ld;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		int r, c, w;
		cin >> r >> c >> w;
		int ans = 0;
		for (int pos = 0; pos + w - 1 < c; ++pos) {
			//cerr << pos << endl;
			int hits = 0;
			vb u(c);
			int last = 0;
			for (int i = w - 1; i < c; i += w) {
				hits++;
				last = i;
				u[i] = 1;
				//cerr << i << ' ';
				if (i >= pos && i < pos + w) {
					break;
				}
			}
			int x = last;
			while (x < c - 1 && x < last + w - 1) {
				x++;
				hits++;
				//cerr << x << "x ";
				u[x] = 1;
				if (x >= pos && x < pos + w) {
					continue;
				} else {
					break;
				}
			}
			hits += last - pos;
			ans = max(ans, hits);
			//cerr << endl;
		}
		//cerr << endl;
		cout << "Case #" << test << ": ";
		cout << ans + (r - 1) * (c / w) << endl;
	}
}
