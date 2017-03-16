#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;

long long two[60];
long long b,m;
int t;

long long g[111];
int n;
int map[111][111];

int main()
{
    int i,j,k,times;
    freopen("B-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    
    two[0]=1;
    for(i=1;i<=51;i++)
    {
        two[i]=two[i-1]*2ll;
    }
    
    
    cin>>t;
    
    for(times=1;times<=t;times++)
    {
        cin>>b>>m;
        cout<<"Case #"<<times<<": ";
        if(two[b-2]<m)
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"POSSIBLE"<<endl;
        
        memset(map,0,sizeof(map));
        
        n=0;
        while(m!=0)
        {
            n++;
            if(m%2==1)
            {
                g[n]=1;
            }
            else
            {
                g[n]=0;
            }
            m/=2;
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n+1;j++)
            {
                map[i][j]=1;
            }
        }
        
        for(i=1;i<=n;i++)
        {
            if(g[i]==1)
            {
                if(i+1!=b)
                {
                    map[i+1][b]=1;
                }
            }
        }
        
        
        for(i=1;i<=b;i++)
        {
            for(j=1;j<=b;j++)
            {
                cout<<map[i][j];
            }
            cout<<endl;
        }
    }
    
    
    
    return 0;
}
