#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int r, c, m;
int t, ct, cnt;
bool f[100][100];
int xl[8]={-1,-1,-1,0,0,1,1,1};
int yl[8]={-1,0,1,-1,1,-1,0,1};
void dfs(int x, int y){
    int a, b;
    int cur=0;
    bool mk[8];
    memset(mk,0,sizeof(mk));
    for(int i=0; i<8; i++){
        a = x+xl[i];
        b = y+yl[i];
        if(a>=0 && a<r && b>=0 && b<c && !f[a][b]){
            mk[i]=1;
            cur++;
        }
    }
    if(cur+cnt<=m){
        cnt+=cur;
        for(int i=0; i<8; i++){
            if(mk[i]){
                f[x+xl[i]][y+yl[i]]=1;
            }
        }
        for(int i=0; i<8; i++){
            if(mk[i] && cnt<m){
                dfs(x+xl[i], y+yl[i]);
            }
        }
    }
}
int main(){
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    scanf("%d", &t);
    for(ct=1; ct<=t; ct++){
        printf("Case #%d:\n", ct);
        scanf("%d %d %d", &r, &c, &m);
        m = r*c-m;
        bool flag=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                memset(f,0,sizeof(f));
                f[i][j]=1;
                cnt=1;
                dfs(i,j);
                if(cnt==m){
                    flag=1;
                    break;
                }
            }
            if(flag)    break;
        }
        if(flag){
            putchar('c');
            for(int i=1; i<c; i++){
                if(f[0][i])  putchar('.');
                else    putchar('*');
            }
            puts("");
            for(int i=1; i<r; i++){
                for(int j=0; j<c; j++){
                    if(f[i][j])  putchar('.');
                    else    putchar('*');
                }
                puts("");
            }
        }
        else{
            puts("Impossible");
        }
    }
    return 0;
}
