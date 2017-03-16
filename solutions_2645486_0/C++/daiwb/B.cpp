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

int E, R, N;
int v[10];
int mm[10][15];

int dp(int now, int idx) {
    int& ret = mm[now][idx];
    if (ret != -1) return ret;

    if (idx == N) return ret = 0;

    ret = 0;
    FOR(i,0,now) {
        int gain = v[idx] * i;
        int ne = min(E, now - i + R);
        int t = dp(ne, idx + 1);
        ret = max(ret, gain + t);
    }

    return ret;
}

void run() {
    cin >> E >> R >> N;
    REP(i,N) cin >> v[i];
    memset(mm, -1, sizeof(mm));
    int ret = dp(E, 0);
    cout << ret << endl;
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
