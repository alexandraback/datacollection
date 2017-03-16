#include <bits/stdc++.h>

using namespace std;
#define DEBUG_ON 1

#define INF 0x3f3f3f3f
#define NSYNC ios::sync_with_stdio(false)
#define FOR(i,a,b) for(int i=a; i<(b); ++i)
#define FOR0(i,b) for(int i=0; i<(b); ++i)
#define TRAV(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define RTRAV(it,c) for(__typeof((c).rbegin()) it=(c).rbegin(); it!=(c).rend(); ++it)
#define DBG(x) if(DEBUG_ON) cout << #x << " == " << x << endl
#define DBGP(x) if(DEBUG_ON) cout << "(" << (x).first << ", " << (x).second << ")" << endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define CLR(v) memset(v, 0, sizeof(v))
#define SET(v) memset(v, -1, sizeof(v))

typedef long long ll;
typedef int int_type;
typedef pair<int_type, int_type> pii;
typedef vector<int_type> vi;
typedef vector<vi> vii;

string keyb, tgt;
int k, l, s;
ll hits[20];
ll tot;

void auxs(string cur) {
	if(cur.size()==s) {
		int count = 0;
		FOR0(i,s) {
			int j;
			for(j = 0; i+j<s && j<l && cur[i+j]==tgt[j]; ++j);
			if(j==l) ++count;
		}
		++hits[count];
		++tot;		
	}
	else {
		TRAV(it, keyb) {
			string aux = cur;
			aux += *it;
			auxs(aux);
		}
	}
}

double solve() {
	CLR(hits);
	tot = 0;
	string cur = "";
	auxs(cur);
	double maxh = 0.0;
	double ans = 0.0;
	FOR0(i, s+1) {
		if(hits[i]) maxh = i;
	}
	FOR0(i,s+1) if(hits[i]) {
		ans += (maxh - i)*((double)hits[i]/tot);
		// cout << (maxh - i) << "*" << ((double)hits[i]/tot) << endl;
	}
	return ans;
}

int main() {
	NSYNC;
	int tests;
	cin >> tests;
	FOR(t, 1, tests+1) {
		cin >> k >> l >> s;
		cin >> keyb;
		cin >> tgt;
		cout << "Case #" << t << ": " << fixed << setprecision(15) << solve() << "\n";
	}
	return 0;
}