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
#define sz(v) (in)(((v).size()))
#define forn(i,n) for(int i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
typedef vector<in> VI;

bool has(VI &A, in x) {
  forv(i,A) if(A[i]==x) return true;
  return false;
}

bool DP(in V, VI &A, VI &E) {
  VI DP(V+1,false);
  DP[0]=true;
  forv(i,A) {
    for(in v = V; v>=0; v--) {
      if(DP[v] && v+A[i] <= V) DP[v+A[i]] = true;
    }
  }
  forv(i,E) {
    for(in v = V; v>=0; v--) {
      if(DP[v] && v+E[i] <= V) DP[v+E[i]] = true;
    }
  }
  forv(i,DP) {
    if(!DP[i]) return false;
  }
  return true;
}

bool tryout(in n, VI &A, VI E, in x, in V) {
  if(sz(E) < n) { // try adding more numbers:
    x++;
    while(x<=V && has(A,x)) x++;
    if(x>V) return false;

    if(tryout(n, A, E, x, V)) return true;
    E.PB(x);
    return tryout(n, A, E, x, V);
  } else {
    return DP(V, A, E);
  }
}

void test() {
  in C, D, V; cin >> C >> D >> V;
  VI A(D); forn(i,D) cin >> A[i];

  in res = 0;
  while(true) {
    if(tryout(res,A, VI(), 0, V)) {
      cout << res << endl;
      return;
    }
    res++;
  }
  //cout << opt << endl;
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
