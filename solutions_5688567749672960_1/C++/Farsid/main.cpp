/*
Farsid
BUET
CSE
10
*/

#define filer() freopen("far.in","r",stdin)
#define filew() freopen("far.in","w",stdout)

#include <set>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include <map>
#include<ctime>
#define SET(a, x) memset((a), (x), sizeof(a))
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define i64 ll
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define MAX
#define xx first
#define yy second
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<ll> VL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;

const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


template<class X>void debug(vector<X>&v){for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;}

i64 rev(i64 x)
{
    i64 y=0;
    while(x)
    {
        y*=10;
        y+=(x%10);
        x/=10;
    }
    return y;
}


int main()
{
    //filer();
    freopen("A-large (1).in","r",stdin);
    freopen("A_out.out","w",stdout);
    i64 i,j,k ,T,cas=0;
    scanf("%lld",&T);
    while(T--)
    {
        i64 N,n,n_dig,cnt=0;
        cin>>N;
        if(N<=19)
        {
            printf("Case #%lld: %lld\n",++cas,N);
            continue;
        }
        n=N;
        while(n)
        {
            cnt++;
            n/=10;
        }
        n_dig=cnt;
        //cout<<n_dig<<endl;
        i64 ans=0;
        i64 dig=2,nw=1,a;
        while(dig<n_dig)
        {
            k=dig/2;
            if(dig%2)k++;
            a=0;
            for(i=0;i<dig;i++,k--)
            {
                a*=10;
                if(k>0)a+=9;
            }
            a+=1;
            ans+=(rev(a)-nw+1);
            nw=a;

            dig++;
        }
        //cout<<ans<<endl;
        //cout<<nw<<endl;

        n=N;
//        cnt=0;
//        while(1)
//        {
//            if(n%10==0)
//            {
//                cnt++;
//                n/=10;
//            }
//            else break;
//        }

        k=n_dig/2;
        //k=max(k,cnt+1);
        a=n;
        for(i=0;i<k;i++)
        {
            a/=10;
        }
        for(i=0;i<k;i++)
        {
            a*=10;
        }
        a++;
        //cout<<a<<endl;
        if(N>=a){
        ans+=(rev(a)-nw+1);
        nw=a;}
        ans+=(N-nw+1);
        //cout<<ans<<endl;
        printf("Case #%lld: %lld\n",++cas,ans);

    }
    return 0;
}
/*Test Cases


*/
