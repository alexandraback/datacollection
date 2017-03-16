#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1005;
int T,N,mxdep;
int a[MAX],flag[MAX];
vector <int> G[MAX];
void dfs(int u,int fa,int dep)
{
    mxdep = max(dep,mxdep);
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(v != fa){
            dfs(v,u,dep + 1);
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int casei = 1; casei <= T; ++casei){
        scanf("%d",&N);
        int ans = 1;
        for(int i = 1; i <= N; ++i)
            G[i].clear();
        for(int i = 1; i <= N; ++i){
            scanf("%d",&a[i]);
            G[a[i]].push_back(i);
        }
        for(int i = 1; i <= N; ++i){
            memset(flag,0,sizeof(flag));
            flag[i] = 1;
            int len = 1,tmp = a[i];
            while(!flag[tmp]){
                ++len;
                flag[tmp] = 1;
                tmp = a[tmp];
            }
            //printf("###%d %d %d\n",i,tmp,len);
            if(tmp == i)
                ans = max(ans,len);
        }
        int ans1 = 0;
        for(int i = 1; i <= N; ++i){
            if(a[a[i]] == i && i <= a[i]){
                mxdep = 0;
                dfs(i,a[i],1);
                ans1 += mxdep;
                mxdep = 0;
                dfs(a[i],i,1);
                ans1 += mxdep;
            }
        }
        ans = max(ans,ans1);
        printf("Case #%d: %d\n",casei,ans);
    }
    return 0;
}

