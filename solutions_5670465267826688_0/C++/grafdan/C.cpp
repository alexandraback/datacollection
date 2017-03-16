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

enum letter { ONE, I, J, K };
struct quart {
  bool sign;
  letter val;
  quart(letter v, bool s) {
    val = v;
    sign = s;
  }
  quart(char c) {
    sign = false;
    if(c=='i') val = I;
    if(c=='j') val = J;
    if(c=='k') val = K;
  }
  void print() {
    if(sign) cout << "-";
    if(val==ONE) cout << "1";
    if(val==I) cout << "i";
    if(val==J) cout << "j";
    if(val==K) cout << "k";
    cout << " ";
  }
  quart operator * (const quart &o) {
    quart r(ONE,false);
    if(val == ONE) {
      if(o.val == ONE) r.val = ONE;
      if(o.val == I) r.val = I;
      if(o.val == J) r.val = J;
      if(o.val == K) r.val = K;
    }
    if(val == I) {
      if(o.val == ONE) r.val = I;
      if(o.val == I) { r.val = ONE; r.sign = true; }
      if(o.val == J) { r.val = K; r.sign = false; }
      if(o.val == K) { r.val = J; r.sign = true; }
    }
    if(val == J) {
      if(o.val == ONE) r.val = J;
      if(o.val == I) { r.val = K; r.sign = true; }
      if(o.val == J) { r.val = ONE; r.sign = true; }
      if(o.val == K) { r.val = I; r.sign = false; }
    }
    if(val == K) {
      if(o.val == ONE) r.val = K;
      if(o.val == I) { r.val = J; r.sign = false; }
      if(o.val == J) { r.val = I; r.sign = true; }
      if(o.val == K) { r.val = ONE; r.sign = true; }
    }
    r.sign ^= (sign ^ o.sign);
    return r;
  }
};

void test() {
  in L, X; cin >> L >> X;
  string s; cin >> s;
  string n;
  forn(x,X) n+=s;

  bool have_i = false;
  bool have_j = false;
  quart q(ONE, false);

  forv(i,n) {
    q = q * quart(n[i]);
    // q.print();
    if(have_i && q.val == K && q.sign == false) {
      have_j = true;
    }
    if(q.val == I && q.sign == false) {
      have_i = true;
    }
  }

  // we have -1 in the end
  if(have_i && have_j && q.val == ONE && q.sign == true) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
