#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define uint unsigned int

typedef pair<int,int> pii;
#define x first
#define y second

#define read(n) scanf("%d",&n)
#define readll(n) scanf("%lld",&n)
#define read2(n,m) scanf("%d%d",&n,&m)
#define read3(n,m,l) scanf("%d%d%d",&n,&m,&l)

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,a,b)   for(int i=a;i<b;i++)
#define rf(i,n)     for(int i=n-1;i>=0;i--)

#define init(mem,v) memset(mem,v,sizeof(mem))

#define DB(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DB2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DB3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
#define DB4(a, b, c, d)    cout<<__LINE__<<" :: "<<#a<< ": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;

int n,m,k;
bool grid[50][50];
bool vis[50][50];

void init_grid(uint mask){
    fr(i,n) fr(j,m) if(mask & 1<<(m*i+j)){
        grid[i][j]=true;
    }
    else{
        grid[i][j]=false;
    }
}

void dfs(int i,int j){
    if(i<0 or j<0 or i>=n or j>=m or grid[i][j] or vis[i][j]) return;
    vis[i][j]=true;
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}

bool solve(uint mask){
    init_grid(mask);
    fr(i,n) fr(j,m) vis[i][j]=false;

    fr(i,n) fr(j,m) if(i==0 or i==n-1 or j==0 or j==m-1) dfs(i,j);

    int ans=0;
    fr(i,n) fr(j,m) if(!vis[i][j]) ans++;
    return (ans>=k);
}

int main(){
    int t;
    read(t);
    frr(ii,1,t+1){
        read3(n,m,k);

        uint mask=0;
        int ans=n*m;
        while(mask < (1<<(n*m))){
            if(solve(mask)) ans=min(ans,__builtin_popcount(mask));
            mask++;
        }
        printf("Case #%d: %d\n",ii,ans);
    }
}
