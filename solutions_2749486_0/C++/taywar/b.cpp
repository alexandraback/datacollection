#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;

typedef pair<int,int> PII;

int d[4][2] = {0,1,1,0,-1,0,0,-1};
char s[] = "SEWN";
const int N = 111;
int a[N<<1][N<<1];
string ans;

inline int g( int n,int m ) {
       return n*( 2*N +1 ) + m;
}

inline int ok( int x, int y ) {
       if( x < 0 || y < 0 || x >= 2*N || y >= 2*N ) return 0;
       return 1;
}

void dfs( int x, int y , int step) {
     int dir = a[x][y];
     if( x == N && y == N ) return ;
     dfs( x - step * d[dir][0] , y - step * d[dir][1] , step - 1); 
     ans += s[ dir ];
}

void bfs( int n,int m ) {
     if( n > 0 ) {
         for( int i = 0 ; i < n; ++i) {
              ans += "WE";
         }
     } else {
         for( int i = 0 ; i < -n; ++i) {
              ans += "EW";
         }
     }
     if( m > 0 ) {
         for( int i = 0 ; i < m; ++i) {
              ans += "SN";
         }
     } else {
         for( int i = 0 ; i < -m; ++i) {
              ans += "NS";
         }
     }
     
}

int main() {
    int T, n, m;
    cin>>T;
    for( int tc = 1; tc <= T; ++tc ) {
         cin>>n>>m;
         ans = "";
         bfs(n , m);
         cout<<"Case #"<<tc<<": "<<ans<<endl;
    }
    return 0;
}
