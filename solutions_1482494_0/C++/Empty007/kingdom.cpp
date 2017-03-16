#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

#define F first
#define S second


vector <pair <int, int> > vp, vt;

bool cmp(pair <int, int> a , pair <int, int> b ) {
	if (a.first == b.first) return (vt[a.second] > vt[b.second]);
	return (a.first < b.second);
}

int main() {
	int T, n, x, y;
	cin >> T;
	REP(tc, T) {
		cin >> n;
		vp.clear();
		vt.clear();
		REP(i, n) {
			cin >> x >> y;
//			dbg2(x, y);
			vp.pb(mp(x, i));
			vt.pb(mp(y, i));
		}
		
		sort(ALL(vp), cmp);
		sort(ALL(vt));
		
		int id1 = 0, id2 = 0, stars = 0, levels = 0;
		int vis[n];
		CLR(vis, 0);
		bool bo = true;
		while (true) {
			if (id2 >= n) break;
			if (stars >= vt[id2].F) {
				stars += 2 - vis[vt[id2].S];
//				dbg2(2, vt[id2].S);
				id2++;
				levels++;
				continue;
			}
			else if (id1 < n && stars >= vp[id1].F) {
				stars++;
				vis[vp[id1].S]++;
//				dbg2(1, vp[id1].S);
				id1++;
				levels++;
				continue;
			}
			else {
				bo = false;
				break;
			}
		}
		if (bo) printf("Case #%d: %d\n", tc+1, levels);
		else printf("Case #%d: Too Bad\n", tc+1);
	}

	return 0;
}
