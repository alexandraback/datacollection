#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

#define FOR(i,l,r)  for(int i=(l); i<=(r); ++i)
#define REP(i,r)    for(int i=0; i<(r); ++i)
#define DWN(i,r,l)  for(int i=(r);i>=(l);--i)

#define pb push_back

typedef long long ll;
typedef pair<int, int>pii;

int v[1010];

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out", "w", stdout);
    int casnum, casid = 0;
    cin >> casnum;
    while(casnum --) {
        int n, max_v = 0;
        cin >> n;
        FOR(i, 1, n)    scanf("%d", &v[i]), max_v = max(max_v, v[i]);
        int ans = 1e9;
        FOR(i, 1, max_v) {
            int tmp = 0;
            FOR(j, 1, n)    tmp += (v[j] + i - 1) / i - 1;
            ans = min(ans, tmp + i);
        }
        printf("Case #%d: %d\n", ++casid, ans);
    }
    return 0;
}

