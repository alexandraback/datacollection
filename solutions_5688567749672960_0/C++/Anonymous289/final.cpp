#include <bits/stdc++.h>
#include <fstream>
using namespace std;

typedef long long int ll;

ll rev(ll x)
{
    ll reverse1=0;
    for(;x!=0;)
    {
        reverse1*=10;
        reverse1+=x%10;
        x/=10;
    }
    return reverse1;
}

ll dist[1000007];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    ll n,m,T;
    int xxx=1;
    scanf("%lld",&T);
    while(T--)
    {
        queue<ll> q;
        memset(dist,0,sizeof(dist));
        scanf("%lld",&m);
        if(m<10)
        {
            cout<<"Case #"<<xxx++<<": "<<m<<endl;
        }
        else
        {
            n=10;
            dist[n]=0;
            q.push(n);
            while(!q.empty())
            {
                ll x=q.front();
                q.pop();
                if(x==m)
                break;
                if(x<m && !dist[rev(x)])
                {
                    dist[rev(x)]=dist[x]+1;
                    q.push(rev(x));
                }
                if(x>1 && !dist[x+1])
                {
                    dist[x+1]=dist[x]+1;
                    q.push(x+1);
                }
            }
            cout<<"Case #"<<xxx++<<": "<<(dist[m]+10)<<endl;

        }
    }
    return 0;
}
