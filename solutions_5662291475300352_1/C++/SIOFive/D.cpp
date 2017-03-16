/*
ID: wuqi9395@126.com
PROG:
LANG: C++
*/
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<fstream>
#include<cstring>
#include<ctype.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF (1 << 30)
#define LINF (1LL << 60)
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define eps 1e-6
#define debug puts("===============")
#define pb push_back
#define mkp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define POSIN(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
typedef long long ll;
typedef unsigned long long ULL;
int t, d, n, h, m;
struct node {
    int p, v;
}g[100];
int cnt = 0;
bool cmp(node x, node y) {
    return (1LL * (720 - x.p) * x.v <= 1LL * (720 - y.p) * y.v);
}
int main () {
    freopen("ss.in", "r", stdin);
    freopen("ss.out", "w", stdout);
    cin>>t;
    for (int cas = 1; cas <= t; cas++) {
        cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &d, &h, &m);
            for (int j = 0; j < h; j++) {
                g[cnt].p = d, g[cnt++].v = m + j;
            }
        }
        printf("Case #%d: ", cas);
        sort(g, g + cnt, cmp);
        int ans = 0;
        for (int i = 1; i < cnt; i++) {
            if (1LL * (360 - g[i].p) * g[i].v >= 1LL * (720 - g[0].p) * g[0].v) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
