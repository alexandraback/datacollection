 //#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <bitset>
#include <string>
#include <queue>
using namespace std;
#define rep(i,l,r) for(i = l; i <= r; i++)
#define red(i,l,r) for(i=(l);i>=(r);i--)
#define u_long unsigned long long
#define fff(i, u) for(i = head[u]; i != -1; i = nxt[i])
#define fin() freopen("in.txt", "r", stdin)
#define fout() freopen("out.txt", "w", stdout)
#define clr(vis, a) memset(vis, a, sizeof(vis))
#define LL long long
#define ls id << 1
#define rs id << 1 | 1
#define lson id << 1, l, mid
#define rson id << 1 | 1, mid + 1, r
#define mid ( (l + r) >> 1 )
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define eps 1e-4
#define pi acos(-1)
const int maxn = 1e5 + 10;
const int maxm = 3e4 + 10;
const int inf = 1e9;
const LL mod = 1e9+7;
int getint() {
    char c;
    while((c = getchar()) && !(c >= '0' && c <= '9') && c != '-');
    int ret = c - '0', sgn = 0;
    if(c == '-') sgn = 1, ret = 0;
    while((c = getchar()) && c >= '0' && c <= '9')
        ret = ret * 10 + c - '0';
    if(sgn) ret = -ret;
    return ret;
}
map<string, int> md;
int g[20][2], vis[100][100], x[100], y[100];
int main(){
    //for(int i = 0;  i < 10; i ++) cout << ss[i] << endl;
    fin();
    fout();
    int T = getint();
    for(int ka = 1; ka <= T; ka ++){
        md.clear();
        int tot = 0;
        string s1, s2;
        int n = getint();
        clr(vis, 0);
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
            cin >> s1 >> s2;
            if(!md[s1]) md[s1] = ++tot;
            if(!md[s2]) md[s2] = ++tot;
            if(!vis[md[s1]][md[s2]]) g[++cnt][0] = md[s1], g[cnt][1] = md[s2];
            vis[md[s1]][md[s2]] = 1;
        }
        int ans = 0;
        clr(x, 0);
        clr(y, 0);
        for(int i = 1; i <= cnt; i ++){
            x[g[i][0]] ++;
            y[g[i][1]] ++;
        }
        for(int i = 1; i <= cnt; i ++){
            int xx = g[i][0], yy = g[i][1];
            if(x[xx] >= 2 && y[yy] >= 2){
                ans += 1;
            }
        }
        if(n == 2) ans = 0;
        printf("Case #%d: %d\n", ka, ans);
    }
    return 0;
}










