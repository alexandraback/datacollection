#include <iostream>
#include <vector>
#include <set>

using namespace std;

inline bool check(const vector<int> &x, int m) {
    const int h = *max_element(x.begin(), x.end());
    for (int i = 0; i < m; ++i) {
        const int s = m - i;
        int r = 0;
        for (const auto y : x) {
            r += (y + s - 1) / s;
        }
        if (r <= (i + x.size())) {
            return true;
        }
    }
    return false;
}

int f(vector<int> &x) {
    const int h = *max_element(x.begin(), x.end());
    int l = 1;
    int r = h;
    while (l < r) {
        int m = (l + r) / 2;
        if (check(x, m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int g(const multiset<int> &x) {
    const int h = *x.rbegin();
    if (h <= 3) {
        return h;
    }
    multiset<int> b;
    for (int f : x) {
        if (f > 1) {
            b.insert(f - 1);
        }
    }
    int q = g(b) + 1;
    b = x;
    for (int i = 2; i <= h / 2; ++i) {
        b.erase(b.find(h));
        b.insert(h - i);
        b.insert(i);
        q = min(q, g(b) + 1);
        b.insert(h);
        b.erase(b.find(h - i));
        b.erase(b.find(i));
    }
    return q;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    for (int u = 0; u < t; ++u) {
        int n, tmp;
        cin >> n;
        vector<int> a;
        a.reserve(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            a.push_back(tmp);
        }
        printf("Case #%d: %d\n", u + 1, f(a));
    }

    return 0;
}