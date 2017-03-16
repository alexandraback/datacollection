#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <iomanip>

#define FOR(i,x,y) for(int i =(int)(x); i<(int)(y); i++)
#define REP(i, N) FOR(i, 0, N)
#define SZ(x) (int)x.size()

using namespace std;

typedef vector<int> vin;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvin;

typedef long long LL;
typedef unsigned long long ULL;

int d[2];
int h[2];
int m[2];
int N;
int solve(bool one) {
    if (one == true || N == 1)
        return 0;
    // 2 options - stay behind first guy, or pass and follow behind fast
    int d1, m1, d2, m2;
    if (d[0] <= d[1]) {
        d1 = d[0]; m1 = m[0];
        d2 = d[1]; m2 = m[1];
    } else {
        d1 = d[1]; m1 = m[1];
        d2 = d[0]; m2 = m[0];
    }

    // stay behind last
    double dist_slow = (360.0 - d[0]);
    double speed_fast = 1.0 / m[1];
    double time_slow = (dist_slow / 360.0) * m[0];
    double disp_fast = speed_fast * time_slow;
    bool overlap = false;
    if (d[1] + disp_fast >= 360.0) overlap = true;

    if (overlap) return 1;
    else return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // small test case:
    // either there are two groups of one hiker each, or one group with two hikers
    int T; cin >> T;
    for (int j = 1; j <= T; j++) {
        cin >> N;
        int th = 0;
        for (int i = 0; i < N; i++) {
            int dd, hh, mm; cin >> dd >> hh >> mm;
            d[i-1]=dd; h[i-1]=hh; m[i-1]=mm;
            th += hh;
        }
        cout << "Case #" << j << ": " << solve(th == 1) << "\n";
    }

    return 0;
}

