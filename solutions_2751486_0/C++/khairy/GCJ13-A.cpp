#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <list>
#include <set>
#include <climits>
#include <map>
#include <stack>
#include <queue>
#include <complex>
#include <cmath>
#include <sstream>
#include <deque>
#include <utility>
#include <bitset>
#include <ext/hash_set>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo (1<<30)
#define M 1001
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define iter(it,s) for(it=s.begin();it!=s.end();it++)
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define mem(s,v) memset(s,v,sizeof(s))
#define ppc(x) __builtin_popcount((x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
map <char, int> m;
int n;
inline bool ok (string s) {
	int cnt = 0;
	FOR (i , 0 , sz(s)) {
		if (m[s[i]])
			cnt = 0;
		else
			cnt ++;
		if (cnt == n)
			return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	m['a'] = 1;
	m['e'] = 1;
	m['i'] = 1;
	m['o'] = 1;
	m['u'] = 1;
	int t;
	scanf ("%d", &t);
	FOR (cs, 1 , t + 1) {
		string s, tmp;
		int res = 0;
		cin >> s >> n;
		FOR (i , 0 , sz(s)) {
			FOR (j , 1 , sz(s) + 1) {
				if (i + j > sz(s))
					break;
				tmp = s.substr(i, j);
				res += ok(tmp);
			}
		}
		printf ("Case #%d: %d\n", cs, res);
	}
	return 0;
}
