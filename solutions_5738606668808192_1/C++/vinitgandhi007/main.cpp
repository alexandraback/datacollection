/*
 * Vinit Gandhi
 * L.D. College of Engineering
 */
#include <bits/stdc++.h>
#if __cplusplus>199711L
    #define typeof decltype
#endif
#define IOS  ios_base::sync_with_stdio(false), cin.tie(0)
#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second
#define ll   long long
#define ull  unsigned long long
#define ld   long double
#define SIGN(x) (((x)>0)-((x)<0))
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a)   ((ll)(a).size())
#define FILL(a,x)   memset(a, (x), sizeof((a)));
#define IN(l,i,r)   ((l)<(i)&&(i)<(r))
#define LIN(l,i,r)  ((l)<=(i)&&(i)<(r))
#define INR(l,i,r)  ((l)<(i)&&(i)<=(r))
#define LINR(l,i,r) ((l)<=(i)&&(i)<=(r))
#define cmp_db(a,b) (abs(b-a)<eps)
#define is_int(a)   (cmp(a,0))
#define FOR(i,b,e,s)  for(i=(b);SIGN(s)*i<SIGN(s)*(e);i+=(s))
#define FORE(it,a)    for(typeof((a).begin())it=(a).begin();it!=(a).end();it++)
#define PRESENT(c,x)  ((c).find(x)!=(c).end())
#define CPRESENT(c,x) (find(ALL(c),x)!=(c).end())
#define nl         cout<<'\n'

using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const ll mod=1e9+7;
const ld pi=acos(-1.0);
const ld eps=1e-9;
const int dX[]={-1, 1, 0, 0,-1, 1,-1, 1};
const int dY[]={ 0, 0,-1, 1, 1,-1,-1, 1};

template<class S, class T> ostream& operator<<(ostream& o,pair<S,T>& a)  {o<<a.FI<<" "<<a.SE; return o;}
template<class S, class T> ostream& operator<<(ostream& o,map<S,T>& a)   {FORE(it,a) o<<(*it)<<"\n"; return o;}
template<class S> ostream& operator<<(ostream& o,vector<S>& a)           {FORE(it,a) o<<*it<<" "; return o;}
template<class S> ostream& operator<<(ostream& o,vector<vector<S> >& a)  {FORE(it,a) {o<<(*it)<<"\n";} return o;}
template<class S> ostream& operator<<(ostream& o,set<S>& a)              {FORE(it,a) o<<*it<<" "; return o;}
const ll MAX=11;
int a[MAX], ans[MAX];
ll mod_pow(ll b, ll e, ll m=mod)
{
    ll s=1;
    while(e)
    {
        if(e%2)
            s=(s*b)%m;
        b=(b*b)%m;
        e/=2;
    }
    return s;
}
int find_factor(ull x, ull b) //finds factor of x in base b
{
    FILL(a,0);
    ll i, j;
    for(i=63; i>=0; i--)
    {
        if(((x>>i)&1))
        {
            for(j=2; j<MAX; j++)
                a[j]+=mod_pow(b,i,j);
        }
    }
    for(j=2; j<MAX; j++)
    {
        if(a[j]%j==0)
            return j;
    }
    return -1;

}
int main()
{
    IOS;
    int i, j, T, f;
    ull J, N, start, cnt=0;
    string s;
    cin>>T;
    FOR(i,0,T,1)
    {
        cout<<"Case #"<<i+1<<":\n";
        cin>>J>>N;
        start=(1L<<(J-1))+1;
        while(cnt<N)
        {
            f=1;
            for(j=2; j<MAX; j++)
            {
                ans[j]=find_factor(start, j);
                if(ans[j]==-1)
                    f=0;
            }
            if(f)
            {
                for(j=J-1; j>=0; j--)
                {
                    if(((start>>j)&1))
                        cout<<"1";
                    else
                        cout<<"0";
                }
                cout<<" ";
                for(j=2; j<MAX; j++)
                    cout<<ans[j]<<" ";
                nl;
                cnt++;
            }
            start+=2;
        }
    }
    return 0;
}
