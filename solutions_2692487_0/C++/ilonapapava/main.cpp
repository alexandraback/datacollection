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
const int INF = (int)1e9+10;

ll t, a[N], n, value;

class node {
public:
	ll val, ind, ans;
	node () {}
	node (ll _val, ll _ind, ll _ans) {
		val = _val;
		ind = _ind;
		ans = _ans;
	}
};

ll solve() {
	sort(a, a + n);
	int fir = -1;
	for (int i = 0; i < n; i++) {
		if (value > a[i]) {
			value += a[i];
		} else {
			fir = i;
			break;
		}
	}
	if (fir == -1) return 0;
	queue <node> q;
	q.push(node(value, fir, 0));
	ll mini = (ll)(INF);
	while (!q.empty()) {
		node c = q.front();
		q.pop();
		if (c.ind == n) {
			mini = min(mini, c.ans);
			continue;
		}
		if (c.val > a[c.ind]) {
			q.push(node(c.val + a[c.ind], c.ind + 1, c.ans));
			continue;
		}
		q.push(node(c.val, c.ind + 1, c.ans + 1));
		ll value = c.val + c.val - 1;
		if (c.val == 1)
			continue;
		if (value > a[c.ind]) {
			value += a[c.ind];
			q.push(node(value, c.ind + 1, c.ans + 1));
		} else {
			q.push(node(value, c.ind, c.ans + 1));
		}
	}
	return mini;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
    cout.flags(ios::fixed);
    cout.precision(2);
	cin >> t;
	for (int yy = 0; yy < t; yy++) {
		cin >> value >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << "Case #" << yy + 1 << ": " << solve() << '\n';
	}
    return 0;
}



