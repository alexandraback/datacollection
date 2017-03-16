#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int T;
    scanf("%d",&T);
    int casno=0;
    while(T--)
    {
        casno++;
        int a[150][150];
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        scanf("%d",&a[i][j]);
        int MaxL[150];
        int MaxC[150];
        for(int i=0;i<n;i++)
        {
            int t=-1;
            for(int j=0;j<m;j++)
            if(a[i][j]>t)
            t=a[i][j];
            MaxL[i]=t;
        }
         for(int i=0;i<m;i++)
        {
            int t=-1;
            for(int j=0;j<n;j++)
            if(a[j][i]>t)
            t=a[j][i];
            MaxC[i]=t;
        }
        bool ok=1;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(a[i][j]<min(MaxL[i],MaxC[j]))
        {
            //printf("%d %d %d %d\n",i,j,MaxL[i],MaxC[j]);
            ok=0;
        }
        printf("Case #%d: ",casno);
        if(ok)
        printf("YES\n");
        else
        printf("NO\n");
    }
}
