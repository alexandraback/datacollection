#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;


int t;
int n;
int m;

int p[111][61];
int dir[61];
int map[61][61];
int g[111];

int used[111];
int ans[61];

bool draw(int line,int xx)
{
    int i,j;
    
    for(i=1;i<=n;i++)
    {
        if(map[line-1][i]>=p[xx][i])
        {
            break;
        }
        map[line][i]=p[xx][i];
    }
    
    if(i<=n)return false;
    return true;
}


bool check()
{
    int i,j,k;
    bool rev[111];
    for(i=1;i<=m;i++)
    {
        rev[i]=used[i];
    }
    bool has_ans=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(used[j]==1)continue;
            
            for(k=1;k<=n;k++)
            {
                if(map[k][i]!=p[j][k])break;
            }
            
            if(k>n)
            {
                used[j]=1;
                break;
            }
        }
        
        if(j>m)
        {
            if(has_ans==1)
            {
                for(j=1;j<=m;j++)
                {
                    used[j]=rev[j];
                }
                return false;
            }
            else
            {
                has_ans=1;
                for(j=1;j<=n;j++)
                {
                    ans[j]=map[j][i];
                }
            }
        }
    }
    
    for(j=1;j<=m;j++)
    {
        used[j]=rev[j];
    }
    
    return true;
}


bool dfs(int now)
{
    int i,j,k;
    /*
    cout<<now<<endl;
    for(i=1;i<=now;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<map[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    
    if(now==n+1)
    {
        if(check()==true)
        {
            return true;
        }
    }
    
    
    for(i=1;i<=m;i++)
    {
        if(used[i]==0)
        {
            if(draw(now,i)==true)
            {
                used[i]=1;
                if(dfs(now+1)==true)
                {
                    return true;
                }
                used[i]=0;
            }
        }
    }
    return false;
}

int main()
{
    int i,j,k,times;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    cin>>t;
    
    for(times=1;times<=t;times++)
    {
        cin>>n;
        m=2*n-1;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>p[i][j];
            }
        }
        
        
        for(i=1;i<=n;i++)
        {
            dir[i]=999999;
        }
        memset(map,-1,sizeof(map));
        memset(g,0,sizeof(g));
        for(i=1;i<=n;i++)
        {
             for(j=1;j<=m;j++)
             {
                 if(g[j]==0)
                 {
                     dir[i]=min(dir[i],p[j][i]);
                 }
             }
             
             for(j=1;j<=m;j++)
             {
                 if(p[j][i]==dir[i])
                 {
                     g[j]=i;
                 }
             }
        }
        memset(used,0,sizeof(used));
        dfs(1);
        
        cout<<"Case #"<<times<<":";
        for(i=1;i<=n;i++)
        {
            cout<<' '<<ans[i];
        }
        cout<<endl;
    }
    
    
    
    return 0;
}
