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

int K,L,S;
string kbrd, targ;

int vst[28];
VI V;

bool vt[110][110];
double DP[110][110];
int F[110],ex;

void failure()
{
    F[0] = F[1] = 0; // always true

    for(int i = 2; i <= L; i++) {
    // j is the index of the largest next partial match
    // (the largest suffix/prefix) of the string under
    // index i - 1
        int j = F[i - 1];
        for( ; ; ) {
        // check to see if the last character of string i -
        // - pattern[i - 1] "expands" the current "candidate"
        // best partial match - the prefix under index j
        if(targ[j] == targ[i - 1]) {
            F[i] = j + 1; break;
        }
        // if we cannot "expand" even the empty string
        if(j == 0) { F[i] = 0; break; }
        // else go to the next best "candidate" partial match
        j = F[j];
    }
  }
}

double func(int i, int j)
{
    if(vt[i][j]==1)return DP[i][j];
    vt[i][j]=1;
    DP[i][j]=0;
    if(j==S)
    {
        return 0;
    }
    double ans=func(F[i],j);
    for(int k=0;k<SZ(V);k++)
    {
        int l=V[k];
        double p=vst[l]*1.0;
        p/=K;
        if((targ[i]-'A')==l)
        {
            if((i+1)==SZ(targ))
            {
                ans+=(p*(1+func(F[i+1],j+1)));
            }
            else
            {
                ans+=(p*func(i+1,j+1));
            }
        }
//        else if(i>0)
//        {
//            ans+=(p*func(F[i],j));
//        }
        else if(i==0) ans+=(p*func(i,j+1));
    }
    return DP[i][j]=ans;
}

int main()
{
    freopen("B-small-attempt3.in","r",stdin);
    freopen("B_newout.out","w",stdout);
    int i,j,k ,T,cas=0;
    scanf("%d",&T);
    while(T--)
    {

        SET(vst,0);
        for(i=0;i<110;i++)
        {
            for(j=0;j<110;j++)
            {
                vt[i][j]=0;
                DP[i][j]=0.0;
            }
        }
        SET(vt,0);
        V.clear();
        SET(F,0);


        cin>>K>>L>>S;
        cin>>kbrd;
        cin>>targ;

        failure();

        for(i=0;i<SZ(kbrd);i++)
        {
            j=kbrd[i]-'A';
            if(vst[j]==0)V.pb(j);
            vst[j]++;
        }
        bool t=1;
        for(i=0;i<SZ(targ);i++)
        {
            j=targ[i]-'A';
            if(!vst[j])
            {
                t=0;
                break;
            }
        }
        if(!t)
        {
            printf("Case #%d: %.8lf\n",++cas,0.0);
            continue;
        }
        ex=0;
        int strt=0;
        while(1)
        {
            if(strt+L>S)
            {
                break;
            }
            ex++;
            strt=strt + L - F[L];
        }
        //cout<<ex<<endl;

        double ans=func(0,0);
        //cout<<(double)ex-ans<<endl;
        printf("Case #%d: %.8lf\n",++cas,(double)ex-ans);
    }



    return 0;
}
/*Test Cases


*/
