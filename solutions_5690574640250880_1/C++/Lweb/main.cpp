#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;
typedef long long LL;
int ans[55][55];

inline void solve(int n,int m,int x,int y,int ax,int ay)
{
    memset(ans,0,sizeof(ans));
    for(int i=0;i<x;++i) for(int j=0;j<y;++j) ans[i][j]=1;
    for(int i=0;i<ax;++i) ans[i][y]=1;
    for(int i=0;i<ay;++i) ans[x][i]=1;
    ans[0][0]=2;
}

inline void output(int n,int m)
{
    for(int i=0;i<n;++i,puts("")) for(int j=0;j<m;++j)
    {
        if(ans[i][j]==1) putchar('.');
        else if(ans[i][j]==0) putchar('*');
        else putchar('c');
    }
}

int main()
{
    int T;
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    scanf("%d",&T);
    //for(int n=1;n<=5;++n) for(int m=1;m<=5;++m) for(int cc=0;cc<m*n;++cc)
    for(int ca=1;ca<=T;++ca)
    {
        int n,m,C;
        scanf("%d%d%d",&n,&m,&C);
        printf("Case #%d:\n",ca);
        if(n==1||m==1)
        {
            for(int i=0;i<n;++i,puts("")) for(int j=0;j<m;++j)
            {
                if(C) putchar('*'),--C;
                else putchar(i==n-1&&j==m-1?'c':'.');
            }
            continue;
        }
        if(C+1==n*m)
        {
            for(int i=0;i<n;++i,puts("")) for(int j=0;j<m;++j)
            {
                if(C) putchar('*'),--C;
                else putchar('c');
            }
            continue;
        }
        if(n==2||m==2)
        {
            if(C&1)
            {
                puts("Impossible");
                continue;
            }
            if(C>=n*m-2)
            {
                puts("Impossible");
                continue;
            }
            if(m==2)
            {
                for(int i=0;i<n;++i)
                {
                    if(C) ans[i][0]=ans[i][1]=0,C-=2;
                    else ans[i][0]=ans[i][1]=1;
                }
                ans[n-1][1]=2;
            }
            else if(n==2)
            {
                for(int i=0;i<m;++i)
                {
                    if(C) ans[0][i]=ans[1][i]=0,C-=2;
                    else ans[0][i]=ans[1][i]=1;
                }
                ans[0][m-1]=2;
            }
            output(n,m);
            continue;
        }
        if(C>n*m-4)
        {
            puts("Impossible");
            continue;
        }
        int last=n*m-C;
        bool fg=0;
        for(int i=2;!fg&&i<=n;++i) for(int j=2;!fg&&j<=m;++j)
        {
            if(i*j>last) break;
            int yu=last-i*j;
            if(yu==1) continue;
            for(int x=0;x<i;++x)
            {
                if(x==1) continue;
                if(x&&j==m) continue;
                int y=yu-x;
                if(y&&i==n) continue;
                if(y!=1&&y<j)
                {
                    solve(n,m,i,j,x,y);
                    fg=1;
                    break;
                }
            }
        }
        if(!fg) puts("Impossible");
        else output(n,m);
    }
    return 0;
}

