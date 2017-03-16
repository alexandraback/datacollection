#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl
#define dbgv(x,i) cout<<#x<<"["<<i<<"]: "<< x[i]<<endl
#define maxx 99999999
#define minn -99999999
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define mod 1000000007
#define f(i,a,b) for(i = a; i < b; i++)
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define pii pair< int,int >
#define sc(n) scanf("%lld",&n)
//#define gc getchar_unlocked
//void sc(int &x){register int c = gc();x = 0;int neg = 0;for(;((c<48 || c>57) && c != '-');c = gc());if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
//#define pc(x) putchar_unlocked(x)
//void prc(int n){int N = n, rev, count = 0;rev = N;if (N == 0) { pc('0'); pc('\n'); return ;}while ((rev % 10) == 0) { count++; rev /= 10;} rev = 0;while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}while (count--) pc('0');}
vector <ll> vi;
bool v[1000005];
ll tryrev(ll n)
{
    vi.clear();
    ll x = 1,c = 0;
    ll a[20];
    while(n)
    {
        vi.PB(n%10);
        n /= 10;
    }
    reverse(all(vi));
    int i;
    f(i,0,sz(vi))
    {
        c += (vi[i] * x);
        x *= 10;
    }
    return c;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("out.out","w",stdout);
    #endif
    ll t,n,i,cur,temp;
    sc(t);
    f(i,0,t)
    {
        sc(n);
        queue <pii> Q;
        memset(v,0,sizeof(v));
        Q.push(pii(1,1));
        v[1] = true;
        ll sol = 0;
        while(!Q.empty())
        {
            cur = Q.front().ff;
            temp = Q.front().ss;
            Q.pop();
            if(cur == n)    {sol = temp; break;}
            if(cur + 1 <= n && v[cur + 1] == false)
            {
                v[cur + 1] = true;
                Q.push(pii(cur + 1, temp + 1));
            }
            ll t2 = tryrev(cur);
            if(t2 <= n && v[t2] == false)
            {
                v[t2] = true;
                Q.push(pii(t2, temp + 1));
            }
        }
        printf("Case #%lld: %lld\n",i+1,sol);
    }
    return 0;
}
