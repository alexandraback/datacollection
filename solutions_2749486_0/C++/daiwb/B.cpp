#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long LL;

int X, Y;

void run() {
    cin >> X >> Y;
    int abx = abs(X), aby = abs(Y);

    if (X > 0) {
        REP(i,abx) cout << "WE";
    } else {
        REP(i,abx) cout << "EW";
    }

    if (Y > 0) {
        REP(i,aby) cout << "SN";
    } else {
        REP(i,aby) cout << "NS";
    }

    cout << endl;
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
