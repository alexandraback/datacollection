#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <ctime>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
#define FOR(x, b, e) for(int x=(b); x<=(e); ++x)
#define FORD(x, b, e) for(int x=((int)(b))-1; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) ((int)((x).size()))
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define mp(x,y) make_pair(x,y)
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FOREACH(it, (x)) cerr <<*it <<", "; cout <<endl; }}
typedef short int sint;

void solve() {
	LL k, c, s;
	cin >> k >> c >> s;
	LL sum = 1;
	REP(i, c) sum *= k;
	vector<LL> res;
	int cur = 0;
	while (cur < k) {
		LL ind = cur;
		REP(i, c - 1) {
			if (cur + 1 < k) {
				++cur;
			}
			ind = ind * k + cur;
		}
		// cout << "dorzucam: " << ind << endl;
		res.PB(ind);
		++cur;
	}
	if (SIZE(res) > s) {
		cout << "IMPOSSIBLE";
	} else {
		FOREACH(p, res) {
			cout << *p + 1 << ' ';
		}
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	FOR(i, 1, t) {
		cout << "Case #" << i << ": ";
		solve();
	}
}