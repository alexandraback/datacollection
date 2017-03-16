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
int main()
{
    ios::sync_with_stdio ( false );
    int t,i,j,k,m,n,x,y,a,b;
   freopen ( "B-small-attempt0.in","r",stdin );
    freopen ( "B-small10.txt","w",stdout );
    cin>>t;
    rep ( T,1,t )
    {
        cin>>a>>b>>k;
        int ans=0;
        fori ( 0,a-1 )
        {
            forj ( 0,b-1 )
            {
                int x=i&j;
                if ( x<k )
                {

                        ans++;

                }
            }
        }
        printf ( "Case #%d: ",T );
        printf ( "%d\n",ans );
    }
    return 0;
}

