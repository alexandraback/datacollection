#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define NAME "As2"
#define UsingFile 1

int f[25][25];
int dfs(int C,int W){
    if(C==W)return C;
    //C>W
    int &ret=f[C][W];
    ret=C;
    for(int i=1;i<=C-W;i++){
        int ok=dfs(C-i,W)+1;
        int ko=dfs(i+W-1,W);
        cmin(ret,max(ok,ko));
    }
    return ret; 
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    memset(f,-1,sizeof f);
    for(int CA=1;CA<=_T;CA++){
        int R,C,W;
        scanf("%d%d%d",&R,&C,&W);
        int ans=0;
        for(i=W;i<=C;i+=W)
            ans++;
        ans*=R-1;
        while(C>=2*W)C-=W,ans++;
        ans+=dfs(C,W);
        printf("Case #%d: %d\n",CA,ans);
    }
    return 0;
}

