#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

bool run() {
    int X, R, C;
    cin >> X >> R >> C;

    if (X == 1) return false;

    if (X == 2) {
        if ((R * C) & 1) return true;
        else return false;
    }

    if (X == 3) {
        if (C == 3) swap(R, C);
        if (R != 3) return true;
        if (C == 1) return true;
        return false;
    }

    if (X == 4) {
        if (R > C) swap(R, C);
        if (R == 1 && C == 4) return true;
        if (R == 3 && C == 4) return false;
        if (R == 2 && C == 2) return true;
        if (R == 2 && C == 4) return true;
        if (R == 4 && C == 4) return false;
        
        return true;
    }

    return true;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        if (run()) {
            cout << "RICHARD" << endl;
        }
        else {
            cout << "GABRIEL" << endl;
        }
    }
    return 0;
}
