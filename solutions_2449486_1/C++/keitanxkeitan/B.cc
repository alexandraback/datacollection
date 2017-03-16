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

int N, M;
int a[105][105];

void PrintVector( const vector<int> &v ){
  for( int i=0; i<v.size(); ++i ){
    printf( "%d ", v[i] );
  }
  printf( "\n" );
}

bool Solve(){
  set<int> snums;

  for( int r=0; r<N; ++r ){
    for( int c=0; c<M; ++c ){
      snums.insert( a[r][c] );
    }
  }

  vector<int> nums( snums.begin(), snums.end() );
  sort( nums.begin(), nums.end() );

  //  PrintVector( nums );

  for( int i=0; i<nums.size(); ++i ){
    for( int r=0; r<N; ++r ){
      for( int c=0; c<M; ++c ){
	if( a[r][c]!=nums[i] ){
	  continue;
	}

	// 横方向に抜けているか見る
	bool isOkCol=true;
	for( int cc=0; cc<M; ++cc ){
	  if( a[r][cc]>nums[i] ){
	    isOkCol=false;
	    break;
	  }
	}

	// 縦方向に抜けているか見る
	bool isOkRow=true;
	for( int rr=0; rr<N; ++rr ){
	  if( a[rr][c]>nums[i] ){
	    isOkRow=false;
	    break;
	  }
	}

	// 横方向にも縦方向にも抜けていなければ NO
	if( !isOkCol && !isOkRow ){
	  return false;
	}
      }
    }
  }

  return true;
}

int main() {
  int T;
  cin >> T;
  for( int t=1; t<=T; ++t ){
    cin >> N >> M;

    for( int r=0; r<N; ++r ){
      for( int c=0; c<M; ++c ){
	cin >> a[r][c];
      }
    }

    bool isYes=Solve();

    printf( "Case #%d: %s\n", t, isYes ? "YES" : "NO" );
  }
}
