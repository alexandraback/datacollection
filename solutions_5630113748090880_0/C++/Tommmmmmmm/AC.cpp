#include<bits/stdc++.h>
using namespace std;
int n;
int a[111][111];
int id[111];
int g[111][111];
bool cmp(int x,int y){
    return a[x][1]<a[y][1];
}
vector<int>rep;
int in[111];
void dfs(int cur,int has,int last){
    //printf("%d %d %d\n",cur,has,last);
    if(rep.size())return;
    if(cur>=n+n&&has!=n)return;
    if(has+n+n-cur<n)return;
    if(cur>=n+n&&has==n){
        vector<int>V1,V2;
        for(int i=1;i<n+n;i++)if(in[i])V1.push_back(id[i]);else V2.push_back(id[i]);
        //for(int i=0;i<V1.size();i++)printf("%d ",V1[i]);puts("");
        int ned=-1;
        for(int i=0;i<n-1;i++){
            if(a[V2[i]][1]!=a[V1[0]][i+1]){ned=i+1;break;}
        }
        if(ned<0)ned=n;
        //printf("ned=%d\n",ned);
        //for(int i=0;i<V2.size();i++)printf("%d ",V2[i]);puts("");
       // puts("ok");
        for(int i=1;i<=n;i++){
            bool flag=1;
            for(int j=1,cur=0;j<=n;j++){
                if(j==ned)continue;
                int idx=V2[cur++];
                if(a[idx][i]!=a[V1[i-1]][j]){flag=0;break;}
            }
            if(!flag)return;
        }
        for(int i=1;i<=n;i++)rep.push_back(a[V1[i-1]][ned]);
        return;
    }
    if(has<n&&(last==0||g[id[last]][id[cur]])){
        in[cur]=1;
        dfs(cur+1,has+1,cur);
        in[cur]=0;
    }
    dfs(cur+1,has,last);
}
int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int _,cas=1;scanf("%d",&_);    
    while(_--){
        printf("Case #%d: ",cas++);
        rep.clear();
        scanf("%d",&n);
        for(int i=0;i<=n;i++)a[0][i]=-1;
        for(int i=1;i<n+n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<n+n;i++){
            for(int j=1;j<n+n;j++){
                if(i==j)continue;
                bool flag=1;
                for(int k=1;k<=n;k++){
                    if(a[i][k]<=a[j][k]){
                        flag=0;
                        break;
                    }
                }
                if(flag)g[j][i]=1;else g[j][i]=0;
            }
        }
        /*
        for(int i=1;i<n+n;i++){
            for(int j=1;j<n+n;j++){
                printf("%d ",g[i][j]);
            }
            puts("");
        }
        */
        for(int i=1;i<n+n;i++)id[i]=i;
        memset(in,0,sizeof(in));
        sort(id+1,id+n+n,cmp);
        //for(int i=1;i<n+n;i++)printf("%d ",id[i]);puts("");
        dfs(1,0,0);
        //puts("ok");
        for(int i=0;i<rep.size();i++)printf("%d%c",rep[i],i==rep.size()-1?'\n':' ');
    }
}
