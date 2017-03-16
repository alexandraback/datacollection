#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long int64;
typedef long double ldouble;

#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)

#define PROBLEM "C"

struct Tribe {
	int d, n, w, e, s, dd, dp, ds;
	int num;

	/*bool operator < (const Tribe& rhs) {
    	if (this->d == rhs.d) return (this->s > rhs.s);
    	return this->d < rhs.d;
    }*/
};

inline bool operator < (const Tribe& lhs, const Tribe& rhs) {
	if (lhs.d != rhs.d) return lhs.d < rhs.d;
	return (lhs.s < rhs.s);
}

set<Tribe> ts;

const int MAXW = 100100, D = MAXW/2;

int a[MAXW], b[MAXW];

int main() {
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    int T;
    scanf("%d\n", &T);

    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        
        int n;
        cin >> n;

        ts.clear();
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);

        for (int i = 0; i < n; i++) {
        	Tribe x;
        	cin >> x.d >> x.n >> x.w >> x.e >> x.s >> x.dd >> x.dp >> x.ds;
        	x.num = i;

        	ts.insert(x);
        }
	
	    int ans = 0;
	    int day = -1;

        while (ts.size() > 0) {
        	Tribe x = *(ts.begin());
            ts.erase(ts.begin());

            if (x.d != day) {
            	memcpy(a, b, sizeof a);
            	day = x.d;
            }

            bool succ = false;
            for (int i = x.w; i < x.e; i++) {
            	if (a[D+i] < x.s) {
            		b[D+i] = x.s;
            		succ = true;
            	}
            }
            if (succ) ans++;

            x.n--;
            if (x.n > 0) {
            	x.d += x.dd;
            	x.w += x.dp;
            	x.e += x.dp;
            	x.s += x.ds;
            	ts.insert(x);
            }
        }

        cout << ans;
        printf("\n");
    }

    return 0;
}
