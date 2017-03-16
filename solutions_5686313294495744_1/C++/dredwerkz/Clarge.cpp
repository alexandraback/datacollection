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

pair<string, string> v[1004];
int n;
int vis[1004];

void clean(vector<pair<int, string> > &v) {
    vector<pair<int, string> > t;
    for (int i = 0; i < v.size(); i++)
        if (v[i].first)
            t.push_back(v[i]);
    v = t;
    sort(v.begin(), v.end());
}

void fnd(int t, string s, string &s1, string &s2) {
    for (int i = 0; i < n; i++) {
        if (!vis[i] && ((t == 0 && v[i].first == s) || (t == 1 && v[i].second == s))) {
            s1 = v[i].first;
            s2 = v[i].second;
            return;
        }
    }
}

#define SINGLELINE 1
void solve() {
    n = gi();
    string s1, s2;

    unordered_map<string, int>::iterator it;
    unordered_set<string> st1, st2;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        v[i] = make_pair(s1, s2);
        st1.insert(s1);
        st2.insert(s2);
        vis[i] = 0;
    }

    int res = 0;
    while (1) {
        unordered_map<string, int> fc, sc;
        for (int i = 0; i < n; i++)
            if (!vis[i]) {
                s1 = v[i].first;
                s2 = v[i].second;
                if ((it = fc.find(s1)) == fc.end())
                    fc[s1] = 1;
                else
                    it->second++;
                if ((it = sc.find(s2)) == sc.end())
                    sc[s2] = 1;
                else
                    it->second++;
            }
        if (!fc.size())
            break;
        int found = 0;
        for (it = fc.begin(); it != fc.end(); it++)
            if (it->second == 1) {
                found = 1;
                fnd(0, it->first, s1, s2);
                break;
            }
        if (!found) {
            for (it = sc.begin(); it != sc.end(); it++)
                if (it->second == 1) {
                    found = 1;
                    fnd(1, it->first, s1, s2);
                    break;
                }
            if (!found) {
                fnd(0, fc.begin()->first, s1, s2);
            }
        }
        for (int i = 0; i < n; i++)
            if (!vis[i] && (v[i].first == s1 || v[i].second == s2))
                vis[i] = 1;
        st1.erase(s1);
        st2.erase(s2);
        res++;
    }

    printf("%d\n", int(n - (res + st1.size() + st2.size())));
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
