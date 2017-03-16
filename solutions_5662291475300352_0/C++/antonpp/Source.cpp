#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stdlib.h>

using namespace std;

struct hiker {
    int d;
    int m;
};

int f(const vector<hiker>& hikers) {
    if (hikers.size() < 2) {
        return 0;
    }
    hiker a = hikers[0];
    hiker b = hikers[1];
    
    long long m = a.m;
    long long t1 = m * (360 - a.d);
    m = b.m;
    long long t2 = m * (360 - b.d);

    if (t1 < t2) {
        swap(a, b);
    }

    if (a.m == b.m) {
        return 0;
    }
    m = a.m;
    t1 = m * (360 - a.d);
    m = b.m;
    t2 = m * (720 - b.d);

    if (t2 <= t1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        vector<hiker> hikers;
        for (int i = 0; i < n; ++i) {
            int d, h, m;
            scanf("%d%d%d", &d, &h, &m);
            for (int i = 0; i < h; ++i) {
                hikers.push_back({ d, m + i });
            }
        }
        printf("Case #%d: %d\n", i + 1, f(hikers));
    }
    return 0;
}
