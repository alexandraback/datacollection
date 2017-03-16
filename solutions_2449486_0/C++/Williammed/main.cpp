#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int h[105][105];
int left_max[105][105];
int right_max[105][105];
int up_max[105][105];
int down_max[105][105];
int n,m;

int main()
{
    int cas,t=1,l_max,r_max,u_max,d_max;

    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&cas);
    while (cas--)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                scanf("%d",&h[i][j]);
        for (int i=0;i<n;i++)
        {
            l_max=0;
            for (int j=0;j<m;j++)
            {
                left_max[i][j]=l_max;
                l_max=max(l_max,h[i][j]);
            }
            r_max=0;
            for(int j=m-1;j>=0;j--)
            {
                right_max[i][j]=r_max;
                r_max=max(r_max,h[i][j]);
            }
        }
        for(int j=0;j<m;j++)
        {
            u_max=0;
            for(int i=0;i<n;i++)
            {
                up_max[i][j]=u_max;
                u_max=max(u_max,h[i][j]);
            }
            d_max=0;
            for(int i=n-1;i>=0;i--)
            {
                down_max[i][j]=d_max;
                d_max=max(d_max,h[i][j]);
            }
        }
        bool flag=true;
        for(int i=0;i<n&&flag;i++)
           for(int j=0;j<m;j++)
           {
               if(left_max[i][j]<=h[i][j]&&right_max[i][j]<=h[i][j])
                  continue;
               else if(up_max[i][j]<=h[i][j]&&down_max[i][j]<=h[i][j])
                  continue;
               else
               {
                   flag=false;
                   break;
               }
           }
        if(flag)
           printf("Case #%d: YES\n",t++);
        else
           printf("Case #%d: NO\n",t++);
    }
    return 0;
}
