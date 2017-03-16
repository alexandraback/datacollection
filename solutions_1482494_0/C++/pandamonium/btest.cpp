#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int one[15],two[15];
int done[15];
int t,n,y,x,stars=0;
int final;
void dfs(int ans){
    int prev[15],initial;
    for(int i=0;i<n;i++){
        prev[i]=done[i];
    }
    initial=stars;
    bool redo=1;
    while(redo){
        redo=0;
        for(int i=0;i<n;i++){
            if(two[i]<=stars&&done[i]<2){
                stars+=2-done[i];
                done[i]=2;
                ans++;
                redo=1;
            }
        }
    }
    if(stars==2*n){
        final=min(final,ans);
        for(int i=0;i<n;i++) done[i]=prev[i];
        stars=initial;
        return;
    }
    for(int i=0;i<n;i++){
        if(done[i]==0&&one[i]<=stars){
            done[i]=1;
            stars++;
            ans++;
            dfs(ans);
            ans--;
            stars--;
            done[i]=0;
        }
    }
    for(int i=0;i<n;i++) done[i]=prev[i];
    stars=initial;
    return;
}           
int main(){
    scanf("%d",&t);
    for(x=1;x<=t;x++){
        scanf("%d",&n);
        final=2*n+1;
        stars=0;
        memset(one,0,sizeof(one));
        memset(two,0,sizeof(two));
        memset(done,0,sizeof(done));
        for(y=0;y<n;y++){
            scanf("%d %d",&one[y],&two[y]);
        }
        dfs(0);
        if(final>2*n) printf("Case #%d: Too Bad\n",x);
        else printf("Case #%d: %d\n",x,final);
    }
    return 0;
}
