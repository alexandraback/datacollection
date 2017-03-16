#include <cstdio>
#include <cstring>
const int MAXN = 1000;const double eps = 1e-10;int data[MAXN] , n , s;double ans[MAXN];bool check( double key , int x ){double temp[MAXN];double score = data[x]+key*s;memset( temp , 0 , sizeof(temp) );for ( int i = 0; i < n; i++ ){if ( i == x ) temp[i] = key;else{if ( data[i] > score ) continue;else temp[i] = double(score-data[i])/s;}}double ss = 0;for ( int i = 0; i < n; i++ ) ss += temp[i];return ss > 1;}double solve( int x ){double l = 0 , r = 1 , ret = 1;while ( r-l > eps ){double mid = ( l + r ) / 2;if ( check(mid,x) ) {r = mid;ret = mid;} else l = mid;}return ret;}
int main(){
    //freopen("out","w",stdout);
    //freopen("A-large.in", "r", stdin);
    int cas;scanf( "%d" , &cas );for ( int t = 1; t <= cas; t++ ) {scanf( "%d" , &n );for ( int i = 0; i < n; i++ ) scanf( "%d" , &data[i] );s = 0;for ( int i = 0; i < n; i++ ) s += data[i];for ( int i = 0; i < n; i++ ) ans[i] = solve(i);printf( "Case #%d:" , t );for ( int i = 0; i < n; i++ ) printf( " %.6lf" , ans[i]*100 );printf( "\n" );}return 0;}
