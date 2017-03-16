#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int solve() {
    vector<pii> hikers;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d, h, m;
        cin >> d >> h >> m;
        for (int j = 0; j < h; j++)
            hikers.push_back(pii(m + j, d));
    }
    sort(hikers.begin(), hikers.end());
    if (hikers.size() == 1)
        return 0;
    if (hikers[0].first == hikers[1].first)
        return 0;
    int dist = (hikers[1].second - hikers[0].second + 360) % 360;
    if (dist == 0) dist = 360;
    double meet = dist / (360. / hikers[0].first - 360. / hikers[1].first);
    double meetpos = hikers[1].second + (360. / hikers[1].first) * meet;
    double looptime = 1 / (1. / hikers[0].first - 1. / hikers[1].first);
    if (hikers[0].second >= hikers[1].second) {
        //printf("Part 1\n");
        if (meetpos > 360 + 1e-9)
            return 0;
        else
            return 1;
    }
    else {
        //printf("Part 2\n");
        if (meetpos > 360 + 1e-9)
            return 0;
        double mpos2 = meetpos + (360. / hikers[1].first) * looptime;
        if (mpos2 > 360 + 1e-9)
            return 0;
        return 1;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        printf("Case #%d: %d\n", i, solve());
}
