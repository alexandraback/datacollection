#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
#define REP(i,n) for (int i=0;i<int(n);++i) 
const int M = 10000000+5;
typedef long long ll;

bool ispal(int x) {
  stringstream ss;
  ss << x;
  string s;
  ss >> s;
  int n = s.size();
  REP(i,n/2) if (s[i]!=s[n-i-1]) return 0;
  return 1;
}

int main() {
  vector<ll> v(M,0);
  REP(i,M) {
    v[i]=v[i-1];
    ll s = ll(i)*i;
    if (ispal(s) and ispal(i)) ++v[i];
  }
  cerr << "finale" << endl;
  int t; cin >> t;
  REP(cas,t) {
    cout << "Case #" << cas+1 << ": ";
    ll a,b; cin >> a >> b;
    ll bb = sqrt(b);
    ll aa = sqrt(a);
    if (aa*aa!=a) ++aa;
    cout << v[bb]-v[aa-1] << endl;
  }
}
