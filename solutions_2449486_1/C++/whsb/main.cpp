#include <iostream>
#include <cstdio>
using namespace std;

int h[110][110],a[110][110];
int n,m;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,flag;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            a[110][110]=100;
            scanf("%d",&h[i][j]);
        }

        for(int H=100;H>=1;H--)
        {
            for(int i=0;i<n;i++)
            {
                flag=1;
                for(int j=0;j<m;j++)
                {
                    if(h[i][j]>H)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    for(int j=0;j<m;j++) a[i][j]=H;
                }
            }

            for(int j=0;j<m;j++)
            {
                flag=1;
                for(int i=0;i<n;i++)
                {
                    if(h[i][j]>H)
                    {
                        flag=0;break;
                    }
                }
                if(flag)
                {
                    for(int i=0;i<n;i++) a[i][j]=H;
                }
            }

        }
        flag=1;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]!=h[i][j]) flag=0;
        }

        if(flag) printf("Case #%d: YES\n",cas);
        else printf("Case #%d: NO\n",cas);

    }
    return 0;
}
