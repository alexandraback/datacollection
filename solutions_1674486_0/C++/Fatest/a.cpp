#include<cmath>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define for1(i,a,b) for(i=(a);i<(b);i++)
#define for2(i,a,b) for(i=(a);i>(b);i--)
#define same(a) memset((a),0,sizeof(a));
#define ll long long

int cmpint(const void*a,const void *b)
{
    if(((int*)a)[0]==((int*)b)[0])
      return ((int*)a)[1]-((int*)b)[1];
    return ((int*)a)[0]-((int*)b)[0];
}

char s[1000005];
int a[1005][1005];

int flag[1005];

int dfs(int k){
    int i,t;
    for1(i,1,a[k][0]+1)
       if(flag[a[k][i]]==1){
           return 1;
       }
       else {
           flag[a[k][i]]=1;
           t=dfs(a[k][i]);
           if(t==1) return t;
       }
    return 0;
}

int main()
{
    int i,j,n,m,k,l,o,p;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&p);
    for1(o,0,p){
        scanf("%d",&n);
        for1(i,1,n+1){
            scanf("%d",&a[i][0]);
            for1(j,1,a[i][0]+1)
             scanf("%d",&a[i][j]);
        }
        int fg=0;
        for1(i,1,n+1){
            if(fg==1) break;
            same(flag);
            fg=dfs(i);
        }
        printf("Case #%d: ",o+1);
        if(fg==0) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
