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
    freopen("B-large.in","r",stdin);
    freopen("B-output.txt","w",stdout);
    int T;
    cin>>T;
    rep(tt,T)
    {
        ll e,r,n;
        cin>>e>>r>>n;
        r=min(e,r);
        vector<ll> v(n);
        rep(i,n)cin>>v[i];
        vector<ll> p;
        vector<ll> w;
        p.pb(v[0]);
        w.pb(e);
        for(int i=1;i<n;i++)
        {
            ll tmp=r;
            for(int j=p.size()-1;j>=0;j--)
            {
                if(p[j]<v[i]&&tmp<e)
                {
                    if(w[j]+tmp<=e)
                    {
                        tmp+=w[j];
                        p.pop_back();
                        w.pop_back();
                    } else 
                    {
                        w[j]-=e-tmp;
                        tmp=e;
                        break;
                    }
                }
            }
            p.pb(v[i]);
            w.pb(tmp);
        }
        ll ans=0;
        rep(i,p.size())ans+=w[i]*p[i];
        printf("Case #%d: ",tt+1);
        cout<<ans<<endl;
    }
}
