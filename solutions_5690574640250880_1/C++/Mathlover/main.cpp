#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int r,c,m,i,t,j,k,l,a[105],now,ca;
bool flag;
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        ca++;
        printf("Case #%d:\n",ca);
        scanf("%d%d%d",&r,&c,&m);
        if (c==1)
        {
            for (j=1; j<=m; j++) printf("*\n");
            for (j=m+1; j<r; j++) printf(".\n");
            printf("c\n");
        }
        else if (r==1)
        {
            for (j=1; j<=m; j++) printf("*");
            for (j=m+1; j<c; j++) printf(".");
            printf("c\n");
        }
        else
        {
            flag=true;
            k=r*c-m;
            a[1]=min(k/2,c);
            if (k-a[1]*2==1) a[1]--;
            if (a[1]<=0) flag=false;
            else
            {
                a[2]=a[1];
                k-=a[1]*2;
                now=2;
                while (k>0)
                {
                    a[now+1]=min(k,a[now]);
                    if (a[now+1]==1)
                    {
                        a[now]--;
                        a[now+1]=2;
                    }
                    now++;
                    k-=a[now];
                }
            }
            for (i=2; i<=now; i++) if (a[i]>c || a[i]>a[i-1]) flag=false;
            if (a[1]==1 || a[now]<=1) flag=false;
            if (k==1)
            {
                a[now=1]=1;
                flag=true;
            }
            if (!flag || now>r)
            {
                printf("Impossible\n");
                continue;
            }
            cout<<'c';
            for (i=2; i<=a[1]; i++) cout<<'.';
            for (i=a[1]+1; i<=c; i++) cout<<'*';
            cout<<endl;
            for (i=2; i<=now; i++)
            {
                for (j=1; j<=a[i]; j++) cout<<'.';
                for (j=a[i]+1; j<=c; j++) cout<<'*';
                cout<<endl;
            }
            for (i=now+1; i<=r; i++)
            {
                for (j=1; j<=c; j++) cout<<'*';
                cout<<endl;
            }
        }
    }
    return 0;

}
