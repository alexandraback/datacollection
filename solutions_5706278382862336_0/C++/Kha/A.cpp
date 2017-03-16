#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <algorithm>
#include <iomanip>
#include <complex>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define rep(i,s,e) for (int i=(s);i<(e);++i)
#define pb push_back
#define mk make_pair
#define fst first
#define snd second
#define all(x) (x).begin(),(x).end()
#define clr(x,y) memset(x,y,sizeof x)
#define contains(x,y) (x).find(y)!=(x).end()
#define endl "\n"

int dx[]={0,0,1,-1,1,-1,1,-1}, dy[]={-1,1,0,0,1,-1,-1,1};
const int mod = 1e9+7;

ll gcd(ll u, ll v) {
    while ( v != 0) {
        ll r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main() {
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(16);

	int t;
	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cout << "Case #" << ti << ": ";
		char c; ll n, d;
		cin >> n >> c >> d;
		ll g = gcd(d, n);
		n /= g;
		d /= g;
		if ((1ll<<40) % d)
			cout << "impossible";
		else {
			int i;
			for (i = 1; i <= 40; i++) {
				d >>= 1;
				if (n >= d) break;
			}
			cout << i;
		}
		cout << endl;
	}
}
