#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

int n,m;
int grass[100][100];
int diff[100][100];

bool judge(){
    scanf("%d%d",&n,&m);
    int Hmax = 0;
    rep(i,n) rep(j,m){
        scanf("%d",grass[i]+j);
        Hmax = max(grass[i][j],Hmax);
    }

    for(int H = 1; H <= Hmax; H++){
        memset(diff,0,sizeof(diff));

        rep(i,n) rep(j,m+1){
            if(j==m) rep(k,m) diff[i][k] = 1;
            else if(grass[i][j] < H) return false;
            else if(grass[i][j] > H) j = 999;
        }

        rep(j,m) rep(i,n+1){
            if(i==n) rep(k,n) diff[k][j] = 1;
            else if(grass[i][j] < H) return false;
            else if(grass[i][j] > H) i = 999;
        }

        rep(i,n) rep(j,m) grass[i][j] += diff[i][j];
    }
    return true;
}

int main(){
    int T;
    scanf("%d",&T);
    rep(C,T){
        printf("Case #%d: %s\n", C+1, judge()?"YES":"NO");
    }
    return 0;
}
