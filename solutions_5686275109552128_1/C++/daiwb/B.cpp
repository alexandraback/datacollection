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

void run() {
    int n;
    cin >> n;
    vector<int> que(n);
    int mx = 1;
    REP(i, n) {
        cin >> que[i];
        mx = max(mx, que[i]);
    }
    int res = mx;
    FOR(pc, 2, mx - 1) {
        int sum = 0;
        REP(i, n) {
            sum += (que[i] + pc - 1) / pc - 1;
        }
        res = min(res, sum + pc);
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
