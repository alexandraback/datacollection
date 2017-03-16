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

    LINT r,c,w;
    cin >> r >> c >> w;

    LINT res = r * ((ceil(c/(double)w)) + w-1);

    cout << "Case #" << caseNum << ": " << res << endl;
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
