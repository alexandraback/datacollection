#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include <limits.h>
#include<cmath>
#include<map>
#include<queue>
#include<set>
using namespace std;

#define N 100005
#define M 100005
#define LL long long

//为自己加油O(∩_∩)O~

const long long  mod =1000000007;
int ne[1111];
vector<int> v[1111];
bool vis[1111];
int maxn=0,ans=0,lian=0;
int huan=0;
void dfs1(int pos,int len)
{
    vis[pos]=1;
    maxn=max(len,maxn);
    for (int j=0;j<v[pos].size();j++){
        if (vis[v[pos][j]]) continue;
        dfs1(v[pos][j],len+1);
    }
}
int shen[1111];
void dfs(int pos,int len)
{
    shen[pos]=len;
    if (shen[ne[pos]]!=0){
        huan=len-shen[ne[pos]];
        return;
    }
    dfs(ne[pos],len+1);
    if (huan!=0) return ;
}
int main()
{
    freopen("3.out","w",stdout);
    int T;
    scanf("%d",&T);
    int t=T;
    while (T--){
        int n;
        scanf("%d",&n);
        for (int j=1;j<=n;j++) v[j].clear();
        for (int j=1;j<=n;j++) {
            scanf("%d",&ne[j]);

            v[ne[j]].push_back(j);
        }
        memset(vis,0,sizeof(vis));
        ans=0;lian=0;huan=0;
        for (int j=1;j<=n;j++){
            if (!vis[j]){
                if (ne[ne[j]]==j){
                    maxn=0;
                    vis[j]=1;vis[ne[j]]=1;
                    dfs1(j,1);
                    lian+=maxn;
                    maxn=0;
                    dfs1(ne[j],1);
                    lian+=maxn;
                }
            }
        }

        int haha=0;
            for (int j=1;j<=n;j++){
                if (!vis[j]){
                        memset(shen,0,sizeof(shen));
                        huan=0;
                        dfs(j,1);
                        haha=max(haha,huan+1);
                }
            }

        ans=max(haha,lian);
        printf("Case #%d: %d\n",t-T,ans);
    }
    return 0;
}








