// -*- compile-command: "g++ -Wall -Wextra x.cpp -o x && ./x <test.in" -*-
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdio>
#include <iostream>
#include <iomanip> 
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
typedef double D;

in cnt(string S, string T) {
  in res = 0;
  forv(i,S) {
    if(S.substr(i,sz(T)) == T) res++;
  }
  return res;
}

D E; // Expectation esult
D M; // Maximum
void tryout(in S, string s, string l, string k, D prob) {
  if(sz(s) < S) {
    // cout << "S: " << s << " with prob " << prob << " and sz " << sz(s) << endl;
    forv(i,k) {
      // cout << "-> " << s+k[i] << endl;
      tryout(S,s+k[i],l,k,prob * (1./sz(k)));
    }
  } else {
    in c = cnt(s,l);
    M = max(M,1.0*c);
    E += prob*c;
    // cout << "S: " << s << " with prob " << prob << " and count " << c << endl;
  }
}

void test() {
  in K,L,S; cin >> K >> L >> S;
  string k; cin >> k;
  string l; cin >> l;
  E = 0.;
  M = 0.;
  tryout(S, "",l,k,1.0);
  cout << M-E << endl;
}
int main(){
  std::ios::sync_with_stdio(false); // remove this if you use printf/scanf
  std::cin.tie(0);
  std::cout << std::setprecision(9);
  in T; cin >> T;
  forn(t,T) {
    cout << "Case #" << t+1 << ": ";
    test();
  }

  return 0;  
}
