/*
ID: jsnjhcb1
PROG: c
LANG: C++
*/
/*************************************************************************
	> File Name: c.cpp
	> Author: UCU
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六  4/16 10:02:15 2016
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<string>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<iomanip>
#include<climits>
#include<fstream>
using namespace std;
int F[1010];
int ans ;
int n;
int vis[1010];
int huanmax;
void dfs(int root,int now,int cnt){
    vis[now] = cnt;
    if(vis[F[now]] == -1){
        dfs(root,F[now],cnt+1);
    }
    else{
        if(F[now] == root){
            huanmax = max(huanmax,cnt-vis[F[now]]+1);
        }
    }
}
void solve(int now,int cnt,int &huanmax){
    vis[now] = cnt;
    huanmax = max(huanmax,cnt);
    for(int i=1;i<=n;++i){
        if(vis[i] == -1 && F[i] == now){
            solve(i,cnt+1,huanmax);
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        printf("Case #%d: ",ca);
        scanf("%d",&n);
        memset(F,0,sizeof F);
        huanmax = 0;
        for(int i=1;i<=n;++i){
            scanf("%d",F+i);
        }
        ans = 1;
        for(int i=1;i<=n;++i){
            memset(vis,-1,sizeof vis);
            dfs(i,i,1);
        }
        int ans = 0;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if(F[i] == j && F[j] == i){
                    memset(vis,-1,sizeof vis);
                    vis[i] = vis[j] = 1;
                    int tmp1 ,tmp2;
                    tmp1 = tmp2 = 0;
                    solve(i,1,tmp1);
                    solve(j,1,tmp2);
                    ans += tmp1 + tmp2;
                }
            }
        }
        printf("%d\n",max(ans,huanmax));
    }
    return 0;
}
