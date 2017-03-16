#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <array>

using namespace std;

int J, P, S, k;
set<string> bst;

int i2s(int a, int b)
{
    return a * 4 + b;
}

string i3s(int a, int b, int c)
{
    string s = "0 0 0";
    s[0] += a + 1;
    s[2] += b + 1;
    s[4] += c + 1;
    return s;
}

void myadd(map<int, int> &a, int b)
{
    if (a.count(b) == 0) {
        a[b] = 1;
    } else {
        a[b]++;
    }
}

void myer(map<int, int> &a, int b)
{
    if (a[b] > 1) {
        a[b]--;
    } else {
        a.erase(b);
    }
}

int it;
void gen(int prev, map<int, int> &jp, map<int, int> &ps, map<int, int> &js, set<string> &jps)
{
    // for (const auto& x: jp) {
    //     cerr << x << " ";
    // }
    // cerr << endl;
    if (bst.size() == J * P * S || it > 10000000) {
        return;
    }
    it ++;
    if (jps.size() > bst.size()) {
        bst = jps;
    }
    for (int i1 = 0; i1 < J; i1++) {
        if (i1 * 9 + 6 + 2 <= prev) {
            continue;
        }
        for (int i2 = 0; i2 < P; i2++) {
            if (i1 * 9 + i2 * 3 + 2 <= prev) {
                continue;
            }
            auto s1 = i2s(i1, i2);
            int s = 0;
            if (jp.count(s1) != 0 && jp[s1] >= k) {
                s += jp[s1];
                continue;
            }
            for (int i3 = 0; i3 < S; i3++) {
                if (i1 * 9 + i2 * 3 + i3 <= prev) {
                    continue;
                }
                auto s2 = i2s(i2, i3);
                if (ps.count(s2) != 0 && ps[s2] >= k) {
                    s += ps[s2];
                    continue;
                }
                auto s3 = i2s(i1, i3);
                if (js.count(s3) != 0 && js[s3] >= k) {
                    s += js[s3];
                    continue;
                }
                auto s4 = i3s(i1, i2, i3);
                if (jps.count(s4) != 0) {
                    continue;
                }
                // cerr << s << endl;
                // if (s >= k) {
                //     continue;
                // }
                // jp.insert(s1);
                // ps.insert(s2);
                // js.insert(s3);
                myadd(jp, s1);
                myadd(ps, s2);
                myadd(js, s3);
                jps.insert(s4);

                gen(i1 * 9 + i2 * 3 + i3, jp, ps, js, jps);

                myer(jp, s1);
                myer(ps, s2);
                myer(js, s3);
                jps.erase(s4);
            }
        }
    }
}

void solve()
{
    bst.clear();
    cin >> J >> P >> S >> k;

    map<int, int> jp, ps, js;
    set<string> jps;
    it = 0;
    // cerr << J << " " << P << " " << S << " " << k;
    gen(0, jp, ps, js, jps);
    cout << bst.size();
    cout << endl;
    for (const auto& x: bst) {
        cout << x << endl;
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}