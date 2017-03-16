// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL get( LL r, LL n ) {
    if ( n==0 ) return 0;
    LL dn=2*r+1;
    LL up=2*r+4*n-3;
    return (up+dn)*n/2;
}
long double get2( long double r, long double n ) {
    if ( n==0 ) return 0;
    long double dn=2*r+1;
    long double up=2*r+4*n-3;
    return (up+dn)*n/2;
}
void solve() {
    LL r,t;
    scanf("%lld%lld",&r,&t);
    LL ll=0,rr=t;
    while ( ll!=rr ) {
        LL mm=(ll+rr+1)/2;
        bool ok=(get2(r,mm)<=t && get(r,mm)<=t);
        if ( ok ) ll=mm;
        else rr=mm-1;
    }
    LL ans=ll;
    printf("%lld\n",ans);
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while ( t-- ) {
        printf("Case #%d: ",++cas);
        solve();
    }
    return 0;
}

