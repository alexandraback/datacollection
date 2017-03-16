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
char s[20], t[20];
int a[5], b[5], cnt, id[10];
int ans, x, y,  len;
int ax[20], ay[20];
void get(){
    for(int i = 0; i < len; i ++) ax[i] = a[i], ay[i] = b[i];
}
void dfs(int cur){
    if(cur > cnt){
        int ta = 0, tb = 0;
        for(int i = 0; i < len; i ++){
            ta = ta * 10 + a[i];
        }
        for(int i = 0; i < len; i ++){
            tb = tb * 10 + b[i];
        }
        int temp = (int)abs(ta - tb);
        if(temp < ans){
            ans = temp, x = ta, y = tb;
            get();
        }
        else if(temp == ans && (ta < x)){
            ans = temp, x = ta, y = tb;
            get();
        }
        else if(temp == ans && (x == ta) && tb < y){
            ans = temp, x = ta, y = tb;
            get();
        }
        return;
    }
    for(int i = 0; i <= 9; i ++){
        int u = id[cur];
        if(u < 10){
            a[u] = i;
            dfs(cur + 1);
            a[u] = -1;
        }
        else{
            u -= 10;
            b[u] = i;
            dfs(cur + 1);
            b[u] = -1;
        }
    }
}
int main(){
    //for(int i = 0;  i < 10; i ++) cout << ss[i] << endl;
    fin();
    fout();
    int T = getint();
    for(int ka = 1; ka <= T; ka ++){
        scanf("%s%s", s, t);
        len = strlen(s);
        ans = 1000, x, y, cnt = 0;
        for(int i = 0; i < len; i ++){
            if(s[i] == '?') a[i] = -1, cnt++, id[cnt] = i;
            else a[i] = s[i] - '0';
        }
        for(int i = 0; i < len; i ++){
            if(t[i] == '?') b[i] = -1, cnt++, id[cnt] = i + 10;
            else b[i] = t[i] - '0';
        }
        dfs(1);
        printf("Case #%d: ", ka);
        for(int i = 0; i < len; i ++) cout << ax[i];
        cout << " ";
        for(int i = 0; i < len; i ++) cout << ay[i];
        cout << endl;
    }
    return 0;
}











