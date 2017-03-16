/*
ID: ahri1
PROG: C
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define sz(X) ((int)(X).size())
#define foreach(i,c) for(__typeof((c).begin()) i=((c).begin());i!=(c).end();++i)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

template<typename T, typename U> inline void relaxmin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}

void solve(){
  int N, M, K;
  cin >> N >> M >> K;
  
  int best = K;
  
  if (N<2 || M < 2) {
    cout << K << endl;
    return;
  }
  
  if (N>M) swap(N,M);
  
  for(int i=3;i<=N;++i){
    for(int j=i;j<=M;++j){
      int takeoff = 0;
      for(int k=0;k<i-1;++k){
        int cando = j*i-4 - takeoff;
        int stones = (2*i+2*j-8)-k;
        int diff = max(0, (K-cando));
        stones +=diff;
        relaxmin(best, stones);
        takeoff+=k+1;
      }
    }
  }
  cout << best << endl;
}

int main() {

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}
