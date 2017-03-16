#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

string a,b;
int c,d;

string pr(int a, int l) {
  string tmp="";
  while(l--) {
    tmp += '0'+(a%10);
    a/=10;
  }
  reverse(tmp.begin(),tmp.end());
  return tmp;
}

bool ok(int m, string& s) {
  for(int i = s.size()-1; i >=0; --i) {
    if(s[i] != '?' && m%10 != s[i]-'0') return 0;
    m/=10;
  }
  return 1;
}

int main() {
	ios::sync_with_stdio(0);
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    cin >> a >> b;
    int l = 1;
    for(int i = 0; i < a.size(); ++i)
      l=l*10;
    int best = 0x7ffffff;
    for(int i = 0; i < l; ++i) {
      for(int j = 0; j < l; ++j) {
        if(!ok(i,a) || !ok(j,b)) continue;
        if(abs(i-j) < best) {
          best = abs(i-j);
          c=i;
          d=j;
        }
      }
    }
    cout << "Case #" << t << ": ";
    cout << pr(c,a.size()) << " " << pr(d,a.size()) << "\n";
  }
	return 0;
}
