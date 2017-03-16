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

ll dzies(int k)
{
    ll ret=1;
    while(k>0)
    {
        ret*=10;
        k--;
    }
    return ret;
}

int rev(int x)
{
    int ret=0;
    vector<int> digs;
    while(x)
    {
        digs.pb(x%10);
        x/=10;
    }
    for(int i=0;i<(int)digs.size();i++) ret=10*ret+digs[i];
    return ret;
}

void solve(int num)
{
    ll n;
    cin >> n;

    vi ans(n+42,INF);
    ans[0]=0;

    for(int i=1;i<=n;i++)
    {
        ans[i]=ans[i-1]+1;
        //cout<<rev(i)<<" "<<ans[rev(i)]<<endl;
        if(i%10 && rev(i)<=n) ans[i]=min(ans[i],ans[rev(i)]+1);
    }

    cout<<"Case #"<<num<<": "<<ans[n]<<"\n";

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

