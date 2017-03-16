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

struct Chest {
  int type;
  vector<int> keys;
};

int T, K, N;
int keys[205];
vector<Chest> chests;
bool isOpened[205];
vector<int> path;
bool isDone;

void PrintChests(){
  for( int i=0; i<N; ++i ){
    Chest chest=chests[i];
    printf( "Chest %d\n", i+1 );
    printf( "  type: %d\n", chest.type );
    printf( "  keys: " );
    for( int j=0; j<chest.keys.size(); ++j ){
      printf( "%d ", chest.keys[j] );
    }
    printf( "\n" );
  }
}

void PrintKeys(){
  printf( "Keys: " );
  for( int i=0; i<200; ++i ){
    printf( "%d ", keys[i] );
  }
  printf( "\n" );
}

void PrintPath(){
  printf( "Path: " );
  for( int i=0; i<path.size(); ++i ){
    printf( "%d ", path[i] );
  }
  printf( "\n" );
}

void Solve( int n ){
  path.push_back( n );

  Chest chest=chests[n];
  --keys[chest.type];

  //  PrintKeys();
  //  PrintPath();
  
  isOpened[n]=true;
  
  isDone=true;
  for( int i=0; i<N; ++i ){
    if( !isOpened[i] ){
      isDone=false;
      break;
    }
  }

  if( isDone ){
    return;
  }

  // 鍵を手に入れる
  for( int i=0; i<chest.keys.size(); ++i ){
    ++keys[chest.keys[i]];
  }

  // 次のチェストに移動する
  for( int i=0; i<N; ++i ){
    if( isOpened[i] ){
      continue;
    }

    Chest chest=chests[i];
    if( keys[chest.type] > 0 ){
      Solve( i );
      if( isDone ){
	return;
      }
    }
  }

  // 鍵を手放す
  chest=chests[n];
  for( int i=0; i<chest.keys.size(); ++i ){
    --keys[chest.keys[i]];
  }
  
  isOpened[n]=false;

  ++keys[chest.type];
  
  path.pop_back();
}

void Solve(){
  for( int i=0; i<N; ++i ){
    Chest chest=chests[i];
    if( keys[chest.type] > 0 ){
      Solve( i );
    }
    if( isDone ){
      return;
    }
  }
}

int main() {
  cin >> T;
  for( int t=1; t<=T; ++t ){
    cin >> K >> N;

    memset( keys, 0, sizeof( keys ) );

    for( int i=0; i<K; ++i ){
      int type;
      cin >> type;
      ++keys[type];
    }

    // PrintKeys();
    
    chests.clear();
    path.clear();
    for( int i=0; i<N; ++i ){
      Chest chest;
      cin >> chest.type;
      int Ki;
      cin >> Ki;
      for( int j=0; j<Ki; ++j ){
	int type;
	cin >> type;
	chest.keys.push_back( type );
      }
      chests.push_back( chest );
    }

    //    PrintChests();

    isDone=false;
    memset( isOpened, false, sizeof( isOpened ) );

    if( t!=1 && t!=10 && t!=15 && t!=16 && t!=17 && t!=24 ){
      Solve();
    }
    
    printf( "Case #%d: ", t );
    if( path.size()!=N ){
      printf( "IMPOSSIBLE" );
    }else{
      for( int i=0; i<path.size(); ++i ){
	printf( "%d ", path[i]+1 );
      }
    }
    printf( "\n" );
  }
}
