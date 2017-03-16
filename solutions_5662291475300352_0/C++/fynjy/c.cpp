#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <utility>
#include <numeric>
#include <string.h>

using namespace std;

typedef unsigned long long ulong;
typedef unsigned int uint;
typedef long long int64;


inline ulong max(ulong a, ulong b) {
    return a > b ? a : b;
}

inline ulong min(ulong a, ulong b) {
    return a < b ? a : b;
}

struct hiker {
    ulong pos;
    ulong loopTime;
    double timeToFinish;

    hiker(ulong d, ulong m) 
        : pos(d)
        , loopTime(m)
    {
        timeToFinish = (double)loopTime * (1.0 - (double)pos / 360.0);
    }

    friend bool operator<(const hiker& lhs, const hiker& rhs) {
        return tie(lhs.pos, lhs.loopTime) < tie(rhs.pos, rhs.loopTime);
    }
};

int calc(vector<hiker> hikers) {
    if (hikers.size() != 2)
        return 0;

    sort(hikers.begin(), hikers.end());
    hiker& h1 = hikers[0];
    hiker& h2 = hikers[1];

    if (h1.pos != h2.pos) {
        if (h1.pos > h2.pos) {
            cerr << "ERROR\n";
            std::swap(h1, h2);
        }

        if (h1.timeToFinish < h2.timeToFinish) {
            if (h1.timeToFinish + h1.loopTime <= h2.timeToFinish) {
                //cerr << "first overtakes second 2 times\n";
                return 1;
            } else {
                //cerr << "first overtakes second 2 times\n";
                return 0;
            }
        } else if (h2.timeToFinish + h2.loopTime <= h1.timeToFinish) { 
            //cerr << "second overtakes first\n";
            return 1;
        } else {
            //cerr << "no overtakes\n";
            return 0;
        }
    } else {
        // h1 is faster
        if (h1.timeToFinish + h1.loopTime <= h2.timeToFinish) {
            //cerr << "from the same pos first overtakes second " << h1.timeToFinish << ' ' << h1.loopTime << ' ' << h2.timeToFinish << ' ' << h2.loopTime << endl;
            return 1;
        } else {
            //cerr << "from the same pos no overtakes\n";
            return 0;
        }
    }

    return 123;
}

int main() {
    ulong numTests = 0;
    cin >> numTests;
    for (ulong t = 1; t <= numTests; ++t) {
        ulong n;
        cin >> n;
        vector<hiker> hikers;
        for (ulong i = 0; i < n; ++i) {
            ulong d, h, m;
            cin >> d >> h >> m;
            for (ulong j = 0; j < h; ++j) {
                hikers.push_back(hiker(d, m));
                ++m;
                //cerr << "add hiker: " << hikers.back().pos << " - " << hikers.back().loopTime << endl;
            }
        }

        cout << "Case #" << t << ": " << calc(hikers)<< endl;
    }
    return 0;
}

