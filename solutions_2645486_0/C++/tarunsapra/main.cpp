#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<utility>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ll long long
#define MAX_SIZE 200005
#define MOD 1000000007
#define S(x) scanf("%d",&x)
#define SL(x) cin>>x
#define SC(x) scanf("%c",&x)
#define SS(x) scanf("%s",x)
#define SZ(x) x.size()
#define IT iterator
#define PI pair<int,int>
#define PL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>
#define VVI vector< VI >
#define VVL vector< VL >
#define VVP vector< PI >
#define READ() freopen("/Users/home/Desktop/input.txt","r",stdin)
#define WRITE() freopen("/Users/home/Desktop/output.txt","w",stdout)
#define dump() SC(dump_char)
int dump_char;

ll gain=0;
ll n,r,arr[15],initial;

void cal(ll e,ll i,ll g)
{
    if(i==n+1 || e==0)
    {
        gain=max(gain,g);
        return;
    }
    
    //cal(e,i+1,g);
    for(ll j=0;j<=e;j++)
    {
        cal(min(initial,e-j+r),i+1,g+arr[i]*j);
    }
}

int main()
{
    READ();WRITE();
    ll t;
    SL(t);
    for(ll j=1;j<=t;j++)
    {
        memset(arr,0,sizeof(arr));
        gain=0;
        SL(initial);
        SL(r);
        SL(n);
        for(ll i=1;i<=n;i++)
            SL(arr[i]);
        cal(initial,1,0);
        printf("Case #%lld: %lld\n",j,gain);
    }
    return 0;
    
}