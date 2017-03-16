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

ll nwd(ll a, ll b) { return (b ? nwd(b, a%b) : a); }

void solve(int num)
{
    ll p=0, q=0;
    string s;
    cin>>s;
    int pos=0;
    for(; s[pos]!='/'; pos++) p=p*ll(10)+ll(s[pos]-'0');
    pos++;
    for(; pos<s.length(); pos++) q=q*ll(10)+ll(s[pos]-'0');
    ll meh=nwd(p,q);
    p/=meh;
    q/=meh;
    int fail=0, ans=1;
    ll dwa=1;
    while(dwa<q) dwa*=ll(2);
    if(dwa!=q) fail=1;
    else
    {
        while(q/ll(2)>p)
        {
            ans++;
            q/=ll(2);
        }
    }
    cout<<"Case #"<<num<<": ";
    if(fail) cout<<"impossible\n";
    else cout<<ans<<"\n";

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

