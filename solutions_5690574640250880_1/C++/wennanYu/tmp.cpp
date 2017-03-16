#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int T, cas;
int a, b, m;
char ans[55][55];

bool go(int a, int n, int b, int m, int s){
    int w = m-b+1, h = n-a+1;
    if (w==1||h==1){
        for (int i=a;i<=n;++i){
            for (int j=b;j<=m;++j){
                if (s){
                    ans[i][j]='*';
                    s--;
                }
            }
        }
    }
    if (w==2 && h==2){
        if (s==0) return true;
        if (s==3){
            ans[a][b] = ans[a+1][b] = ans[a][b+1] = '*';
            return true;
        }
        return false;
    }
    int tm = min(w, h);
    if (tm>s){
        for (int i=a;i<=n-2;++i){
            for (int j=b;j<=m-2;++j){
                if (s){
                    ans[i][j]='*';
                    s--;
                }
            }
        }
        if (s) return false;
        return true;
    }
    if (w<=h){
        for (int i=b;i<=m;++i){
            ans[a][i] = '*';
        }
        return go(a+1,n,b,m,s-w);
    }
    else{
        for (int i=a;i<=n;++i){
            ans[i][b] = '*';
        }
        return go(a,n,b+1,m,s-h);
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        memset(ans, '.', sizeof ans);
        scanf("%d%d%d", &a, &b, &m);
        printf("Case #%d:\n", ++cas);
        if (go(1,a,1,b,m)){
            ans[a][b]='c';
            for (int i=1;i<=a;++i){
                for (int j=1;j<=b;++j){
                    printf("%c", ans[i][j]);
                }
                puts("");
            }
        }
        else{
            puts("Impossible");
        }
    }
}
