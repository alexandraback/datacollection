#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long ll;
typedef double db;

int t,m,n;

int a[1000010];
int b[10];

int main()
{
#ifdef Haha
    freopen("sub-1.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
#endif // Haha
    a[1]=1;
    for(int i=1; i<=1000000; i++)
    {
        //printf("%d\n",i);
        int l=0;
        int x=i;
        while(x)
        {
            b[l++]=x%10;
            x/=10;
        }
        x=0;
        for(int j=0; j<l; j++)
            x=x*10+b[j];
        if(a[i+1]==0) a[i+1]=a[i]+1;
        else a[i+1]=min(a[i+1],a[i]+1);
        if(x<=1000000)
        {
            if(a[x]==0) a[x]=a[i]+1;
            else a[x]=min(a[x],a[i]+1);
        }
    }
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",cas,a[n]);
    }
    return 0;
}
