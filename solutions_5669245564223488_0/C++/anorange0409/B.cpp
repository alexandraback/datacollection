#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool ch[255], vis[1000];
string a[100];
int b[100];
int N, ans;
void check(){
    memset(ch, 0, sizeof ch);
    char last = ' ';
    for (int i = 1; i <= N; i++){
        string p = a[b[i]];
        for (int j = 0; j < p.size(); j++){
            if (p[j] == last) continue;
            else{
                if (ch[p[j]]) goto B1;
                ch[p[j]] = true;
                last = p[j];
            }
        }
    }
    ans++;
    B1: return;

}

void dfs(int dep){
    if (dep > N) {check(); return;}
    for (int i = 1; i <= N; i++)
    if (!vis[i]){
        b[dep] = i;
        vis[i] = true;
        dfs(dep + 1);
        vis[i] = false;
    }
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++){
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> a[i];
        ans = 0;
        memset(vis, 0, sizeof(vis));
        dfs(1);
        printf("Case #%d: %d\n", o, ans);
    }
}
