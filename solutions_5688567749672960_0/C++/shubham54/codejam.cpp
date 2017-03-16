#include <cstdio>
#include <queue>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int rev(int x)
{
    int reve=0;
    for(;x!=0;)
    {
        reve=reve *10;
        reve=reve+x%10;
        x/=10;
    }
    return reve;
}

int d[1234567];

int main()
{
    freopen("file.in", "r", stdin);
    freopen("shubham.txt", "w", stdout);
    int n,m,t;
    int g=0;
    scanf("%d",&t);
    while(t--)
    {
        queue<int> q;
        memset(d,0,sizeof(d));
        scanf("%d",&m);
        if(m<10)
            cout<<"Case #"<<++g<<": "<<m<<endl;
        else
        {
            n=10;
            d[n]=0;
            q.push(n);
            while(!q.empty())
            {
                int x=q.front();
                q.pop();
                if(x==m) break;
                if(x<m && !d[rev(x)])
                {
                    d[rev(x)]=d[x]+1;
                    q.push(rev(x));
                }
                if(x>1 && !d[x+1])
                {
                    d[x+1]=d[x]+1;
                    q.push(x+1);
                }
            }
            cout<<"Case #"<<++g<<": "<<(d[m]+10)<<endl;
           // printf("%d\n",(d[m]+10));
        }
    }
    return 0;
}
