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
};
vector<node> g;
double work(node x) {

}
int main () {
    freopen("sb.in", "r", stdin);
    freopen("fk.out", "w", stdout);
    cin>>t;
    for (int cas = 1; cas <= t; cas++) {
        g.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &d, &h, &m);
            for (int j = 0; j < h; j++) {
                g.pb({d, j + m});
            }
        }
        printf("Case #%d: ", cas);
        if (g.size() < 2) puts("0");
        else {
            if (g[0].v == g[1].v) puts("0");
            else {
                node x = g[0], y = g[1];
                if (x.v < y.v) swap(x, y);
                if (1LL * (360 - x.p) * x.v >= 1LL * (720 - y.p) * y.v) puts("1");
                else puts("0");
            }
        }
    }
    return 0;
}
