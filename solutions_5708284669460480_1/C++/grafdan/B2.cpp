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

string k,l;

in presuf(string k) {
  for(in x=1; x<=sz(k); x++) {
    if(k.substr(x,sz(k)-x) == k.substr(0,sz(k)-x)) return x;
  }
  return sz(k);
}

vector<D> state;

in domatch(string l, string nxt) {
  in mtch = min(sz(l), sz(nxt));
  while(mtch > 0) {
    // cout << l << " " << nxt << endl;
    // cout << "mtch? " << mtch << endl;
    if(nxt.substr(sz(nxt)-mtch,mtch) == l.substr(0,mtch)) return mtch;
    mtch--;
  }
  return mtch;
}
void apply_state() {
  vector<D> new_state(sz(l)+1,0);
  forv(i,state) {
    forv(j,k) {
      string nxt = l.substr(0,i) + k[j];
      in match = domatch(l,nxt);
      // cout << l << " and " << nxt << " match for " << match << endl;
      new_state[match] += state[i] * (1.0/sz(k));
    }
  }
  state = new_state;

  // forv(i, state) {
  //   printf("%.2lf ",state[i]);
  // }
  // printf("\n");
}

bool has_all() {
  VI P(sz(l),false);
  forv(i,k) {
    forv(j,l) {
      if(k[i]==l[j]) P[j]=true;
    }
  }
  forv(i,P) {
    if(!P[i]) return false;
  }
  return true;
}
void test() {
  in K,L,S; cin >> K >> L >> S;
  cin >> k;
  cin >> l;

  if(!has_all()) {
    cout << 0 << endl;
    return;
  }
  in x = presuf(l);
  D M = (S-L)/x + 1;
  // cout << l << endl;
  // cout << "S " << S << " L " << L << " x " << x << " M " << M <<endl;

  state = vector<D>(L+1,0.0);
  state[0] = 1.;

  D E = 0.0;
  forn(s,S) {
    apply_state();
    E += state.back();
  }
  cout << M - E << endl;
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
