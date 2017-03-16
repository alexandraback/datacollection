#pragma comment(linker, "/STACK:16777216")
#include <algorithm> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <ctime>
#include <cstring> 
#include <deque> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector> 

using namespace std; 

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

#define bublic public:
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define y0 y32479
#define y1 y95874

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-9;
const int N = (int)1e5+5;
const ll INF = (int)1e9+10;


ll T, R, t;

inline ll number(ll q) {
	return (q / 4ll) + 1;
}

inline ll get_sum(ll m) {
	ll ans = ((R + m * 4ll - 1) / 2ll) * (m - number(R) + 1);
	return ans;
}

inline bool ok(ll m) {
	ll sum = get_sum(m);
	return (sum <= t);
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
    cout.flags(ios::fixed);
    cout.precision(2);
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		cin >> R >> t;
		ll l = 1, r = INF;
		while (r - l > 1) {
			ll m = (l + r) / 2;
			if (2ll * m * R + (2ll * m - 1) * m <= t)
				l = m;
			else
				r = m;
		}
		cout << "Case #" << tt + 1 << ": " << l << '\n';
	}
    return 0;
}



