#define DBG 1

#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
    scanf("%lld", &a);
    return a;
}

struct h_ {
    ll r;
    ll s;
};

bool mf(h_ a, h_ b) {
    return a.r < b.r;
}

#define SINGLELINE 1
void solve() {
    vector<h_> v;
    int n = gi();
    for (int i = 0; i < n; i++) {
        int p = gi();
        int h = gi();
        ll t = gi();
        for (int j = 0; j < h; j++) {
            ll reach = (t+j) * (360LL-p);
            h_ h = {reach, t*360LL};
            v.push_back(h);
        }
    }
    sort(v.begin(), v.end(), mf);
    int min = 100;
    for (int i = 0; i < v.size(); i++) {
        ll res = 0;
        for (int j = i+1; j < v.size(); j++) {
            if (v[j].r > v[i].r)
                res++;
        }
        for (int j = 0; j < i; j++) {
            if (v[j].r < v[i].r) {
                ll d = v[i].r - v[j].r;
                ll x = d/v[j].s;
                res += x;
            }
        }
        if (res < 100)
            min = MIN(res, min);
    }
    printf("%d\n", min);
}

int main() {
    int t = gi();

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:%c", i, (SINGLELINE ? ' ' : '\n'));
        solve();
    }

    return 0;
}
