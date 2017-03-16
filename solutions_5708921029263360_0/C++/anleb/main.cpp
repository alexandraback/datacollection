#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <time.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <math.h>
using namespace std;

    ////////////////////////////////////////////////////////////////////////////////
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

bool check(vector<int> &p) {
    int m = -1e9;
    int s = 0;
    for (int i = 0; i < p.size(); ++i) {
        s += p[i];
        if (p[i] > m) {
            m = p[i];

        }
    }
    if (m * 2 > s) {
        return 1;
    }
    return 0;
}

struct my {
    int j, p, s;
};

bool operator < (my a, my b) {
    return mp(a.j, mp(a.p, a.s)) < mp(b.j, mp(b.p, b.s));
}

bool check(vector<my> &v, int k) {
    map<my, int> m;
    for (auto i : v) {
        my l = i;
        l.j = -1;
        m[l]++;
        if (m[l] >= k) {
            return 0;
        }
        l.j = i.j;
        l.p = -1;
        m[l]++;
        if (m[l] >= k) {
            return 0;
        }
        l.p = i.p;
        l.s = -1;
        m[l]++;
        if (m[l] >= k) {
            return 0;
        }
        l.s = i.s;
    }
    return  1;
}

int main(){
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int z = 0; z < t; ++z) {
        cout << "Case #" << z+1 <<": ";
        cerr << z << endl;
        int j, p, s, k;
        cin >> j >> p >> s >> k;
        vector<my> v;
        my l;

        for (int a = 0; a < j; ++a) {
            for (int b = 0; b < p; ++b) {
                for (int c = 0; c < s; ++c) {
                    l.j = a;
                    l.p = b;
                    l.s = c;
                    v.push_back(l);
                }
            }
        }
        int ma = 1;
        for (int i = 0; i < v.size(); ++i) {
            ma *= 2;
        }
        vector<my> ans;
        int lol = 0;
        ++k;
        if (j == p and p == s and s == 3) {
            for (int i = 0; i > -1000000; --i) {
                vector <my> current;
                int c = rand() % ma;
                int it = 0;
                while (c) {
                    if (c % 2) {
                        current.push_back(v[it]);
                    }
                    c/=2;
                    ++it;
                }
                if (current.size() <= lol) {
                    continue;
                }
                if (check(current, k)) {
                    swap(ans, current);
                    lol = ans.size();
                }
            }
        }
        else {
            for (int i = ma - 1; i > 0; --i) {
                vector<my> current;
                int c = i;//rand() % ma;
                int it = 0;
                while (c) {
                    if (c % 2) {
                        current.push_back(v[it]);
                    }
                    c /= 2;
                    ++it;
                }
                if (current.size() <= lol) {
                    continue;
                }
                if (check(current, k)) {
                    swap(ans, current);
                    lol = ans.size();
                }
            }
        }
        cout << lol << endl;
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i].j+1 <<  ' ' << ans[i].p+1 << ' ' << ans[i].s+1 << '\n';
        }
    }
}