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
	string x;
	cin >> x;
	x.push_back('+');
	reverse(x.begin(), x.end());
	int cnt = 0, ost = x[0];
	FOR(i, 1, SIZE(x) - 1) {
		if (x[i] != ost) {
			++cnt;
			ost = x[i];
		}
	}
	cout << cnt << endl;
}

int main(){
	int t;
	cin >> t;
	FOR(i, 1, t) {
		cout << "Case #" << i << ": ";
		solve();
	}
}