#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					cin>>n
#define p(n)					cout<<n<<'\n'
#define sd(n)					int n;cin>>n;
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define mp(a,b)                                 make_pair(a,b)
#define ps(str)                                 cout<<str<<'\n'
#define pans(t,ans)                             do{cout<<"Case #"<<t<<": "<<ans<<endl;} while(0)

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX
#define PI 3.14159265358979323846

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int> > > TG;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int pow2(ll a)
{
    int ans=0;
    ll p=1;
    while (p<a)
    {
        p*=2LL;
        ans++;
    }
    if (p==a) return ans;
    return -1;
}

int solve(ll p,ll q)    //q is a power of 2
{
    ll m=2;
    int ans=1;
    while (true)
    {
        if (m*p>=q) return ans;
        m*=2;
        ans++;
    }
}

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    sd(T);
    int i,j,t;
    FOR(t,0,T)
    {
        string str;
        cin>>str;
        int n=sz(str);
        i=0;
        ll p=0,q=0;
        while (str[i]!='/')
        {
            p=(p*10LL)+(ll)(str[i++]-'0');
        }
        i++;
        while (i<n) q=(q*10LL)+(ll)(str[i++]-'0');
//        cout<<p<<' '<<q<<endl;
        ll g=__gcd(p,q);
        p/=g;q/=g;
        int ret=pow2(q);
        if (ret>=0) pans(t+1,solve(p,q));
        else pans(t+1,"impossible");
    }
}
