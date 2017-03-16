#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    freopen("wtf.in","r+",stdin);
    freopen("out.txt","w+",stdout);
    int T;
    cin>>T;
    for(int e=1;e<=T;++e)
    {
        cout<<"Case #"<<e<<": ";
        int N , i , j  ;
        LL K;
        cin>>N>>K;
        LL upto = (1LL<<N-2);
        if(upto<K)
        {
            cout<<"IMPOSSIBLE\n";
            continue;
        }

        bool adj[N+1][N+1];
        memset(adj,0,sizeof(adj));
        for(i=2;i<=N;++i)
        {
            for(j=i+1;j<=N;++j)
                adj[i][j] = 1;
        }
        if(K==(1LL<<N-2))
        {
            for(j=2;j<=N;++j)
                adj[1][j] = 1;
        }
        else
        {
            for(j=0;j<N-2;++j)
            {
                if((K>>j)&1)
                    adj[1][N-1-j]=1;
            }
        }
        cout<<"POSSIBLE\n";
        for(i=1;i<=N;++i,cout<<'\n')
            for(j=1;j<=N;++j)
                cout<<adj[i][j];
    }
    return 0;
}
