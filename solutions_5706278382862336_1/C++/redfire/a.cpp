/* @author Ishita Gupta*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define vi vector<int>
#define vvi vector< vi >
#define vs vector<string>
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define fori(s,e) for(int i=s;i<=e;i++)
#define forj(s,e) for(int j=s;j<=e;j++)
#define fork(s,e) for(k=s;k<=e;k++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define ull unsigned long long
#define ll long long
#define imax INT_MAX
#define imin INT_MIN
#define mem(x,y) memset(x,y,sizeof(x));
#define pii pair<int,int>
#define aa first
#define bb second
using namespace std;
ll gcd ( ll a,ll b )
{
    if ( b==0 )
    {
        return a;
    }
    return gcd ( b,a%b );
}
ll fun ( ll a,ll b )
{
    //cout<<a<<" "<<b<<endl;
    if(a==b) return 0;
    if ( 2*a>=b )
    {
        return 1;
    }
    ll g=gcd(a,b);
    a=a/g;
    b=b/g;
    return fun ( 2*a,b )+1;
}
bool check ( ll a )
{
    while ( a!=1 )
    {
        if ( a%2!=0 )
        {
            return false;
        }
        a=a/2;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio ( false );
    int t,i,j,k,m,n,x,y,a,b;
    freopen ( "A-large.in","r",stdin );
    freopen ( "A-large0.txt","w",stdout );
    cin>>t;
    rep ( T,1,t )
    {
        string str;
        cin>>str;
        n=str.size();
        ll p=0,q=0,flag=1;
        //cout<<str<<endl;
        fori ( 0,n-1 )
        {
            if ( str[i]=='/' )
            {
                flag=0;
                continue;
            }
            if ( flag==1 )
            {
                p=p*10+str[i]-'0';
            }
            else
            {
                q=q*10+str[i]-'0';
            }
        }
        ll g=gcd(p,q);
        p=p/g;
        q=q/g;
        printf ( "Case #%d: ",T );
        if ( check ( q ) )
        {
            ll ans=fun ( p,q );
            printf ( "%lld\n",ans );
        }
        else
        {
            printf("impossible\n");
        }

    }
    return 0;
}

