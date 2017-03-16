#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef vector<double> vd;

int count_deceitful(vd &ni, vd &ki) {
    int r = 0;
    vd n;
    n.assign(ni.begin(), ni.end());
    vd k;
    k.assign(ki.begin(), ki.end());
    while (!n.empty()) {
        if (n.front() > k.front()) {
            r++;
            n.erase(n.begin());
            k.erase(k.begin());
            continue;
        }
        n.erase(n.begin());
        k.pop_back();
    }
    return r;
}

int count_normal(vd &ni, vd &ki) {
    int r = 0;
    vd n;
    n.assign(ni.begin(), ni.end());
    vd k;
    k.assign(ki.begin(), ki.end());
    while (!n.empty()) {
        if (n.back() > k.back()) {
            r++;
            n.pop_back();
            k.erase(k.begin());
            continue;
        }
        n.pop_back();
        k.pop_back();
    }
    return r;
}

int main() {
    int tcc;
    cin >> tcc;
    for (int tc = 1; tc <= tcc; tc++) {
        vector<double> n;
        vector<double> k;
        int l;
        cin >> l;
        for (int i = 0; i < l; i ++) {
            double v;
            cin >> v;
            n.push_back(v);
        }
        for (int i = 0; i < l; i ++) {
            double v;
            cin >> v;
            k.push_back(v);
        }
        sort(n.begin(), n.end());
        sort(k.begin(), k.end());

        printf("Case #%d: %d %d\n", tc, count_deceitful(n, k), count_normal(n, k));
    }
}
