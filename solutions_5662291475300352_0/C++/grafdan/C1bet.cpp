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
typedef double D;
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(int i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
typedef vector<in> VI;

D absval(D x) {
  if(x<0) return -x;
  return x;
}

in test() {
  in N; cin >> N;
  VI WP;
  VI WV;
  forn(n,N) {
    in D,H,M; cin >> D >> H >> M;
    forn(h,H) {
      WP.PB(D);
      WV.PB(M+h);
    }
  }

  if(sz(WP) < 2) {
    return 0;
  }

  if(WV[0] == WV[1]) {
    return 0;
  }

  // First have the back and slow
  if(WP[0] > WP[1] || (WP[0]==WP[1] && WV[0] < WV[1])) {
    swap(WP[0], WP[1]);
    swap(WV[0], WV[1]);
  }

  D f0 = WV[0] * (360.0-WP[0])/360.0;
  D f1 = WV[1] * (360.0-WP[1])/360.0;
  D vrel = absval(1.0/WV[0] - 1.0/WV[1]);
  D degrel;
  if(WV[0] < WV[1]) { // we are faster
    degrel = WP[1]-WP[0];
  } else { // the other is faster
    degrel = WP[0]-WP[1]+360;
  }
  if(degrel < 0.00001) degrel+= 360;
  // If we are first following the fast one, then we wait for the second meeting
  if(WV[1] > WV[0]) {
    degrel += 360;
  }
  D tmeet = (degrel/360.0)/vrel;
  D s0 = f0 + WV[0];
  D s1 = f1 + WV[1];
  // cout << f0 << " " << s0 << endl;
  // cout << f1 << " " << s1 << endl;
  // cout << tmeet << endl;

  if(max(f0,f1) <= tmeet) {
    return 0;
  } else {
    return 1;
  }
}
int main(){
  std::ios::sync_with_stdio(false); // remove this if you use printf/scanf
  std::cin.tie(0);

  in T; cin >> T;
  forn(t,T) {
    cout << "Case #" << t+1 << ": " << test() << endl;
  }

  return 0;  
}
