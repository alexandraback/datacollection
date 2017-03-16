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

vector<int> a;
int c, d, w;

set<int> nums;

void g(int x, int s) {
    if (x == a.size()) {
        if (s <= w) {
            nums.insert(s);
        }
        return;
    }
    g(x + 1, s);
    g(x + 1, s + a[x]);
}

bool h(int q, vector<int> av) {
    for (int i = 0; i < q; ++i) {
        a.push_back(av[i]);
    }
    nums.clear();
    g(0, 0);
    if (nums.size() == w + 1) {
        return true;
    }
    for (int i = 0; i < q; ++i) {
        a.pop_back();
    }
    vector<int> vvv(av.size() - q);
    for (int i = 0; i < q; ++i) {
        vvv.push_back(1);
    }
    while (next_permutation(vvv.begin(), vvv.end())) {
        for (int i = 0; i < vvv.size(); ++i) {
            if (vvv[i])
            a.push_back(av[i]);
        }
        nums.clear();
        g(0, 0);
        if (nums.size() == w + 1) {
            return true;
        }
        for (int i = 0; i < q; ++i) {
            a.pop_back();
        }
    }
    return false;
}

int f() {
    set<int> all(a.begin(), a.end());
    vector<int> av;
    for (int i = 1; i <= w; ++i) {
        if (!all.count(i)) {
            av.push_back(i);
        }
    }
    for (int i = 0; i <= w; ++i) {
        if (h(i, av)) {
            return i;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        
        cin >> c >> d >> w;
        a.assign(d, 0);
        for (int i = 0; i < d; ++i) {
            cin >> a[i];
        }
        printf("Case #%d: %d\n", i, f());
    }
    return 0;
}
