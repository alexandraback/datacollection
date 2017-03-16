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

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);    
}

void solve() {
    long long a;
    long long b;
    char t;

    cin >> a >> t >> b;
    long long g = gcd(a, b);
    a /= g;
    b /= g;
    
    if (__builtin_popcountll(b) != 1) {
        cout << "impossible" << endl;
        return;
    }

    int ret = 0;    
    long long d = b;
    while (d > 0) {
        ++ret;
        d /= 2;
    }

    --ret;
    while (a > 1) {
        --ret;
        a /= 2;
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
