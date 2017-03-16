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

void test() {
  in N; cin >> N;
  VI A;
  in m=0;
  forn(n,N) {
    in a; cin >> a;
    A.PB(a);
    m = max(m,a);
  }

  in opt = m;
  for(in t=1; t<=m; t++) {
    in extra = 0;
    forv(i,A) {
      if(A[i]>t) {
        extra += (A[i]-1)/t;
      }
    }
    opt = min(opt, t+extra);
  }

  cout << opt << endl;
}
int main(){
  std::ios::sync_with_stdio(false); // remove this if you use printf/scanf
  std::cin.tie(0);

  in T; cin >> T;
  forn(t,T) {
    cout << "Case #" << t+1 << ": ";
    test();
  }

  return 0;  
}
