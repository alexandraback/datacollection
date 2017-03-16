#include <iostream>
#include <cstdio>
#include <fstream>

#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <cstring>

#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <memory.h>
using namespace std;

#define fr(i, n) for (int i = 0; i < (int)(n); i++)
#define fb(i, n) for (int i = n - 1; i >= 0; i--)
#define all(a) (a).begin(), (a).end()
#define _(a, b) memset(a, b, sizeof(a))
#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

inline int ni() { int a; scanf("%d", &a); return a; }
inline double nf() { double a; scanf("%lf", &a); return a; }
template <class T> void out(T a, T b) { bool first = true; for (T i = a; i != b; i++) { if (!first) printf(" "); first = false; cout << *i; } puts(""); }
template <class T> void outl(T a, T b) { for (T i = a; i != b; i++) cout << *i << "\n"; } 

const int MOD = 1000000009;

ll factorial(ll n) {
	ll ans = 1;
	fr(i, n) {
		ans *= i + 1;
		ans %= MOD;
	}
	return ans;
}

int T;
int N;
vs v;
vector<char> f, l;
vector<vector<bool> > msk;
vector<vi> lt;
vi lb, le;

vector<bool> used;

vector<bool> operate(string s) {
	vector<bool> c(26, false);
	fr(i, sz(s)) {
		int num = s[i] - 'a';
		if (c[num] && s[i - 1] != s[i]) {
			c.clear();
			return c;
		}
		c[num] = true;
	}
	char ff = *s.begin();
	char ll = *s.rbegin();
	c[ff - 'a'] = c[ll - 'a'] = false;
	return c;	
}

int solve() {
	cin >> N;
	v.clear();
	f.clear();
	l.clear();
	msk.clear();
	v.resize(N);
	f.resize(N);
	l.resize(N);
	msk.resize(N);
	fr(i, N) {
		cin >> v[i];
		f[i] = *v[i].begin();
		l[i] = *v[i].rbegin();
	}
	fr(i, N) {
		msk[i] = operate(v[i]);
		if (msk[i].empty())
			return 0;
	}
	fr(i, N)
		for (int j = 0; j < N; j++)
			if (i == j)
				continue;
			else
				fr(k, 26)
					if ((msk[i][k] == true && msk[j][k] == true) || (msk[i][k] == true && (f[j] - 'a' == k || l[j] - 'a' == k)))
						return 0;
	

	vector<int> num(N);
	fr(i, N)
		num[i] = i;
	int ans = 0;
	do {
		string s;
		fr(i, N) {
			s += f[num[i]];
			s += l[num[i]];
		}
		vector<bool> res = operate(s);
		if (!res.empty())
			ans++;
	} while (next_permutation(all(num)));
	return ans;
	/*lt.clear();
	lb.clear();
	le.clear();
	lt.resize(26);
	lb.assign(26, -1);
	le.assign(26, -1);
	fr(i, N) {
		if (f[i] == l[i])
			lt[f[i] - 'a'].pb(i);
		else {
			if (lb[f[i] - 'a'] != -1)
				return 0;
			else
				lb[f[i] - 'a'] = i;

			if (le[l[i] - 'a'] != -1)
				return 0;
			else
				le[l[i] - 'a'] = i;
		}

	}					

	ll ans = 0;
	ll all = 1;
	fr(i, 26) {
		all *= factorial(sz(lt[i]));
		all %= MOD;		
	} 		

	used.clear();
	used.assign(26, false);
	ll groups = 0;
	fr(i, 26) {
		if (!used[i]) {
			if (sz(lt[i]) || lb[i] != -1 || le[i] != -1) {
				doit(i);
				groups++;
			}
		}
	}

	all *= factorial(groups);
	all %= MOD;
	return (int)all;*/
}

int main() {
	freopen("traincars.in", "r", stdin);
	freopen("traincars.out", "w", stdout);  
	cin >> T;
	fr(test, T)
		printf("Case #%d: %d\n", test + 1, solve());
}
        