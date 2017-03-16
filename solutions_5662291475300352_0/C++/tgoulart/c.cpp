#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

#define MAX_ENCOUNTERS 10
#define EPS 1e-6

struct Event {
    double instant;
    int laps;
    int hiker;
    Event(double i, int l, int h) {
        instant = i;
        laps = l;
        hiker = h;
    }
    bool operator <(const Event &e) const {
        if (instant+EPS < e.instant) return true;
        if (laps < e.laps) return true;
        return false;
    }
};

void solve(int testNo) {
    cout << "Case #" << testNo << ": ";

    int N;
    cin >> N;

    vector <Event> events;
    int totalHikers = 0;

    while (N--) {
        int D, H;
        long long M;
        cin >> D >> H >> M;
        for (int i=0; i < H; ++i) {
            int startintPoint = D;
            double speed =  6.0 / (M + i); // degrees / s
            long long timePerLap = (M + i) * 60; // s
            double timeUntilFirstLap = (360 - startintPoint) / speed;
//            printf("%lf %lld %lf\n",  speed, timePerLap, timeUntilFirstLap);
            for (int k=0; k < MAX_ENCOUNTERS+1; ++k) {
                events.push_back(Event(timeUntilFirstLap + k * timePerLap, k, totalHikers + i));
            }
        }
        totalHikers += H;
    }
//    return;
    sort(events.begin(), events.end());

    int ans = MAX_ENCOUNTERS;
    int stillInFirstLap = totalHikers;
    int lapped = 0;

//    for (int i=0; i < events.size(); ++i) {
//        printf("%d) %d %lf\n", events[i].hiker, events[i].laps, events[i].instant);
//    }
//    return;

    for (int i=0; i < events.size() && stillInFirstLap > 0; ++i) {
        while (i+1 < events.size() && events[i+1].instant-EPS < events[i].instant) {
            if (events[i].laps == 0) {
                --stillInFirstLap;
            } else {
                ++lapped;
            }
            ++i;
        }
//        printf("%d %lf\n", events[i].laps, events[i].instant);
        if (events[i].laps == 0) {
            --stillInFirstLap;
        } else {
            ++lapped;
        }

        ans = min(ans, stillInFirstLap + lapped);

    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i=1; i <= T; ++i) {
        solve(i);
    }
    return 0;
}
