#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
#define SIZE 222
int cs,a[SIZE],used[SIZE];
void dfs(int x,int get[],vector<int>e[]){
    int i;
    if(get[x])return;
    get[x]=1;
    for(i=0;i<e[x].size();i++)
        dfs(e[x][i],get,e);
}
bool check(int N,int now[],vector<int>e[]){
    int key[SIZE]={},i,j,cnt[SIZE]={},get[SIZE]={};
    for(i=1;i<=200;i++)cnt[i]=now[i];
    vector<int>ee[SIZE];
    for(i=1;i<=N;i++){
        if(used[i]!=cs){
            key[a[i]]++;
            for(j=0;j<e[i].size();j++){
                cnt[e[i][j]]++;
                ee[a[i]].pb(e[i][j]);
            }
        }
    }
    for(i=1;i<=200;i++){
        //if(i<=4)printf("%d:%d,%d\n",i,key[i],cnt[i]);
        if(key[i]>cnt[i])return 0;
    }
    for(i=1;i<=200;i++)
        if(now[i]>0)dfs(i,get,ee);
    for(i=1;i<=200;i++)
        if(key[i]&&!get[i])return 0;
    return 1;
}
int main(){
    int T,K,N,i,j,k;
    scanf("%d",&T);
    while(T--){
        cs++;
        scanf("%d%d",&K,&N);
        int now[SIZE]={};
        for(i=0;i<K;i++){
            int x;
            scanf("%d",&x);
            now[x]++;
        }
        vector<int>e[SIZE];
        for(i=1;i<=N;i++){
            scanf("%d",&a[i]);
            int m;
            scanf("%d",&m);
            while(m--){
                int x;
                scanf("%d",&x);
                e[i].pb(x);
            }
        }
        printf("Case #%d:",cs);
        if(!check(N,now,e)){
            puts(" IMPOSSIBLE");
            continue;
        }
        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                if(used[j]==cs||!now[a[j]])continue;
                now[a[j]]--;
                for(k=0;k<e[j].size();k++)now[e[j][k]]++;
                used[j]=cs;
                if(check(N,now,e)){
                    printf(" %d",j);
                    break;
                }
                used[j]=0;
                now[a[j]]++;
                for(k=0;k<e[j].size();k++)now[e[j][k]]--;
            }
        }
        puts("");
    }    
    return 0;
}
