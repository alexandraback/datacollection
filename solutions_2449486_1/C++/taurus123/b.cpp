#include<iostream>
#include<cstdio>
using namespace std;
int a[105][105];
int b[105];
int c[105];
int main()
{
    int T,n,m;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        scanf("%d",&a[i][j]);
        for(int i=0;i<n;i++)
        {
            int tmp=0;
            for(int j=0;j<m;j++)
                if(a[i][j]>tmp)
                tmp=a[i][j];
            b[i]=tmp;
        }
        for(int j=0;j<m;j++)
        {
            int tmp=0;
            for(int i=0;i<n;i++)
                if(a[i][j]>tmp)
                tmp=a[i][j];
            c[j]=tmp;
        }
        bool flag=true;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            if(a[i][j]!=b[i]&&a[i][j]!=c[j])
            flag=false;
        if(flag)
            printf("Case #%d: YES\n",cas);
        else
            printf("Case #%d: NO\n",cas);

    }
    return 0;
}
