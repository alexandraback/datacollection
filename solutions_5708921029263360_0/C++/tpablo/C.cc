#include <bits/stdc++.h>

using namespace std;


template<typename t_c, typename t_e>
bool has(t_c const &container, t_e const &elem) {
  return container.find(elem) != container.end();
}


struct O {
  int j, p, s;
  O(): j(0), p(0), s(0) { }
  O(int j, int p, int s): j(j), p(p), s(s) { }
  
  bool operator<(O const &r) const {
    if(j < r.j) return true;
    if(j > r.j) return false;
    if(p < r.p) return true;
    if(p > r.p) return false;
    if(s < r.s) return true;
    if(s > r.s) return false;
    return false;
  }
  
  friend ostream &operator<<(ostream &os, O const &r) {
    return (os << r.j << ' ' << r.p << ' ' << r.s);
  }
};


void test() {
  static int c;
  cout << "Case #" << ++c << ": ";
  
  int j, p, s, k;
  cin >> j >> p >> s >> k;
  
  set<O> ans;
  map<O, int> tgc;
  
  int jo = 0, po = 0, so = 0;
  
  for(bool loop = true; loop;) {
    loop = false;
    for(int jjj = 1; jjj <= j; ++jjj) {
    int jj = (jjj + jo - 1) % j + 1;
    for(int ppp = 1; ppp <= p; ++ppp) {
    int pp = (ppp + po - 1) % p + 1;
    if(tgc[O(jj, pp, 0)] >= k) continue;
    for(int sss = 1; sss <= s; ++sss) {
    int ss = (sss + so - 1) % s + 1;
      if(has(ans, O(jj, pp, ss))) continue;
      if(tgc[O(jj, pp, 0)] >= k) continue;
      if(tgc[O(jj, 0, ss)] >= k) continue;
      if(tgc[O(0, pp, ss)] >= k) continue;
      
      jo += 1;
      po += 1;
      so += 1;
      
      tgc[O(jj, pp, 0)]++;
      tgc[O(jj, 0, ss)]++;
      tgc[O(0, pp, ss)]++;
      ans.insert(O(jj, pp, ss));
      
      loop = true;
    }
    }
    }
  }
  
  cout << ans.size() << '\n';
  for(set<O>::iterator it = ans.begin(); it != ans.end(); ++it) {
    cout << *it << '\n';
  }
}


int main() {
  int t;
  cin >> t;
  
  while(t --> 0) test();
  
  return 0;
}
