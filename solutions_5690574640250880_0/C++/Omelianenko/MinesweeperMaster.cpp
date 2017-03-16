#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>

using namespace std;

#define ll long long

bool flag;
int i, j, t, num, color[10][10], used[10][10], f, r, c, m, a[10][10], sum, b[36];

int getfriends(int x, int y)
{
    int s=0;
    s=a[x-1][y]
     +a[x+1][y]
     +a[x][y+1]
     +a[x][y-1]
     +a[x+1][y+1]
     +a[x-1][y+1]
     +a[x+1][y-1]
     +a[x-1][y-1];
    return s;
}

void dfs(int x, int y, int C)
{
    f++;
    used[x][y]=C;
    color[x][y]=getfriends(x, y);
    if(color[x][y]==0)
    {
        if(x+1<=r&&used[x+1][y]!=C)dfs(x+1, y, C);
        if(x-1>=1&&used[x-1][y]!=C)dfs(x-1, y, C);
        if(y+1<=c&&used[x][y+1]!=C)dfs(x, y+1, C);
        if(y-1>=1&&used[x][y-1]!=C)dfs(x, y-1, C);
        if(x+1<=r&&y+1<=c&&used[x+1][y+1]!=C)dfs(x+1, y+1, C);
        if(x+1<=r&&y-1>=1&&used[x+1][y-1]!=C)dfs(x+1, y-1, C);
        if(x-1>=1&&y+1<=c&&used[x-1][y+1]!=C)dfs(x-1, y+1, C);
        if(x-1>=1&&y-1>=1&&used[x-1][y-1]!=C)dfs(x-1, y-1, C);
    }
}

void rec(int d, int x)
{
    b[d]=x;
    sum+=x;
    if(sum==m&&d==r*c)
    {
        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
                a[i][j]=b[(i-1)*c+j];
        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
                if(a[i][j]==0)
                {
                    f=0;
                    int q=i;
                    int w=j;
                    dfs(i, j, (i-1)*c+j);
                    if(r*c-f==m)
                    {
                        for(int i=1; i<=r; i++)
                        {
                            for(int j=1; j<=c; j++)
                                if(i==q&&w==j)cout<<"c"; else
                                if(a[i][j])cout<<"*"; else cout<<".";
                            cout<<endl;
                        }
                        flag=1;
                        if(flag)return;
                    }
                }
    } else
    if(d<r*c)
    {
        rec(d+1, 0);
        if(flag)return;
        if(sum!=m)rec(d+1, 1);
        if(flag)return;
    }
    sum-=x;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    cin>>t;
    while(t--)
    {
        sum=0;
        flag=0;
        cin>>r>>c>>m;
        for(i=0; i<=r+1; i++)
            for(j=0; j<=c+1; j++)
            {
                used[i][j]=0;
                a[i][j]=0;
            }
        cout<<"Case #"<<++num<<":"<<endl;
        rec(0, 0);
        if(!flag)cout<<"Impossible"<<endl;
    }
}
