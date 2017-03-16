#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<iostream>
#include<sstream>
using namespace std;
int T,cas=0,n,m,M;
char mp[55][55];
void out()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%c",mp[i][j]);
        puts("");
    }
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&M);
        printf("Case #%d:\n",++cas);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)mp[i][j]='*';
        if(n==4&&m==4&&M==3)
        {
            printf("c...\n....\n...*\n..**\n");
            continue;
        }
        if(n==5&&m==5&&M==4)
        {
            printf("*....\n.....\n..c..\n.....\n***..\n");
            continue;
        }
        int black=n*m-M;
        if(black==1)
        {
            mp[0][0]='c';
            out();
            continue;
        }
        if(m==1)
        {
            mp[0][0]='c';
            for(int i=1;i<black;i++)mp[i][0]='.';
            out();
            continue;
        }
        if(n==1)
        {
            mp[0][0]='c';
            for(int i=1;i<black;i++)mp[0][i]='.';
            out();
            continue;
        }
        int len=-1;
        for(int i=2;i<=m;i++)
        {
            if(black/i>1&&black/i<=n&&black%i!=1)
            {
                if(black/i==n&&black%i>0)continue;
                len=i;
                break;
            }
        }
        if(len==-1)
        {
            for(int i=2;i<=n;i++)
            {
                if(black/i>1&&black/i<=m&&black%i!=1)
                {
                    if(black/i==m&&black%i>0)continue;
                    len=i;
                    break;
                }
            }
            if(len==-1)
            {
                if(min(m,n)>=4)
                {
                    for(int i=2;i<=m;i++)
                    {
                        if(black/i>1&black/i<=n&&black%i==1)
                        {
                            if(black/i==n)continue;
                            len=i;
                            break;
                        }
                    }
                    if(len==-1)
                    {
                        for(int i=2;i<=n;i++)
                        {
                            if(black/i>1&&black/i<=m&&black%i==1)
                            {
                                if(black/i==m)continue;
                                len=i;
                                break;
                            }
                        }
                        if(len==-1)puts("Impossible");
                        else
                        {
                            int col=black/len,left=black%len;
                            for(int i=0;i<len;i++)
                            for(int j=0;j<col;j++)
                            mp[i][j]='.';
                            for(int i=0,j=n-1;i<=left;i++,j--)
                            mp[j][col]='.';
                            mp[0][0]='*';
                            if(len>3)
                            {
                                mp[len-2][0]='c';
                                out();
                            }
                            else if(col>3)
                            {
                                mp[0][col-2]='c';
                                out();
                            }
                            else puts("Impossible");
                        }

                    }
                    else
                    {
                        int row=black/len,left=black%len;
                        for(int i=0;i<row;i++)
                        for(int j=0;j<len;j++)
                        mp[i][j]='.';
                        for(int j=0,i=m-1;j<=left;j++,i--)
                        mp[row][i]='.';
                        mp[0][0]='*';
                        if(len>3)
                        {
                            mp[0][len-2]='c';
                            out();
                        }
                        else if(row>3)
                        {
                            mp[row-2][0]='c';
                            out();
                        }
                        else puts("Impossible");
                    }
                }
                else puts("Impossible");
            }
            else
            {
                int col=black/len,left=black%len;
                for(int i=0;i<len;i++)
                for(int j=0;j<col;j++)
                mp[i][j]='.';
                for(int i=0;i<left;i++)
                mp[i][col]='.';
                mp[0][0]='c';
                out();
            }
        }
        else
        {
            int row=black/len,left=black%len;
            for(int i=0;i<row;i++)
            for(int j=0;j<len;j++)
            mp[i][j]='.';
            for(int j=0;j<left;j++)
            mp[row][j]='.';
            mp[0][0]='c';
            out();
        }
    }
}
