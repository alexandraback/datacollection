// C

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef long double ld;

struct hiker {
    hiker(ld d, ld m) : d(d), m(m) {}
    ld d, m;
    bool operator<(const hiker& other) const
    { return m < other.m; }
};

ld tcollide(ld d1, ld d2, ld m1, ld m2) {
    return (d1 - d2) / (m2 - m1);
}

int solve() {
    vector<hiker> vec;

    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        ld d; int h; ld m;
        cin >> d >> h >> m;
        for(int hi = 0; hi < h; ++hi)
            vec.push_back(hiker(d, m+hi));
    }
    sort(vec.begin(), vec.end());

    if(vec.size() == 1) return 0;
    if(vec[0].m == vec[1].m) return 0;
    if(vec[1].d >= vec[0].d) {
        hiker& fast = vec[1],
               slow = vec[0];

        if(fast.d == slow.d) fast.d += .000000001;

        fast.d = -1 * (360.0 - fast.d);

        if(tcollide(fast.d, slow.d, fast.m, slow.m) <= 
           tcollide(slow.d, 360.0, slow.m, 0.0)) {
            return 1;
        }
        else return 0;
    }
    else {
        hiker& fast = vec[1],
               slow = vec[0];

        ld slow360 = tcollide(slow.d, 360.0, slow.m, 0.0);
        ld collide1 = tcollide(fast.d, slow.d, fast.m, slow.m);
        fast.d += fast.m * collide1;
        slow.d += slow.m * collide1;
        ld collide2 = tcollide(fast.d+.0000001, slow.d, fast.m, slow.m);

        if(collide2 <= slow360) return 1;
        else return 0;
    }
}

int main() {
    int t; cin >> t;
    for(int tcase = 1; tcase <= t; ++tcase) {
        printf("Case #%i: %i\n", tcase, solve());
    }
    return 0;
}
