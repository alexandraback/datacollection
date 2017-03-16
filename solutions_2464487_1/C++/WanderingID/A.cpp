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
    freopen("A-large.in","r",stdin);
    freopen("A-output.txt","w",stdout);
    int T;
    cin>>T;
    rep(tt,T)
    {
        ll r,t;
        cin>>r>>t;
        ll mi=1,ma=min(sqrt(t/2+1),t/r/2+1);
        //cout<<cal(2,1)<<endl;
        while(mi<ma)
        {
            ll mid=(mi+ma+1)/2;
            ll res=cal(mid,r);
            if(res<=t)mi=mid;
            else ma=mid-1;
        }
        printf("Case #%d: ",tt+1);
        cout<<ma<<endl;
    }
}
