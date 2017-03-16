#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<set>
#include<cstring>
typedef long long int uli;
using namespace std;

const int mx = 60;
char b[mx][mx];
bool vis[mx][mx],found;
int cnt,r,c,m;


bool valid(int i, int j){
    return (i>=0 && i<r && j>=0 && j<c);
}
void dfs(int i, int j){
    vis[i][j] = true;
    cnt++;
    bool ok = true;
    for(int dr=-1;dr<=1;dr++){
        for(int dc=-1;dc<=1;dc++){
            int vi = i+dr,vj = j+dc;
            if(valid(vi,vj) && b[vi][vj]=='*') 
                ok = false;
        }
    }
    if(ok){
        for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                int vi = i+dr,vj = j+dc;
                if(valid(vi,vj) && !vis[vi][vj]) 
                    dfs(vi,vj);
            }
        }
    }
}

void solve(int i ,int j, int no, int nx){

    if(found) return;
    if(nx>m || no>r*c-m) return;
    if(i==r){
        memset(vis,false, sizeof vis);
        /*
        for(int s=0;s<r;s++){
            for(int t=0;t<c;t++){
                cout<<b[s][t];
            }
            cout<<endl;
        }
        */
        cnt = 0;
        dfs(0,0);
        if(cnt==no){
            found = true;
        }
        return;
    }

    b[i][j] = '.';
    j++;
    if(j==c) solve(i+1,0,no+1,nx);
    else solve(i,j,no+1,nx);

    if(found) return;

    b[i][j-1] = '*';
    if(j==c) solve(i+1,0,no,nx+1);
    else solve(i,j,no,nx+1);

}
int main(){
    freopen("cat.in","r",stdin);
    freopen("cat.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d %d %d",&r,&c,&m);
        found = false;
        solve(0,0,0,0);
    
        printf("Case #%d:\n",tc);
        if(!found) printf("Impossible\n");
        else{
            b[0][0] = 'c';
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    printf("%c",b[i][j]);
                }
                printf("\n");
            }
        };
    }
    return 0;
}
