#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct hiker {
    int pos;
    int time;
};

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tt;
    cin >> tt;
    for (int ti = 1; ti <= tt; ++ti) {
        int n;
        cin >> n;
        vector<hiker> hikers;
        for (int i = 1; i <= n; ++i) {
            int d, h, m;
            cin >> d >> h >> m;
            for (int j = 0; j < h; ++j) {
                hiker temp;
                temp.pos = d;
                temp.time = m + j;
                hikers.push_back(temp);
            }
        }
        int answer = 0;
        if (hikers.size() > 1) {
            int d1 = hikers[0].pos;
            int h1 = hikers[0].time;
            int d2 = hikers[1].pos;
            int h2 = hikers[1].time;
            if (h1 != h2) {
                if (d1 > d2) {
                    swap(d1, d2);
                    swap(h1, h2);
                }
                double s1 = d1, s2 = d2;
                if (h1 > h2) {
                    double k = double(d2 - d1) / (h2 - h1);
                    s1 = d1 + k * h1;
                    s2 = d2 + k * h2;
                }
                if (s1 < 360) {
                    double t1 = (360 - s1) / 360 * h1;
                    int z2 = s2 + t1 / h2;
                    if (z2 <= 720) {
                        answer = 1;
                    }
                }
            }
        }
        cout << "Case #" << ti << ": " << answer << '\n';
    }
}
