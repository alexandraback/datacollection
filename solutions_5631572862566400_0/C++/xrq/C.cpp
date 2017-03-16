#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#define mem(a) memset(a,0,sizeof(a))
#define INF 0x7fffffff   //INT_MAX
#define inf 0x3f3f3f3f   //
const double PI = acos(-1.0);
const double e = exp(1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
bool cmpbig(int a,int b){return a>b;}
bool cmpsmall(int a,int b){return a<b;}
using namespace std;
int arc[1005][1005];
int list[1005][1005];
int flag[1005];
int p[1005];

int n,t;
void dfs(int sta,int beg){
    if(flag[sta])
        return;
    flag[sta]=1;
    for(int i=1;i<=n;i++){
        if(arc[sta][i] && !flag[i]){
            dfs(i,beg);
        }
        if(arc[sta][i] && i==beg){
            flag[beg]++;
            return;
        }
    }

}

int dfs2(int sta,int no){
    int ans=0;
    for(int i=1;i<=n;i++){
    	if(i==no){no=0;continue;}
        if(arc[i][sta]){
            ans=max(ans,dfs2(i,no));
        }
    }
    return ans+1;
}
int main()
{
    scanf("%d",&t);
    for(int o=1;o<=t;o++){
        printf("Case #%d: ",o);
        scanf("%d",&n);
        mem(arc);
        for(int i=1;i<=n;i++){
            int to;
            scanf("%d",&to);
            arc[i][to]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            mem(flag);
                for(int j=1;j<=n;j++)
                    if(arc[i][j]==1){
                        dfs(i,i);
                    }
                if(flag[i]==2){
                    int maxn=0;
                    for(int i=1;i<=n;i++)
                        if(flag[i])
                            maxn++;
                    ans=max(ans,maxn);
                }
        }
        mem(flag);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(arc[i][j]==1 && arc[j][i]==1){
                      ans=max(ans,dfs2(i,j)+dfs2(j,i));
                }
            }
        printf("%d\n",ans);
        }
    return 0;
}
