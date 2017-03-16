/*
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#define eps 1e-9
using namespace std;
int main(){
  freopen("A-small-attempt1.in","r",stdin);
  freopen("A-small-attempt1.out","w",stdout);
    int t,n,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int a[200],mmax=0,cnt=0,sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        printf("Case #%d:",++cas);
        for(int i=0;i<n;i++){
            double high=1,low=0,mid;
            while(high-low>eps){
                mid=(high+low)/2;
                double tt=a[i]+sum*mid,tmp=mid;
              //  cout<<tt<<" "<<mid<<endl;
                for(int j=0;j<n;j++)
                    if(i!=j)
                        tmp+=(tt-a[j])/sum;
             //   cout<<tmp<<endl;
                if(tmp<1)
                   low=mid;
                else
                   high=mid;
            }
            printf(" %.6f",mid*100);
        }
        printf("\n");
    }
    return 0;
}
*/

#include <cstdio>
#include <algorithm>
using namespace std;
struct Node {
    int id;
    double s;
};
Node node[203];
double y[203];
bool cmp( const Node &a, const Node &b ) {
    return a.s < b.s;
}
int main( int argc, char *argv[] )
{
    freopen( "A-large.in", "r", stdin );
    freopen( "A-large.out", "w", stdout );
    int t, cas = 0, n, i, j, n1;
    double x, k, av;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &n );
        x = 0;
        for ( i = 0; i < n; ++i ) {
            node[i].id = i;
            scanf( "%lf", &node[i].s );
            x += node[i].s;
        }
        sort( node, node + n, cmp );
        k = 0;
        n1 = n - 1;
        for ( i = 0; i < n1; ++i ) {
            k += node[i].s;
            if ( (k + x) / ( i + 1 ) <= node[i+1].s ) break;
        }
        j = i;
        if ( j >= n1 ) k += node[n1].s;
        av = ( k + x ) / ( j + 1 );
        for ( i = 0; i < n; ++i ) {
            if ( i <= j ) y[node[i].id] = ( av - node[i].s ) / x;
            else y[node[i].id] = 0;
        }
        printf( "Case #%d:", ++cas );
        for ( i = 0; i < n; ++i ) printf( " %.8f", y[i] * 100 );
        putchar( '\n' );
    }
    return 0;
}
