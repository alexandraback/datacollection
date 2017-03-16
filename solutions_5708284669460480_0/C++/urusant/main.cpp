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

int k, l, s;
string KEY, WORD;

int sum = 0, number = 0, maximum = 0;

void solve(string current) {
	if (sz(current) == s) {
		int x = 0;
		for (int i = 0; i + l - 1 < s; ++i) {
			if (current.substr(i, l) == WORD) {
				++x;
			}
		}
		sum += x;
		number++;
		maximum = max(maximum, x);
		return;
	}
	for (int i = 0; i < k; ++i) {
		solve(current + KEY[i]);
	}
}

int main() {
	cout.precision(10);
	cout << fixed;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> k >> l >> s >> KEY >> WORD;
		sum = 0, number = 0, maximum = 0;		
		solve("");
		cout << "Case #" << test << ": " << ((double)maximum * (double)number - sum) / (double)number << endl;
	}
}
