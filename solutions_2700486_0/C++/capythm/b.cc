#include <iostream>
#include <cstdio>
using namespace std;
int d[40][100];
int s[21][40][100];
int n[21];
int dfs( int a, int b ){
  if( b == 0 ){
    for( int i=0; i<40; i++ ) for( int j=0; j<100; j++ ){
      s[a][i][j] += d[i][j];
    }
    return 1;
  }
  int h=39;
  while( h >= 0 ){
    if( d[h][0+50] == 1 ) break;
    h--;
  }
  int ret = 0;
  if( h < 0 || ( d[h+1][49] && d[h+1][51] ) ) {
    if( h < 0 ) h = -2;
    d[h+2][50] = 1;
    ret = dfs( a, b-1 );
    d[h+2][50] = 0;
    return ret;
  }
  // to left
  if( !d[h+1][49] ){
    int y = h+1;
    int x = 49;
    while( y > 0 ){
      if( d[y-1][x-1] ) break;
      y--; x--;
    }
    d[y][x] = 1;
    ret += dfs( a, b-1 );
    d[y][x] = 0;
  }
  // to right
  if( d[h+1][51] == 0 ){
    int y = h+1;
    int x = 51;
    while( y > 0 ){
      if( d[y-1][x+1] ) break;
      y--; x++;
    }
    d[y][x] = 1;
    ret += dfs( a, b-1 );
    d[y][x] = 0;
  }
  return ret;
}
int main( void )
{
  for( int i=1; i<=20; i++ ){
    for( int j=0; j<40; j++ ) for( int k=0; k<100; k++ ){
      d[j][k] = 0;
    }
    n[i] = dfs( i, i );
    //cout << n[i] << endl;
    //for( int j=5; j>=0; j-- ){
    //  for( int k=44; k<57; k++ ){
    //    cout << s[i][j][k] << ' ';
    //  }
    //  cout <<endl;
    //}
  }
  int T;
  cin >> T;
  for( int testcase=1; testcase <= T; testcase++ ){
    int N,X,Y;
    cin >> N >> X >> Y;
    double ret = 0;
    if( -10 <= X && X <= 10 && Y < 7 ){
      ret = s[N][Y][X+50];
      ret /= n[N];
    }
    printf( "Case #%d: %.7f\n", testcase, ret );
    //cout << "Case #" << testcase << ": " << ret << endl;
  }
  return 0;
}
