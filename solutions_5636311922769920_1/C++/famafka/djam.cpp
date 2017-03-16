#include<bits/stdc++.h>
using namespace std;

void go(long long x,long long z,long long k,long long N)
{
    if(k==1)
    {
        cout<<x<<' ';
        return;
    }
    long long newX=(x-1)*N+1;
    if(z<N)
    {
        ++z;
        while(newX%N!=z%N)
            ++newX;
        go(newX,z,k-1,N);
    }else
    {
        go(newX,z,k-1,N);
    }
}

int main()
{
    freopen("jam.in","r",stdin);
    freopen("jam.out","w",stdout);
    int t;
    cin>>t;
    for(int t1=1;t1<=t;t1++)
    {
        cout<<"Case #"<<t1<<": ";
        int N,K,S;
        cin>>N>>K>>S;
        int kol=(N/K);
        if(N%K>0)
            ++kol;
        if(kol>S)
        {
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        for(int i=1;i<=N;i+=K)
        {
            int p=min(N,i+K-1);
            go(i,i,K,N);
        }
        cout<<"\n";
    }
}
