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

bool isPalindrome( ll num ){
  stringstream ss;
  ss << num;
  string str;
  ss >> str;

  int len=str.size();

  for( int i=0; i<len; ++i ){
    if( str[i]!=str[len-i-1] ){
      return false;
    }
  }

  return true;
}

int main() {
  vector<ll> fss;
  
  for( ll i=0; i<=10000000; ++i ){
    if( isPalindrome( i ) ){
      if( isPalindrome( i * i ) ){
	fss.push_back( i * i );
      }
    }
  }

  //  for( int i=0; i<fss.size(); ++i ){
  //    cout << fss[i] << endl;
  //  }
    
  int T;
  cin >> T;
  for( int t=1; t<=T; ++t ){
    ll A, B;
    cin >> A >> B;

    int ans=0;
    for( int i=0; i<fss.size(); ++i ){
      if( ( fss[i] >= A ) && ( fss[i] <= B ) ){
	++ans;
      }
    }

    printf( "Case #%d: %d\n", t, ans );
  }
}
