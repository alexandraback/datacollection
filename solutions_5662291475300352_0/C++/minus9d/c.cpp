#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
#include <complex>
#include <cassert>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair

class Hiker {
public:
    ll M;
    ll D;
    double speed;
};

int solve(void) {
    int N;
    cin >> N;

    vector<Hiker> hikers;

    REP(n,N) {
        ll D, H, M;
        cin >> D >> H >> M;
        REP(h, H) {
            Hiker hiker;
            hiker.M = M + (ll)h;
            hiker.D = D;
            hiker.speed = (double)360.0 / hiker.M;
            hikers.pb(hiker);
        }
    }

    //assert(hikers.size() == 2);

    // もっとも遅いハイカーが0につく所要時間
    double slow_speed = 1e10;
    ll slow_D = (ll)-1;
    for(auto& h : hikers) {
        if (slow_speed > h.speed) {
            slow_speed = h.speed;
            slow_D = h.D;
        }
    }
    double time = (double)(360.0 - slow_D) / slow_speed;

    // deerはこれより少しだけ遅い時間をかけて到着
    //time += 1e-9;

    // 早いhiker
    double fast_speed = 0.0;
    ll fast_D = (ll)-1;
    for(auto& h : hikers) {
        if (fast_speed < h.speed) {
            fast_speed = h.speed;
            fast_D = h.D;
        }
    }

    // // どれだけ動く?
    // double dist = fast_M * time;
    // // 何回0を通る?
    // ll times = 0;
    // if (dist > fast_D) {
    //     ++times;
    //     dist -= (double)(360 - fast_D);
    // }
    


    double time_fast_hiker = (double)(360.0 - fast_D + 360.0) / fast_speed;
    if (time_fast_hiker > time + 1e-10) {
        return 0;
    }
    else {
        return 1;
    }
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for (int test = 0; test < TEST_NUM; ++test){
        cout << "Case #" << (test + 1) << ": ";
        cout << solve();
        cout << endl;
    }

    return 0;
}

