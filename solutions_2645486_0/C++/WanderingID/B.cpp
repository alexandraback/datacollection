#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <utility>
#include <cstdlib>
#include <cassert>

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define EPS 1e-9

using namespace std;

typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef unsigned long long ll;

ll cal(ll n, ll r)
{
    return 2*n*n-n+2*r*n;
}

ll min(ll a, ll b)
{
    return a<b?a:b;
}

int main()
{
    freopen("B-small.in","r",stdin);
    freopen("B-output.txt","w",stdout);
    int T;
    cin>>T;
    rep(tt,T)
    {
        int e,r,n;
        cin>>e>>r>>n;
        r=min(e,r);
        vector<vi> f(n+1,vi(e+1,-1));
        vi v(n+1);
        rep(i,n)cin>>v[i+1];
        f[0][e]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=r;j<=e;j++)
            {
                for(int k=r;k<=e;k++)
                {
                    if(k-j+r>=0&&f[i-1][k]>=0)f[i][j]=max(f[i][j],f[i-1][k]+(k-j+r)*v[i]);
                }
            }
        }
        printf("Case #%d: ",tt+1);
        cout<<f[n][r]<<endl;
    }
}
