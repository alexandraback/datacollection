// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline double sq( double x ) { return x*x; }
#define K 12
#define M 9
int r,n,m,k,p[K][M];
void input() {
    for ( int i=0; i<k; i++ ) {
        long long x;
        scanf("%lld",&x);
        for ( int j=2; j<=m; j++ ) {
            int c=0;
            while ( x%j==0 ) {
                c++;
                x/=j;
            }
            p[i][j]=c;
        }
    }
}
int big[M];
double avg[M];
void build() {
    memset(big,0,sizeof(big));
    memset(avg,0,sizeof(avg));
    for ( int i=0; i<k; i++ ) for ( int j=2; j<=m; j++ ) big[j]=max(big[j],p[i][j]);
    for ( int i=0; i<k; i++ ) for ( int j=2; j<=m; j++ ) avg[j]+=p[i][j];
    for ( int i=2; i<=m; i++ ) avg[i]/=k;
}
void predict() {
    int n5=max(big[5],(int)(avg[5]*2+0.25));
    if ( n5>n ) n5=n;
    int n7=max(big[7],(int)(avg[7]*2+0.25));
    if ( n5+n7>n ) n7=n-n5;
    int n3=0;
    for ( int i=0; i<k; i++ ) n3=max(n3,p[i][3]-p[i][2]);
    if ( n3+n5+n7>n ) n3=n-n5-n7;
    int n6=big[3]-n3;
    if ( n3+n5+n7+n6>n ) n6=n-n3-n5-n7;
    int t=n-n5-n7-n3-n6;
    int l2=0;
    if ( n6==0 && t>0 ) for ( int i=0; i<k; i++ ) if ( p[i][2]==1 ) l2=1;
    double tmt=0;
    for ( int i=0; i<k; i++ ) tmt+=sq(p[i][2]);
    tmt/=k;
    int n2=t,n4=0,n8=0;
    double best=1e100;
    for ( int i2=l2; i2<=t; i2++ ) for ( int i4=0; i2+i4<=t; i4++ ) {
        int i8=t-i2-i4;
        if ( i2+2*i4+3*i8+n6<big[2] ) continue;
        double now_avg=(i2+2*i4+3*i8+n6)/2.0;
        double now_tmt=0;
        for ( int i=0; i<514; i++ ) {
            double s=0;
            for ( int j=0; j<n6; j++ ) if ( rand()%2 ) s++;
            for ( int j=0; j<i2; j++ ) if ( rand()%2 ) s++;
            for ( int j=0; j<i4; j++ ) if ( rand()%2 ) s+=2;
            for ( int j=0; j<i8; j++ ) if ( rand()%2 ) s+=3;
            now_tmt+=sq(s);
        }
        now_tmt/=514;
        double diff=5.14*fabs(now_avg-avg[2])+fabs(now_tmt-tmt);
        if ( diff<best ) {
            best=diff;
            n2=i2,n4=i4,n8=i8;
        }
    }
    for ( int i=0; i<n2; i++ ) putchar('2');
    for ( int i=0; i<n3; i++ ) putchar('3');
    for ( int i=0; i<n4; i++ ) putchar('4');
    for ( int i=0; i<n5; i++ ) putchar('5');
    for ( int i=0; i<n6; i++ ) putchar('6');
    for ( int i=0; i<n7; i++ ) putchar('7');
    for ( int i=0; i<n8; i++ ) putchar('8');
    assert(n2+n3+n4+n5+n6+n7+n8==n);
    //printf(" best = %f\n",best);
    puts("");
}
void solve() {
    scanf("%d%d%d%d",&r,&n,&m,&k);
    while ( r-- ) {
        input();
        build();
        predict();
    }
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while ( t-- ) {
        printf("Case #%d:\n",++cas);
        solve();
    }
    return 0;
}



