#include <bits/stdc++.h>

using namespace std;

int get(int mask,int num)
{
    return (mask>>num)&1;
}

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

vector<vector<int>> color;

void dfs(int x,int y,int c)
{
    int n=color.size();
    int m=color[0].size();
    color[x][y]=c;
    for(int i=0;i<4;i++)
        if(x+dx[i]>=0 && y+dy[i]>=0 && x+dx[i]<n && y+dy[i]<m && !color[x+dx[i]][y+dy[i]]) dfs(x+dx[i],y+dy[i],c);
}

int check(int mask,int n,int m)
{
    color.assign(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            color[i][j]=42*get(mask,i*m+j);

    int c=1;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!color[i][j]) dfs(i,j,c++);

    vector<int> colors(43,0);
    vector<int> color_ok(43,1);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            colors[color[i][j]]++;

    for(int i=0;i<n;i++)
            color_ok[color[i][0]]=0,
            color_ok[color[i][m-1]]=0;
    for(int i=0;i<m;i++)
            color_ok[color[0][i]]=0,
            color_ok[color[n-1][i]]=0;

    color_ok[42]=1;

    int ans=0;
    for(int i=0;i<43;i++)
        ans+=colors[i]*color_ok[i];
    return ans;

}

main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    for(int test=0;test<T;test++)
    {
        cout<<"Case #"<<test+1<<": ";

        int n,m,k;
        cin>>n>>m>>k;

        int mi=20;
        for(int i=0;i<(1<<n*m);i++)
        {
            int ones=__builtin_popcount(i);
            if(ones<mi && check(i,n,m)>=k)
                mi=ones;
        }
        cout<<mi<<endl;
    }
}
