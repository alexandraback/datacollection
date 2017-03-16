#define DBG 1

#include <cstring>
#include <iomanip>
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

char c[8];
char j[8];

#define SINGLELINE 1
void solve() {
    scanf("%s%s", c, j);
    int m = 1000;
    int cs = 1;
    int js = 1;
    int l = strlen(c);
    vector<pair<int, int> > v;
    for (int i = 0; i < l; i++)
        if (c[i] == '?')
            v.push_back(make_pair(0, i));
    for (int i = 0; i < l; i++)
        if (j[i] == '?')
            v.push_back(make_pair(1, i));

    int ttt = 1;
    int nq = v.size();
    for (int i = 0; i < nq; i++)
        ttt *= 10;

    for (int i = 0; i < ttt; i++) {
        int n = i;
        for (int k = 0; k < nq; k++) {
            int r = n % 10;
            n /= 10;
            if (v[k].first)
                j[v[k].second] = '0' + r;
            else
                c[v[k].second] = '0' + r;
        }
        int cc = atoi(c);
        int jj = atoi(j);
        int mm = cc-jj;
        mm = MAX(mm, -mm);
        if (mm == m) {
            if (cc < cs) {
                cs = cc;
                js = jj;
            } else if (cc == cs && jj < js)
                js = jj;
        } else if (mm < m) {
            m = mm;
            cs = cc;
            js = jj;
        }
    }
    cout << setfill('0') << setw(l) << cs << " " << setfill('0') << setw(l) << js << endl;
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
