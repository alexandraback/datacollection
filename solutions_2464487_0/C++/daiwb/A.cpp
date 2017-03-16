#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long LL;

void run() {
    double r, t;
    cin >> r >> t;
    double r2 = r * 2 - 1;
    double tmp = sqrt(r2 * r2 + 8 * t);
    tmp = (tmp - r2) / 4;
    LL res = (LL) tmp;
    res += 3;
    while (true) {
        double tt = res;
        double qq = 2 * tt * tt + r2 * tt;
        if (qq <= t) break;
        --res;
    }
    cout << res << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
