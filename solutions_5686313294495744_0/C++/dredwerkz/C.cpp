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

#define SINGLELINE 1
void solve() {
    int n = gi();
    string s1, s2;

    vector<pair<string, string> > v;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        v.push_back(make_pair(s1, s2));
    }

    int pp = 1 << n;
    int res = 0;
    for (int i = 1; i < pp; i++) {
        int tr = i;
        unordered_set<string> fs, ss;
        for (int j = 0; j < n && tr; j++) {
            int r = tr % 2;
            tr /= 2;
            if (r) {
                fs.insert(v[j].first);
                ss.insert(v[j].second);
            }
        }
        tr = i;
        int worked = 1;
        int c = 0;
        for (int j = 0; j < n; j++) {
            int r = tr % 2;
            tr /= 2;
            if (!r) {
                if (fs.find(v[j].first) == fs.end()) {
                    worked = 0;
                    break;
                }
                if (ss.find(v[j].second) == ss.end()) {
                    worked = 0;
                    break;
                }
                c++;
            }
        }
        if (worked) {
            res = MAX(c, res);
        }
    }
    printf("%d\n", res);
}

int main() {
    int t = gi();

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:%c", i, (SINGLELINE ? ' ' : '\n'));
        solve();
        fprintf (stderr, "Case %d / %d. Elapsed %.2f. Estimated %.2f\n", i, t, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / i * t) / CLOCKS_PER_SEC);
    }

    return 0;
}
