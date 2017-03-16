#include <iostream>
#include <cstdio>
#include <memory.h>
#include <string.h>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define forn(i, n) for (int i=0; i<(n); ++i)

vector<int> a[128];
int R, N, M, K;

string solve(int tcase) {
    vector<int> v = a[tcase];
    int best = -1;
    string ans = "";
    for (int x=2; x<=M; ++x) for (int y=2; y<=M; ++y) for (int z=2; z<=M; ++z) {
        int cur = 0;
        int t[3] = {x, y, z};
        set<int> h;
        forn (m, (1<<3)) {
            int p = 1;
            forn (i, 3) if (m&(1<<i)) p *= t[i];
            h.insert(p);
        }
        forn (i, K) if (h.find(v[i]) != h.end()) ++cur;
        if (cur > best) {
            best = cur;
            ans = "";
            ans += '0'+x;
            ans += '0'+y;
            ans += '0'+z;
        }

    }
    return ans;
}

int main()
{
    freopen("a.out", "w", stdout);

    int tc; scanf("%d", &tc);
    for (int tt=1; tt<=tc; ++tt) {
        scanf("%d %d %d %d", &R, &N, &M, &K);
        forn (i, R) {
            int x; 
            forn (j, K) {
                scanf("%d", &x);
                a[i].pb(x);
            }
        }
        printf("Case #%d:\n", tt);
        forn (i, R)
            cout << solve(i) << endl;

    }

    return 0;
}
