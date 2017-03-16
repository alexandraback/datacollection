using namespace std;
#include<bits/stdc++.h>

#define BG begin()
#define ED end()
#define st first
#define nd second
#define PB push_back
#define PF push_front
#define FOR(i,a,b) for (long long i=a;i<b;i++)
#define FORE(i,a,b) for (long long i=a;i<=b;i++)
#define FORD(i,a,b) for (long long i=a;i>=b; i--)
#define ri(n)({\
    int neg=0;\
    n=0;\
    char ch;\
    for(ch=getchar(); ch<'0' || ch>'9'; ch=getchar()) if (ch=='-') neg=1-neg;\
    n=ch-48;\
    for(ch=getchar(); ch>='0' && ch<='9'; ch=getchar()) n=(n<<3)+(n<<1)+ch-48;\
    if (neg) n=-n;\
})

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<ll,ll> LL;
const ll INF=1000000;
const double esp=1e-13;
const double pi=3.141592653589;

ll canhai(ll n)
{
    ll fi,la,mid;
    fi=0;
    la=n+1;
    while (fi+1<la)
    {
        mid=fi/2+la/2;
        if (fi%2 && la%2) mid++;
        if (mid>n/mid) la=mid;
        else fi=mid;
    }
    return fi;
}

int rev(int n)
{
    int m=0;
    while (n)
    {
        m=m*10+n%10;
        n/=10;
    }
    return m;
}

bool f[INF+10];
int n,dem,ans[INF+10],u,d,test;
queue<int> q;

int main()
{
    freopen("codeforces.inp", "r", stdin);
    freopen("8224486.out", "w", stdout);
    memset(f,true,sizeof(f));
    FORE(i,2,INF) f[i]=false;
    ans[1]=1;
    dem=1;
    q.push(1);
    while (dem<INF)
    {
        u=q.front();
        q.pop();
        if (!f[u+1])
        {
            ans[u+1]=ans[u]+1;
            q.push(u+1);
            f[u+1]=true;
            dem++;
        }

        d=rev(u);
        if ( !f[d] )
        {
            ans[d]=ans[u]+1;
            q.push(d);
            f[d]=true;
            dem++;
        }
    }
    dem=0;
    cin >> test;
    while (test--)
    {
        dem++;
        cin >> n;
        cout << "Case #" << dem << ": " << ans[n] << "\n";
    }
}

