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

void solve(int num)
{
    ll n;
    cin >> n;
    //cout<<">> "<<n<<endl;

    ll ans=0;
    if(n<=20)
    {
        ans=n;
    }
    else
    {
        if(n%10==0)
        {
            n--;
            ans=1;
        }

        ll dd=10;
        ans+=10;
        int k=2;
        while(dd*10LL<n)
        {
            ans+=dzies(k/2)+dzies((k+1)/2)-1;
            dd*=10;
            k++;
        }

        vector<int> digs;
        ll cur=n;
        while(n)
        {
            digs.pb(n%10);
            n/=10;
        }

        int l=digs.size();

        ll pref=0, suf=0;
        for(int i=(l+1)/2;i<l;i++) pref=pref*10+digs[i];
        for(int i=(l-1)/2;i>=0;i--) suf=suf*10+digs[i];
        //cout<<"dzies "<<ans<<endl;
        //cout<<pref<<" "<<suf<<endl;

        if(pref>1)
        {
            ans+=pref;
        }
        ans+=suf;
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

