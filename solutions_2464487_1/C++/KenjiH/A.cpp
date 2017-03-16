#include <algorithm>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  

long long calc(long long x, long long r) {
    return 2 * x * x + (2 * r - 1) * x;
}


void solve() {
    long long r, t;
    cin >> r >> t;

    long long hi = 1000000000LL;
    hi = min(hi, t/(2*r-1)+10);
    long long lo = 1;

    while (hi - lo > 1) {
        long long mid = (lo + hi) / 2;
        long long tmp = calc(mid, r);
        if (tmp <= t)
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << endl;
}

int main() {
    int T;
    cin >> T;
    REP (i, T) {
        cout << "Case #" << (i+1) << ": ";
        solve();
    }

    return 0;
}
