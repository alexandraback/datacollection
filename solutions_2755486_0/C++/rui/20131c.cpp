#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int m;
int n[20], d[20], s[20], w[20], e[20], dd[20], dp[20], ds[20], h[6000], hh[6000];
struct aa{
    int x,y;
    bool operator < (const aa &a) const {
        return y < a.y;
    }
};
int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cout << "Case #" << tt << ": ";
        memset(h, 0, sizeof h);
        memset(hh, 0, sizeof hh);
        cin >> m;
        vector<aa> a;
        for (int i = 0; i < m; ++i) {
            cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
            w[i] *= 2;
            e[i] *= 2;
            for (int j = 0; j < n[i]; ++j) {
                aa tmp;
                tmp.x = i;
                tmp.y = d[i]+dd[i]*j;
                a.push_back(tmp);
            }
        }
        sort(a.begin(), a.end());
        int k = 0;
        int l = a.size();
        int ans = 0;
        for (int i = 0; i < l; ++i) {
            if (k != a[i].y) {
                k = a[i].y;
                memcpy(h, hh, sizeof h);
            }
            int mark = 0;
            for (int j = w[a[i].x]; j <= e[a[i].x]; ++j) {
                if (h[j+3000] < s[a[i].x]) {
                    mark = 1;
                }
                if (hh[j+3000] < s[a[i].x]) {
                    hh[j+3000] = s[a[i].x];
                }
            }
            ans += mark;
            w[a[i].x] += 2*dp[a[i].x];
            e[a[i].x] += 2*dp[a[i].x];
            s[a[i].x] += ds[a[i].x];
        }
        cout << ans << endl;
    }
    return 0;
}
