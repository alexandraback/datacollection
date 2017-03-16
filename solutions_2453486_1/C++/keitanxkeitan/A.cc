#include <iostream>
#include <cstdio>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <fstream>
#include <complex>
#include <iterator>
#include <memory>
#include <utility>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define rep(i,s,n) for(int i=s;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define MP(a, b) make_pair((a), (b))
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;

ll gcd(ll a, ll b) {
  return a == 0 ? b : gcd(b % a, a);
}

int b[4][4];

void PrintBoard(){
  for( int r=0; r<4; ++r ){
    for( int c=0; c<4; ++c ){
      printf( "%d", b[r][c] );
    }
    printf( "\n" );
  }
  printf( "\n" );
}

int ConvertCharToInt( char c ){
  switch( c ){
  case 'T': return 0;
  case 'X': return 1;
  case 'O': return 2;
  case '.': return 4;
  }
}

int CalcStatus(){
  bool includesEmpty=false;

  for( int r=0; r<4; ++r ){
    for( int c=0; c<4; ++c ){
      if( b[r][c]==4 ){
	includesEmpty=true;
      }
    }
  }

  int bits[10];
  memset( bits, 0, sizeof( bits ) );
  bits[0]=( b[0][0] | b[0][1] | b[0][2] | b[0][3] );
  bits[1]=( b[1][0] | b[1][1] | b[1][2] | b[1][3] );
  bits[2]=( b[2][0] | b[2][1] | b[2][2] | b[2][3] );
  bits[3]=( b[3][0] | b[3][1] | b[3][2] | b[3][3] );
  bits[4]=( b[0][0] | b[1][0] | b[2][0] | b[3][0] );
  bits[5]=( b[0][1] | b[1][1] | b[2][1] | b[3][1] );
  bits[6]=( b[0][2] | b[1][2] | b[2][2] | b[3][2] );
  bits[7]=( b[0][3] | b[1][3] | b[2][3] | b[3][3] );
  bits[8]=( b[0][0] | b[1][1] | b[2][2] | b[3][3] );
  bits[9]=( b[0][3] | b[1][2] | b[2][1] | b[3][0] );

  for( int i=0; i<10; ++i ){
    if( bits[i]==1 ){
      return 1;
    }else if( bits[i]==2 ){
      return 2;
    }
  }

  if( includesEmpty ){
    return 4;
  }else{
    return 3;
  }
}

int main() {
  int T;
  scanf( "%d", &T );

  for( int t=1; t<=T; ++t ){
    for( int r=0; r<4; ++r ){
      string str;
      cin >> str;
      for( int c=0; c<4; ++c ){
	b[r][c]=ConvertCharToInt( str[c] );
      }
    }
    
    int status=CalcStatus();

    printf( "Case #%d: ", t );
    
    switch( status ){
    case 1: printf( "X won\n" ); break;
    case 2: printf( "O won\n" ); break;
    case 3: printf( "Draw\n" ); break;
    case 4: printf( "Game has not completed\n" ); break;
    }

    getchar();
    getchar();
  }
}
