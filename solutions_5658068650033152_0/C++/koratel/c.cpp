#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int INF = 1 << 30;
const double EPS = 1e-8;

char t[30][30], bylo[30][30];
int n, m, k;

void dfs(int i, int j)
{
    if(bylo[i][j]) return;
    bylo[i][j]=1;
    for(int x=-1; x<2; x++)
    {
        for(int y=-1; y<2; y++)
        {
            if(x*y) continue;
            int ii=i+x, jj=j+y;
            if(ii<0 || jj<0) continue;
            if(ii>=n || jj>=m) continue;
            if(t[ii][jj]) continue;
            dfs(ii, jj);
        }
    }
}

int sprawdz(int mask)
{
    int ile=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int cur=i*m+j;
            if(mask&(1<<cur))
            {
                t[i][j]=1;
                ile++;
            }
            else t[i][j]=0;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++) bylo[i][j]=0;
    }
    for(int i=0; i<n; i++)
    {
        if(!t[i][0]) dfs(i, 0);
        if(!t[i][m-1]) dfs(i, m-1);
    }
    for(int j=0; j<m; j++)
    {
        if(!t[0][j]) dfs(0, j);
        if(!t[n-1][j]) dfs(n-1, j);
    }
    int zamkniete=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!bylo[i][j]) zamkniete++;
        }
    }
    if(zamkniete>=k) return ile;
    return k;
}

void solve(int num)
{
    cin>>n>>m>>k;
    int ans=k;
    for(int i=0; i<(1<<(n*m)); i++)
    {
        ans=min(ans, sprawdz(i));
    }
    cout<<"Case #"<<num<<": "<<ans<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}

