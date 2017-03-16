#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define L 1005

char str[L];

vector < pair < char, int > > read() {
    vector < pair < char, int > > v;
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        for (; j < n && str[j] == str[i]; ++j);
        v.push_back(make_pair(str[i], j - i));
        i = j - 1;
    }
    return v;
}

bool check(const vector < pair < char, int > >& a, const vector < pair < char, int > >& b) {
    if (a.size() != b.size())
        return false;
    int n = a.size();
    for (int i = 0; i < n; ++i)
        if (a[i].first != b[i].first)
            return false;
    return true;
}

void solve() {
    vector < vector < pair < char, int > > > vs;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        vs.push_back(read());
    for (int i = 1; i < n; ++i)
        if (!check(vs[0], vs[1])) {
            puts("Fegla Won");
            return;
        }
    int res = 0, m = vs[0].size();
    for (int j = 0; j < m; ++j) {
        vector < int > v;
        for (int i = 0; i < n; ++i)
            v.push_back(vs[i][j].second);
        sort(v.begin(), v.end());
        int midv = v[(v.size() - 1) / 2];
        for (auto x : v)
            res += abs(x - midv);
    }
    printf("%d\n", res);
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: ", ++cas);
        solve();
    }
    return 0;
}
