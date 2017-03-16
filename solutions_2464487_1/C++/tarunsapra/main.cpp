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

ll check(ll a,ll b)
{
    if(a<b)
        return a;
    return b;
}

ll a,d,r,t;

ll bs(ll low,ll high)
{
    //printf("%lld %lld\n",low,high);
    VL v;
    ll mid,val;
    while(high>=low)
    {
        //printf("%lld %lld\n",low,high);
        mid=(low+high)/2;
        val=(mid*(2*a+(mid-1)*d))/2;
        //printf("val is %lld\n",val);
        if(val==t)
        {
            v.pb(mid);
            break;
        }
        if(val>t)
        {
            //printf("greater\n");
            high=mid-1;
        }
        if(val<t)
        {
            //printf("small\n");
            low=mid+1;
            v.pb(mid);
        }
    }
    sort(v.begin(),v.end());
    
    if(v.empty())
        return 0;
    return v[SZ(v)-1];

}

int main()
{
    READ();WRITE();
    int i,j;
    S(j);
    for(i=1;i<=j;i++)
    {
        SL(r);SL(t);
        
        a=2*r+1;
        d=4;
        
        printf("Case #%d: %lld\n",i,bs(1,check(1000000001,t/a)));
    }
    return 0;
}