#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Outfit {
  int a, b, c;

};

void solve(int a, int b, int c, int k, int cur,
           map < pair < int, int >, int > & cntab,
           map < pair < int, int >, int > & cntac,
           map < pair < int, int >, int > & cntbc,
           vector < Outfit > & tmp, vector < Outfit > & res) {
  if(cur == a * b * c){
    if(tmp.size() > res.size())
      res = tmp;
    return;
  }
  Outfit o;
  o.a = cur % a + 1;
  o.b = cur / a % b + 1;
  o.c = cur / a / b + 1;
  solve(a, b, c, k, cur + 1, cntab, cntac, cntbc, tmp, res);
  if(cntab[make_pair(o.a, o.b)] + 1 > k) return;
  if(cntac[make_pair(o.a, o.c)] + 1 > k) return;
  if(cntbc[make_pair(o.b, o.c)] + 1 > k) return;
  ++cntab[make_pair(o.a, o.b)];
  ++cntac[make_pair(o.a, o.c)];
  ++cntbc[make_pair(o.b, o.c)];
  tmp.push_back(o);
  solve(a, b, c, k, cur + 1, cntab, cntac, cntbc, tmp, res);
  --cntab[make_pair(o.a, o.b)];
  --cntac[make_pair(o.a, o.c)];
  --cntbc[make_pair(o.b, o.c)];
  tmp.pop_back();
}

void solve() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  map < pair < int, int >, int > cntab;
  map < pair < int, int >, int > cntac;
  map < pair < int, int >, int > cntbc;
  vector < Outfit > res;
  vector < Outfit > tmp;
  solve(a, b, c, k, 0, cntab, cntac, cntbc, tmp, res);
  cout << res.size() << endl;
  for(const Outfit& o: res)
    cout << o.a << ' ' << o.b << ' ' << o.c << endl;
}

int main() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i){
    cout << "Case #" << i << ": ";
    solve();
  }
}
