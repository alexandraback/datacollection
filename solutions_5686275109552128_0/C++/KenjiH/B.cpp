#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

const int INF = 1<<20;
int n;

// how many spacial minute is needed 
// to make all plates have less than x cakes?
int calc(const vector<int> &v, int x) {
    
    int ret = 0;
    REP (i, v.size()) {
        int y = v[i];
        if (y > x)
            ret += (y + x - 1) / x - 1;
    }

    return ret;
}

void solve() {
    cin >> n;
    vector<int> p(n);
    REP (i, n) cin >> p[i];

    int ret = INF;

    for (int i = 1; i <= 1000; i++) {
        ret = min(ret, i + calc(p, i));
    }

    cout << ret << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    REP (i, T) {
        cerr << "Case #" << i+1 << ": " << endl;
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
