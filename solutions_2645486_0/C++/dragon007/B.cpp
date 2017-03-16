#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <list>
using namespace std;

#define PB push_back
#define MP make_pair
#define A first
#define B second
#define eps 1e-8
#define INF 0x3f3f3f3f

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

struct sgt {
    LL l, r, maxw;
} a[400010];

LL t, E, R, n, v[100010];

void buildtree(LL t, LL l, LL r) {
    a[t].l = l;
    a[t].r = r;
    if (l == r) {
        a[t].maxw = l;
        return ;
    }
    LL mid = (l + r) / 2;
    buildtree(t * 2, l, mid);
    buildtree(t * 2 + 1, mid + 1, r);
    if (v[a[t * 2].maxw] > v[a[t * 2 + 1].maxw])
        a[t].maxw = a[t * 2].maxw;
    else a[t].maxw = a[t * 2 + 1].maxw;
}

LL findmax(LL t, LL l, LL r) {
    if (a[t].l == l && a[t].r == r) return a[t].maxw;
    LL mid = (a[t].l + a[t].r) / 2;
    if (r <= mid) return findmax(t * 2, l, r);
    else if (l > mid) return findmax(t * 2 + 1, l, r);
    else {
        LL ans1 = findmax(t * 2, l, mid), ans2 = findmax(t * 2 + 1, mid + 1, r);
        if (v[ans1] > v[ans2]) return ans1;
        else return ans2;
    }
}

LL work(LL l, LL r, LL s, LL maxe) {
    if (r < l) return 0;
    if (l == r) {
        if (r == n) return s * v[r];
        else return v[r] * max(0LL, s - (maxe - R));
    }
    LL i = findmax(1, l, r);
    LL ans = 0, up, low;
    if (r == n) {
        up = min(s + (i - l) * R, E);
        ans += up * v[i];
        ans += work(l, i - 1, s , up);
    }
    else {
        up = min(s + (i - l) * R, E);
        low = max(0LL, maxe - R * (r - i + 1));
        up = max(up, low);
        ans += (up - low) * v[i];
        ans += work(l, i - 1, s , up);
    }
    ans += work(i + 1, r, min(R, E), maxe);
    //cout<<i<<" "<<ans<<endl;
    return ans;
}

int main() {

    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B.out", "w", stdout);
    scanf("%I64d", &t);
    for (LL ca = 1; ca <= t; ca ++ ) {
        scanf("%I64d%I64d%I64d", &E, &R, &n);
        //if (ca == 100) cout<<E<<" "<<R<<" "<<" "<<n<<endl;
        for (LL i = 1; i <= n; i ++ ) {
            scanf("%I64d", &v[i]);
            //if (ca == 100) cout<<v[i]<<" ";
        }
        //if (ca== 100) cout<<endl;
        buildtree(1, 1, n);
        printf("Case #%I64d: %I64d\n", ca, work(1, n, E, INF));
    }
    return 0;
}
