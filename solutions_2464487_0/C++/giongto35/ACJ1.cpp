#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
long long r,t,res,T;

long long calc(long long n)
{
    long long res=0;
    res=(2*r+2*n-2)*n+n;
    return res;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("ACJ1.out","w",stdout);
    cin>>T;
    FOR(st,1,T)
    {
        cin>>r>>t;
        long long left=1;
        long long right=1;
        res=0;
        while (calc(right)<=t) right=right*2;
        while (left<=right)
        {
            long long mid=(left+right)/2;
            if (calc(mid)<=t)
            {
                res=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        cout<<"Case #"<<st<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

