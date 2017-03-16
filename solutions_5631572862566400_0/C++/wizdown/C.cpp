#include<bits/stdc++.h>
#define scd(x) scanf("%d",&x)
#define prd(x) printf("%d",x)
#define sclld(x) scanf("%lld",&x)
#define prlld(x) printf("%lld",x)
#define f_in(x) freopen(x,"r",stdin)
#define f_out(x) freopen(x,"w",stdout)
#define MAX 1002
using namespace std;

typedef long long int llt;

vector< vector<int> > v;
vector<bool> visited[2];
int n,ans,lastNode;

void dfsFirst(int i,int len=1)
{
    visited[0][i] = true;
    bool leaf = true;
    for( int j = 1 ; j<= n ; j++)
    {
        if(v[i][j]==1 && !visited[0][j])
        {
            leaf = false;
            dfsFirst(j,len+1);
        }
    }
    if(leaf)
    {
        if(len > ans)
        {
            ans = len;
            lastNode = i;
        }
    }
}


void dfsSecond(int i,int len=1)
{
    visited[1][i] = true;
    bool leaf = true;
    for( int j = 1 ; j<= n ; j++)
    {
        if(v[j][i]== 1 && !visited[1][j])
        {
            leaf = false;
            dfsSecond(j,len+1);
        }
    }
    if(leaf)
    {
        if(len > ans)
        {
            ans = len;
            lastNode = i;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    int T,x;
    cin>>T;
    for(int t = 1 ; t<= T ; t++ )
    {
        cin>>n;
        ans = 0;
        visited[0].assign(n+1,false);
        visited[1].assign(n+1,false);
        v.assign(n+1,vector<int>(n+1,0));
        for(int i = 1 ; i<= n ; i++)
        {
            cin>>x;
            v[i][x]=1;
        }
        //graph made
        for(int i =  1; i <= n ; i++ )
        {
            if(!visited[0][i])
            {
                cout<<"Found "<<i<<"\n";
                dfsFirst(i);
                cout<<"first Dfs : "<<"Ans : "<<ans<<" \t LastNode : "<<lastNode<<"\n";
                dfsSecond(lastNode);
                cout<<"Second Dfs : "<<"Ans : "<<ans<<" \t LastNode : "<<lastNode<<"\n";

            }
        }
        cout<<"Case #"<<t<<": "<<ans<<"\n";
        v.clear();
        visited[0].clear();
        visited[1].clear();
    }



    return 0;
}
