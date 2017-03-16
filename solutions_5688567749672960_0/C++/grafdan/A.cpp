// -*- compile-command: "g++ -Wall -Wextra x.cpp -o x && ./x <test.in" -*-
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long in;
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(int i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
typedef vector<in> VI;

in reverse(in X) {
  in Y = 0;
  while(X>0) {
    Y*=10;
    Y+= X%10;
    X/=10;
  }
  return Y;
}

#define MAXN 1000100
VI D(MAXN,MAXN+10);
VI P(MAXN,0);

void precompute() {
  priority_queue<pair<in,in> > PQ;
  PQ.push(MP(0,0));
  D[0] = 0;
  P[0] = 0;
  while(PQ.size()) {
    in n = PQ.top().second;
    in d = -PQ.top().first;
    PQ.pop();
    // cout << n << " " << d << endl;
    if(n+1 < MAXN) {
      if(d+1 < D[n+1]) {
        D[n+1] = d+1;
        P[n+1] = n;
        PQ.push(MP(-(d+1), n+1));
      }
    }
    if(reverse(n) < MAXN) {
      if(d+1 < D[reverse(n)]) {
        D[reverse(n)] = d+1;
        P[reverse(n)] = n;
        PQ.push(MP(-(d+1), reverse(n)));
      }
    }
  }
}


void test() {
  in N; cin >> N;
  cout << D[N] << endl;

  // while(N != P[N]) {
  //   cout << P[N] << " ";
  //   N = P[N];
  // }
  // cout << endl;


  //cout << opt << endl;
}
int main(){
  std::ios::sync_with_stdio(false); // remove this if you use printf/scanf
  std::cin.tie(0);
  precompute();
  in T; cin >> T;
  forn(t,T) {
    cout << "Case #" << t+1 << ": ";
    test();
  }

  return 0;  
}
