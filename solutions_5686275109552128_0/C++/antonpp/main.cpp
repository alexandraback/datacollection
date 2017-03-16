#include <iostream>
#include <set>

using namespace std;

int f(multiset<int> &x) {
    const int h = *x.rbegin();
    if (h < 4) {
        return h;
    }
    const int y = h/2;
    x.erase(x.find(h));
    x.insert(y);
    x.insert(h-y);
    return min(h, f(x) + 1);
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
        multiset<int> a;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            a.insert(tmp);
        }
        int res = 0;
        res = g(a);
        printf("Case #%d: %d\n", u + 1, res);
    }

    return 0;
}