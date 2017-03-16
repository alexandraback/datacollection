#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[2000];
int t[2000];
int vis[2000];
int m[2000];
int h[2000];
int ans;
int tans;
int ttt;
void dfs(int x, int la, int len){
    vis[x] = ttt;
    h[x] = len;
    if (vis[a[x]] == ttt){
        if (a[x] == la && (len - 1) > m[la]){
            ans += (len - 1) - m[la];
            m[la] = (len - 1);
            if (m[x] == 0){
                ans += 1;
                m[x] = 1;
            }
        }
        if (len - h[a[x]] + 1 > tans){
            tans = len - h[a[x]] + 1 ;
        }
    }else dfs(a[x],x,len+1); 
}

void tdfs(int x, int la, int len){
    vis[x] = 1;
    if (vis[a[x]] == 1){
        if (len > tans){
            tans = len;
        }
        if (a[x] == la)
            ans += 2;
    }else tdfs(a[x],x, len+1); 
}

int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    cin >> T;
    int w = 1;
    for (int w = 1;w<=T;w++){
        int n;
        cin >> n;
        ans = 0;
        tans = 0;
        ttt = 0;
        memset(a,0,sizeof(a));
        memset(t,0,sizeof(t));
        memset(vis,0,sizeof(vis));
        memset(m,0,sizeof(m));
        memset(h,0,sizeof(h));
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            t[a[i]] += 1;
        }
        for (int i = 1; i <= n; i++){
            if (t[i] == 0){
                ttt += 1;
                dfs(i, -1, 1);
            }
        }
        for (int i = 1; i <= n; i++){
            if (vis[i] == 0){
                tdfs(i, -1, 1);
            }
        }
        if (tans > ans)
            ans = tans;
        printf("Case #%d: ", w);
        cout << ans << endl;
    }
}