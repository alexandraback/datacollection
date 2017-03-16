#include<functional>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<set>
#include<map>
using namespace std;
int getnum()//读大量数据特别快
{
    char ch;
    while(ch=getchar(),ch==10||ch==32);
    int ans=ch-48;
    while((ch=getchar())!=EOF&&(ch>='0'&&ch<='9'))
    {
        ans*=10;
        ans+=ch-'0';
    }
    return ans;
}
int sum,r,c,m;
char a[60][60];
void dfs(int x,int y)
{
    int X=x,Y=y;
    a[x][y]='.';
    sum--;
    while(sum>0&&y<=c-1)
    {
        a[x][++y]='.';
        sum--;
    }
    x=X;y=Y;
    while(sum>0&&x<=r-1)
    {
        a[++x][y]='.';
        sum--;
    }
    x=X;y=Y;
    if(sum>0)
    {
        dfs(x+1,y+1);
    }
}
int main(int argc,char *argv[])
{
    freopen("C-large.in","r",stdin);
    freopen("CC.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d %d %d",&r,&c,&m);
        printf("Case #%d:\n",cas);
        if(r==1)
        {
            for(int i=1;i<=m;i++) printf("*");
            for(int i=m+1;i<=c-1;i++) printf(".");
            printf("c\n");
        }
        else if(c==1)
        {
            for(int i=1;i<=m;i++) printf("*\n");
            for(int i=m+1;i<=r-1;i++) printf(".\n");
            printf("c\n");
        }
        else if(r==2)
        {
            if((m<=c*2-4&&m%2==0)||(m==r*c-1))
            {
                if(m==r*c-1)
                {
                    for(int i=1;i<=r;i++)
                        for(int j=1;j<=c;j++)
                            a[i][j]='*';
                    a[1][1]='c';
                    for(int i=1;i<=r;i++)
                    {
                        for(int j=1;j<=c;j++)
                            printf("%c",a[i][j]);
                        printf("\n");
                    }
                }
                else
                {
                    m/=2;
                    for(int i=1;i<=r;i++)
                    {
                        for(int j=1;j<=c-m;j++)
                            a[i][j]='.';
                        for(int j=c-m+1;j<=c;j++)
                            a[i][j]='*';
                    }
                    a[1][1]='c';
                    for(int i=1;i<=r;i++)
                    {
                        for(int j=1;j<=c;j++)
                            printf("%c",a[i][j]);
                        printf("\n");
                    }
                }
            }
            else printf("Impossible\n");
        }
        else if(c==2)
        {
            if((m<=r*2-4&&m%2==0)||(m==r*c-1))
            {
                if(m==r*c-1)
                {
                    for(int i=1;i<=r;i++)
                        for(int j=1;j<=c;j++)
                            a[i][j]='*';
                    a[1][1]='c';
                    for(int i=1;i<=r;i++)
                    {
                        for(int j=1;j<=c;j++)
                            printf("%c",a[i][j]);
                        printf("\n");
                    }
                }
                else
                {
                    m/=2;
                    for(int i=1;i<=c;i++)
                    {
                        for(int j=1;j<=r-m;j++)
                            a[j][i]='.';
                        for(int j=r-m+1;j<=r;j++)
                            a[j][i]='*';
                    }
                    a[1][1]='c';
                    for(int i=1;i<=r;i++)
                    {
                        for(int j=1;j<=c;j++)
                            printf("%c",a[i][j]);
                        printf("\n");
                    }
                }
            }
            else printf("Impossible\n");
        }
        else
        {
            sum=r*c-m;
            for(int i=1;i<=r;i++)
                for(int j=1;j<=c;j++)
                    a[i][j]='*';
            a[1][1]='c';
            if(sum==1)
            {
                for(int i=1;i<=r;i++)
                {
                    for(int j=1;j<=c;j++)
                        printf("%c",a[i][j]);
                    printf("\n");
                }
            }
            else if(sum==2||sum==3) printf("Impossible\n");
            else
            {
                sum-=4;
                a[1][2]=a[2][1]=a[2][2]='.';
                if(sum==0)
                {
                    for(int i=1;i<=r;i++)
                    {
                        for(int j=1;j<=c;j++)
                            printf("%c",a[i][j]);
                        printf("\n");
                    }
                }
                else if(sum==1||sum==3) printf("Impossible\n");
                else if(sum==2) {a[1][3]=a[2][3]='.';for(int i=1;i<=r;i++){for(int j=1;j<=c;j++) printf("%c",a[i][j]);
                        printf("\n");} }
                else {
                    
                    a[1][3]=a[2][3]=a[3][1]=a[3][2]='.';
                    sum-=4;
                    int t1=2,t2=2;
                    while(sum>0)
                    {
                        while(sum>=2&&t2<=c-2)
                        {
                            a[t1][t2+1+1]=a[t1-1][t2+1+1]='.';
                            sum-=2;
                            t2++;
                            
                        }
                        t1=t2=2;
                        
                        while(sum>=2&&t1<=r-2)
                        {
                            a[t1+1+1][t2]=a[t1+1+1][t2-1]='.';
                            sum-=2;
                            t1++;
                        }
                        t1=t2=2;
                        break;
                    }
                    if(sum>0)
                    while(sum>0)
                    {
                        t1=t2=3;
                        
                        dfs(t1,t2);
                        
                        for(int i=1;i<=r;i++)
                        {
                            for(int j=1;j<=c;j++)
                                printf("%c",a[i][j]);
                            printf("\n");
                        }
                    }
                    else
                    {
                       for(int i=1;i<=r;i++)
                        {
                            for(int j=1;j<=c;j++)
                                printf("%c",a[i][j]);
                            printf("\n");
                        } 
                    }
                }
            }
        }
    }
    return 0;
}

