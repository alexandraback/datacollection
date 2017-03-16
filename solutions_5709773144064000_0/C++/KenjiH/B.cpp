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

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

void solve() {
    double c, f, x;
    cin >> c >> f >> x;

    double ret = 0;
    double a = 2.0;
    double b = 0;

    if (x < c) {
        cout << fixed << setprecision(9) << x / a << endl;
        return;
    }

    for (;;) {
        if (b < c) {
            ret += (c - b) / a;
            b = c;
        }

        double t = (x - c) / a;             // not purchase cookie farm
        double u = (x - b + c) / (a + f);   // purchase cookie farm

        if (t < u) {
            ret += t;
            break;
        }

        a += f;
        b -= c;
    }

    cout << fixed << setprecision(9) << ret << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    
    int T;
    cin >> T;

    REP (i, T) {
        cerr << "Solving Case #" << (i+1) << "..." << endl;
        cout << "Case #" << (i+1) << ": "; 
        solve();
    }

    return 0;
}
