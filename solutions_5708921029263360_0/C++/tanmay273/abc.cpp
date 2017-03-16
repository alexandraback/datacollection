#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pl;

#define sl(x) scanf("%I64d",&x)
#define pl(x) printf("%I64d\n",x)
#define sf(x) sort(x.begin(),x.end(),func)
#define s(x) sort(x.begin(),x.end())
#define all(v) v.begin(),v.end()
#define rs(v) { s(v) ; r(v) ; }
#define r(v) {reverse(all(v));}
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define f(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)

const ll mod = 1000000007;
const ll inf = LLONG_MAX;
const ll ninf = LLONG_MIN;
const ld eps = 1e-12;
const ll N = 1000005;
const ll LOGN = 19;

int main()
{
    FILE *fin = freopen("C-small-attempt0.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("B-small-attempt0.out", "w", stdout);
	ll t;
	cin >> t;
	ll tt = 1;
	while(t--)
    {
        ll j,p,s,n;
        ll ans = 0;
        cout << "Case #"<< tt++ << ": ";
        cin >> j >> p >> s >> n;
        for(ll i=1;i<=j;i++)
		{
			ll c=0;
			for(ll y=1;y<=p;y++)
			{
				for(ll k=1;k<=min(s,n);k++)
				{
                    ans++;
					c++;
				}
			}
		}
		cout<<ans<<"\n";
		ll ans2=0;
		for(ll i=1;i<=j;i++)
		{
			ll c=0;
			for(ll y=1;y<=p;y++)
			{
				for(ll k=1;k<=min(s,n);k++)
				{
					if(c==n)
					{
						c=0;
						ans2++;
					}
					cout<<i<<" "<<y<<" "<<k+ans2<<"\n";
					c++;
				}
			}
		}
    }
    return 0;
}
