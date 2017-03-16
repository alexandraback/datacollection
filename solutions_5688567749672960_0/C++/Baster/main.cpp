#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

typedef pair<ld, ld> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

li n;

bool read() {
	cin >> n;
    return true;
}

map<li, int> dp;

const int N = 1000 * 1000 + 500;
int ans[N];

li rev(li x) {
	
	if (x == 0)
		return 0;

	vector<int> v;
	while(x) {
		v.pb(x % 10);
		x /= 10;
	}
	
	forn (i, v.size()) {
		x *= 10;
		x += v[i];
	}
	return x;
}

void solve() {
 
	cout << ans[n] << endl;
	
 }

int main() {
    
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	forn (i, N)
		ans[i] = INF;
	
	ans[0] = 0;
	
	queue<int> q;
	q.push(0);

	while(!q.empty()) {
		int v = q.front();
		q.pop();
		int to = rev(v);
		if (to < N && ans[to] == INF) {
			ans[to] = ans[v] + 1;
			q.push(to);
		}
		to = v + 1;
		if (to < N && ans[to] == INF) {
			ans[to] = ans[v] + 1;
			q.push(to);
		}
	}

	int tc;
	cin >> tc;

	forn (i, tc) {
		read();
		cout << "Case #" << i + 1 << ": ";
        solve();
	}
    
    return 0;
}