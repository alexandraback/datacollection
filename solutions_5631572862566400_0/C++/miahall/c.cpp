#include<bits/stdc++.h>
using namespace std;
int T,n,x;
int use[1234],dep[1234],go[1234];
vector<int> e[1234];
int ans,s;
void dfs(int x){
  //  cout<<x<<endl;
    use[x]=1;
    if(!use[go[x]]){
        dep[go[x]]=dep[x]+1;
        dfs(go[x]);
    }
}
int sou(int x){
    int s=0;
    for(int i=0;i<e[x].size();i++){
        int y=e[x][i];
        if(use[y])continue;
        s=max(s,sou(y));
    }
    return s+1;
}
int main(){
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    scanf("%d",&T);

    for(int ti=1;ti<=T;ti++){
        printf("Case #%d: ",ti);
        scanf("%d",&n);
        for(int i=0;i<n;i++)e[i].clear();
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            x--;
            go[i]=x;
            e[x].push_back(i);
        }

        ans=s=0;
        for(int i=0;i<n;i++){
            memset(use,0,sizeof(use));
            memset(dep,0,sizeof(dep));
            dfs(i);
            for(int j=0;j<n;j++)if(go[j]==i)ans=max(ans,dep[j]+1);
        }


        memset(use,0,sizeof(use));
        for(int i=0;i<n;i++) {
            int j=go[i];
            if(go[i]==j && go[j]==i) {
                use[i]=1;
                s++;
            }
        }
        for(int i=0;i<n;i++)if(use[i]) s+=sou(i)-1;
        printf("%d\n",max(s,ans));
    }


}
