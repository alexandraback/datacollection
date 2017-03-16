#include <iostream>
#include <cstdio>
#include <fstream>

#include <vector>
#include <list>
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

bool doit(int c) {
	list<char> lst;
	int cc = c;
	while (true) {
		//cerr << (char)(c + 'a') << endl;
		//used[c] = true;
		if (used[c])
			return false;
		used[c] = true;
		lst.push_front(c + 'a');
		int z = le[c];
		if (z == -1)
			break;
		else
			c = f[z] - 'a';
	}
	//cerr << 100 << endl;
	c = cc;
	used[c] = false;
	while (true) {
		//used[c] = true;
		if (used[c])
			return false;
		used[c] = true;		
		lst.pb(c + 'a');
		int z = lb[c];
		if (z == -1)
			break;
		else
			c = l[z] - 'a';
	}
	string s;
	for (list<char>::iterator it = lst.begin(); it != lst.end(); it++)
		s += *it;
	vector<bool> res = operate(s);
	return !res.empty();
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
		
	lt.clear();
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
				//cerr << i << endl;
				if (!doit(i))
					return 0;
				groups++;
			}
		}
	}

	all *= factorial(groups);
	all %= MOD;
	return (int)all;
}

int main() {
	freopen("traincars.in", "r", stdin);
	freopen("traincars.out", "w", stdout);  
	cin >> T;
	fr(test, T) {		
		int ans = solve();
		printf("Case #%d: %d\n", test + 1, ans);
		//cerr << test + 1 << " " << ans << endl;
	}
}
        