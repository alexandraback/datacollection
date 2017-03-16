/*
 ID: aandrew
 PROG: gcj 2013, round 1a
 URL:
 LANG: C++
 
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cassert>
#include <set>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MP make_pair
#define PB push_back

const int N = 15, K = 15;
map<ll,int> h;
double ans;
int r, n, m, k, v[N], st[N], prod[K];

void backtrack(int x) {
	if (x == n) {
		//got the numbers
		h.clear();
		//cout << "        ";
		REP(i,1<<n) {
			ll p = 1;
			REP(j,n) if ((1<<j) & i) p *= v[j];
			//cout << p << " ";
			h[p]++;
		}
		//cout << endl;
		double pr = 1;
		REP(j,k) {
			pr *= 1.*h[ prod[j] ]/(1<<n);
		}
		
		/*REP(i,n)
			cout << v[i] << " ";
		cout << " ------ " << pr << endl;*/
		
		if (pr > ans) {
			ans = pr;
			REP(i,n) st[i] = v[i];
		}
	} else {
		for (int z = 2; z <= m; z++) { 
			v[x] = z; 
			backtrack(x+1);
		}
	}
}

int main() {
	int T;
	cin >> T;
	REP(qqq,T) {
		cin >> r >> n >> m >> k;
		cout << "Case #" << (qqq+1) << ":" << endl;
		REP(i,r) {
			REP(j,k) cin >> prod[j];
			ans = 0;
			backtrack(0);
			REP(i,n) cout << st[i];
			cout << endl;
		}
	}
}
