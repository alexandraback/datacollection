#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <map>

using namespace std;

const double eps = 1e-9;
const int N=105;
char c[N][N];
int main()
{
    //freopen("data.txt","r",stdin);
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int T;
    cin>>T;
    for(int ca=1; ca<=T; ++ca)
    {
        printf("Case #%d:\n",ca);
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                c[i][j]='*';

        int flag=0;
        if(k==0&&flag==0)
        {
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=m; ++j)
                    c[i][j]='.';
            flag=1;
        }
        if(flag==0&&n*m<=2)
        {
            flag=1;
        }
        if(flag==0&&n*m-k==1)
        {
            flag=1;
        }
        if(min(n,m)==1&&flag==0)
        {
            {
                if(n==1)
                {
                    for(int j=1; j<=m-k; ++j)
                        c[n][j]='.';
                    flag=1;
                }
                else if(m==1)
                {
                    for(int i=1; i<=n-k; ++i)
                        c[i][m]='.';
                    flag=1;
                }
            }

        }
        if(min(n,m)==2&&flag==0)
        {
            if(k%2==1||n*m-k<4)
            {
                flag=-1;
            }
            else
            {
                if(n==2)
                {
                    for(int j=1; j<=(n*m-k)/2; ++j)
                        c[1][j]=c[2][j]='.';
                }
                else if(m==2)
                {
                    for(int i=1; i<=(n*m-k)/2; ++i)
                        c[i][1]=c[i][2]='.';
                }
                flag=1;
            }
        }
        k=n*m-k;
        if(k==1&&flag==0)
        {
            flag=1;
        }
        if(k<4&&flag==0)
        {
            flag=-1;
        }
        if(k==4&&flag==0)
        {
            for(int i=1; i<=2; ++i)
                for(int j=1; j<=2; ++j)
                {
                    c[i][j]='.';
                }
            flag=1;
        }
        if((k==5||k==7)&&flag==0)
        {
            flag=-1;
        }
        if(k==6&&flag==0)
        {
            for(int i=1; i<=2; ++i)
                for(int j=1; j<=3; ++j)
                {
                    c[i][j]='.';
                }
            flag=1;
        }
        if(k==8&&flag==0)
        {
            for(int i=1; i<=3; ++i)
                for(int j=1; j<=3; ++j)
                {
                    if(i==3&&j==3) continue;
                    c[i][j]='.';
                }
            flag=1;
        }
        if(k==9&&flag==0)
        {
            for(int i=1; i<=3; ++i)
                for(int j=1; j<=3; ++j)
                {
                    c[i][j]='.';
                }
            flag=1;
        }
        if(flag==0&&k<=2*m)
        {
            for(int i=1; i<=3; ++i)
                for(int j=1; j<=3; ++j)
                {
                    if(i==3&&j==3) continue;
                    c[i][j]='.';
                }
            if(k%2==1)
            {
                c[3][3]='.';
                k=k-9;
            }
            else
            {
                k=k-8;
            }
            for(int j=4; j<=m&&k>0; ++j)
            {
                c[1][j]='.';
                c[2][j]='.';
                k=k-2;
            }
            flag=1;
        }
        if(flag==0&&k>2*m)
        {

            for(int j=1; j<=m&&k>0; ++j)
            {
                c[1][j]='.';
                c[2][j]='.';
                k=k-2;
            }
            int l=3,r=1;
            while(k>0)
            {

                c[l][r]='.';
                --k;
                if(k==0)
                {
                    break;
                }
                if(r==m)
                {
                    l=l+1;
                    r=1;
                }
                else
                {
                    r=r+1;
                }
            }
            if(r==1)
            {
                if(l==3)
                {
                    c[l][r+1]='.';
                    c[l][r+2]='.';
                    c[l-1][m]='*';
                    c[l-2][m]='*';
                }
                else
                {
                    c[l][r+1]='.';
                    c[l-1][m]='*';
                }
            }
            flag=1;
        }
        if(flag==-1)
            printf("Impossible\n");
        else
        {
            c[1][1]='c';
            for(int i=1; i<=n; ++i)
            {
                for(int j=1; j<=m; ++j)
                {
                    printf("%c",c[i][j]);
                }
                printf("\n");
            }
        }

    }
    return 0;
}
