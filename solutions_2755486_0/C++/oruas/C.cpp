#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,a,n) for(int i=(a);i<(n);i++)
#define dec(i,n) for(int i=(n);i>0;i--)
#define decc(i,a,n) for(int i=(a);i>(n);i--)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))
#define mem(a,b) memset((a),(b),sizeof(a))
#define clr(a) mem(a,0)
const double pi=acos(-1.0);
const int inf=100000000;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef vector< string > VS;
typedef vector< ll > VLL;
#define eps 1e-9
//main code starts here
#define maxd 676065
#define max 10005
int arr[max];
int tarr[max];
struct info
{
    int l,r,h;
    info(){}
    info(int a, int b, int c){l=a,r=b,h=c;}
};
vector<info>vv[maxd];
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t,cas=1;
    int N,n,l,r,h,d,dd,dp,dh;
    int minl;
    cin>>t;
    while(t--)
    {
        cin>>N;
        rep(i,maxd)vv[i].clear();
        minl=inf;
        while(N--)
        {
            cin>>d>>n>>l>>r>>h>>dd>>dp>>dh;
            l*=3;
            l++;
            r*=3;
            r++;
            dp*=3;
            vv[d].pb(info(l,r,h));
            minl=min(minl,l);
            rep(i,n-1)
            {
                d+=dd;
                l+=dp;
                r+=dp;
                h+=dh;
                vv[d].pb(info(l,r,h));
                minl=min(minl,l);
            }
        }
        minl=-minl;
        clr(arr);
        clr(tarr);
        int maxr=0;
        int ans=0;
        rep(d,maxd)
        {
            if(sz(vv[d]))rep(i,maxr+1)tarr[i]=arr[i];
            rep(k,sz(vv[d]))
            {
                l=vv[d][k].l+minl;
                r=vv[d][k].r+minl;
                h=vv[d][k].h;
                maxr=Max(maxr,r);
                bool ok=0;
                repp(i,l,r+1)
                {
                    if(arr[i]<h)ok=1;
                    tarr[i]=Max(tarr[i],h);
                }
                if(ok)ans++;
            }
            if(sz(vv[d]))rep(i,maxr+1)arr[i]=tarr[i];
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
	return 0;
}
