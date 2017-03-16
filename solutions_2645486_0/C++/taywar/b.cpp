#include <iostream>
using namespace std;
const int N = 1111;

int a[N], n, r, e;
int ans;

void dfs( int d, int left, int v ) {
     //cout<<d<<" "<<left<<" "<<v<<endl;
     //getchar();
     if( d == n ) {
         if( ans < v ) ans = v;
         return ;
     }
     for( int i = left ; i >= 0 ; --i ) {
          int next = left - i + r;
          if( next > e ) next = e;
          dfs( d+1, next, v + a[d]*i );
     }
}

int main() {
    int T;
    cin>>T;
    for( int tc = 1; tc <= T; ++tc ) {
         cin>>e>>r>>n;
         for( int i = 0 ; i < n; ++i ) {
              cin>>a[i];
         }
         ans = 0;
         dfs( 0, e, 0 );
         cout<<"Case #"<<tc<<": "<<ans<<endl;
    }
    return 0;
}
