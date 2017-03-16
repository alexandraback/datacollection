#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)
#define CLR(arr) memset(arr,0,sizeof(arr))
#define MAX3(a,b,c) max(a,max(b,c))
#define MAX4(a,b,c,d) max(max(a,b),max(c,d))
#define MIN3(a,b,c) min(a,min(b,c))
#define MIN4(a,b,c,d) min(min(a,b),min(c,d))
#define MST(arr,val) memset(arr,val,sizeof(arr))
#define PI acos(-1.0)
#define oo 1000000000
#define loo 1000000000000000000LL
#define eps 1e-8

typedef long long ll;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll n,m;
    int t,cs = 0;
    cin >> t;
    while(t--)
    {
        scanf("%lld/%lld",&n,&m);
        int total = 0;
        ll g = gcd(n,m);
        n /= g;
        m /= g;
        ll t = 1;
        while(t < m)
        t *= 2;
        if(m!=t)
        {
            printf("Case #%d: impossible\n",++cs);
            continue;
        }
        while( n < m)
        {
            n = n * 2;
            total++;
        }
        printf("Case #%d: %d\n",++cs,total);
    }
    return 0;
}
