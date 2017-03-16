#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#define MAXN 100000
#define LL long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
int n,m,ans;
int p[13];
void dfs(int cnt,int a[])
{
    if(cnt>=ans)return;
    int b[11],c[11],i,j,maxi=0;
    for(i=1;i<=9;i++)
    {
        b[i]=c[i]=a[i];
        if(a[i]>0)maxi=i;
    }
    //for(i=1;i<=9;i++)printf("%d%c",a[i],i==9?'\n':' ');

    if(maxi==1)
    {
        ans=min(cnt+1,ans);
        return;
    }
    for(i=1;i<=8;i++)
    {
        c[i]=a[i+1];
    }
    c[9]=0;
    dfs(cnt+1,c);
    for(i=1;i<=maxi/2;i++)
    {
        b[i]+=1;
        b[maxi-i]+=1;
        b[maxi]-=1;
        dfs(cnt+1,b);
        b[i]-=1;
        b[maxi-i]-=1;
        b[maxi]+=1;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("2in.txt", "r", stdin);
        freopen("2out.txt", "w", stdout);
    #endif
    int T,t,i,j,d;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%d",&n);
        int maxi=0;
        memset(p,0,sizeof(p));
        for(i=0;i<n;i++)
        {
            scanf("%d",&d);
            p[d]++;
            maxi=max(maxi,d);
        }
        ans=maxi;
        dfs(0,p);
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
