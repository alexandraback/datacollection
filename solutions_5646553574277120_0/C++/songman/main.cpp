#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <map>

#define UREP(i,n) for(unsigned int i=0;i<n;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define FRVR for(;;)

typedef unsigned long long int ULINT;
typedef long long int LINT;

const double EPS = 1e-6;

using namespace std;

void process(int caseNum) {

    int c,d,v;
    cin >> c >> d >> v;

    vector<int> denom;
    REP(i, d) {
        int den;
        cin >> den;
        denom.push_back(den);
    }


    bool * vals = new bool[v+1];
    REP(i, v+1) vals[i] = false;
    vals[0] = true;

    for(;;) {
        bool ok = true;
        REP(i, v+1) if(!vals[i]) { ok = false; break; }
        if(ok) break;

        UREP(i, 1<<denom.size()) {
            int val = 0;
            for(int j = 0; j < denom.size(); j++) {
                if(i & (1<<j)) val+= denom[j];
            }
            if(val <= v)
                vals[val] = true;
        }

        REP(i, v+1) if(!vals[i]) { denom.push_back(i); break; }
    }


    cout << "Case #" << caseNum << ": " << denom.size() - d << endl;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    REP(i, t) {
        process(i+1);
    }

    return 0;
}
