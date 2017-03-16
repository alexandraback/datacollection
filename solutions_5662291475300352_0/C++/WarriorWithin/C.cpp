#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Useful constants
#define INF (int)2e9
#define INFL (long long)1e18
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
// Useful container manipulation / traversal macros
#define all(a) a.begin(), a.end()
#define in(a,b) ( (b).find(a) != (b).end())
#define pb push_back
#define fill(a,v) memset(a, v, sizeof a)// fill originally
#define mp make_pair

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define tr(container, it) for(aut(it,container.begin()); it != container.end(); it++)


#define llu long long unsigned
#define ld long


#define DEBUG 1
#define debug(x) {if (DEBUG)cout <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cout <<#x <<" = "; tr((x),it) cout <<*it <<", "; cout <<endl; }}


#define checkbit(n,b) ( (n >> b) & 1)
#define setbit(n,b) (n | ((1 << b)))
#define unsetbit(n,b) (n & (~(1 << b)))
#define rep(i,n) for(int i=0; i<(int)n;i++)
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mod (1000000007L)

//typedef pair<int,pair<int,pair<int,int> > >  pp;

//freopen (fname"in","r",stdin);
//freopen (fname"out","w",stdout);

ll n,b;

int d1,d2,t1,t2;

void solve()
{

    cin>>n;
    int ctr=0;
    ll d,h,m;
    d1=-1;
    rep(i,n)
    {
        cin>>d>>h>>m;
        ctr += h;
        if(h==1)
        {
            if(d1==-1)
            {
                d1 = d;
                t1 = m;
            }
            else
            {
                d2=d;
                t2=m;
            }

        }
        else
        {
            d1 = d;
            t1 = m;
            d2 = d;
            t2 = m+1;
        }
    }

    if(ctr >= 3)
    {
        cout<<0<<endl;
        return;
    }

    if(t1 > t2)
    {
        swap(t1,t2);
        swap(d1,d2);
    }

    double mini=0,maxi=0;

    mini = ((360-(double)d1)/360.00)*((double)t1);
    mini = max(mini, ((360-(double)d2)/360.00)*((double)t2));

    maxi = ((360-(double)d1)/360.00)*((double)t1) + t1;

    //cout<<mini<<" "<<maxi<<endl;
    maxi = min(maxi, (t2 + ((360-(double)d2)/360.00)*((double)t2)));
//    cout<<mini<<" "<<maxi<<endl;

    if(maxi > mini+EPS)
    {
        cout<<0<<endl;
        return ;
    }

    cout<<1<<endl;

}

int main()
{
    int t;
    s(t);

    for(int cno=1;cno<=t;cno++)
    {
        cout<<"Case #"<<cno<<": ";

        solve();

    }
}