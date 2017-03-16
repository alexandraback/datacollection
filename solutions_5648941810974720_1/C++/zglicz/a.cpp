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

int co[] = {0, 2, 6, 7, 5, 8, 4, 3, 1, 9};
string elems[] = {"ZERO", "TWO",  "SIX", "SEVEN", "FIVE", "EIGHT", "FOUR", "THREE",  "ONE",   "NINE"};
int cnt[26];
VI res;

bool moge(string kt) {
	int wys[26];
	REP(i ,26) wys[i] = 0;
	REP(i, SIZE(kt)) {
		++wys[kt[i] - 'A'];
	}
	// if (kt == "FIVE") {
	// 	REP(i, 26) printf("wys[%c] = %d, %d\n", i + 'A', wys[i], cnt[i]);
	// }
	REP(i, 26) if (wys[i] > cnt[i]) {
		// printf("nie da sie!\n");
		return false;
	}
	// cout << "moge wpisac: " << kt << endl;
	REP(i, 26) cnt[i] -= wys[i];
	return true;
}

void solve() {
	string x;
	cin >> x;
	REP(i, SIZE(x)) {
		cnt[x[i] - 'A']++;
	}
	REP(i, 10) {
		while (moge(elems[i])) {
			res.PB(co[i]);
		}
	}
	sort(ALL(res));
	REP(i, SIZE(res)) printf("%d", res[i]);
	printf("\n");
	res.clear();
}

int main(){
	int t;
	cin >> t;
	FOR(i, 1, t) {
		cout << "Case #" << i << ": ";
		solve();
	}
}