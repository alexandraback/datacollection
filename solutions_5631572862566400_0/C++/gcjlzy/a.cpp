#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
const int N=1e3+1;
int a[N],bo1[N];
bool bo[N];
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t,k;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        int n,i,ans1=0,ans=0;
        cin>>n;memset(bo1,0,sizeof bo1);
        for(i=1;i<=n;i++)scanf("%d",a+i);
        for(i=1;i<=n;i++)
        if(a[a[i]]==i)bo1[i]=1;
        for(i=1;i<=n;i++)
        if(!bo1[i])
        {
            memset(bo,0,sizeof bo);
            int x=i,y=0;
            while(!bo[x]&&!bo1[x]){bo[x]=1;x=a[x];y++;}
            if(bo1[x])bo1[x]=max(bo1[x],y+1);
            if(x==i)ans=max(ans,y);
        }
        for(i=1;i<=n;i++)ans1+=bo1[i];
        ans=max(ans,ans1);
        printf("Case #%d: %d",k,ans);
        printf("\n");
    }

    return 0;
}
