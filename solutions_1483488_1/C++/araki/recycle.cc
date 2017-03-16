#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

int solve(int,int);

int main() {
  int num_cases;
  cin >> num_cases;
  for(int i = 0; i < num_cases; i++) {
    int a, b;
    cin >> a >> b;
    int r = solve(a,b);
    cout << "Case #" << i+1 << ": " << r << endl;;
  }
}

int solve(int a, int b) {
  int ret = 0;
  string as = lexical_cast<string>(a);
  string bs = lexical_cast<string>(b);
  int n = as.size();
  for(int i = a; i < b; i++) {
    string is = lexical_cast<string>(i);
    set<string> cand;
    for(int j = 1; j < n; j++) {
      string rs(is);
      rotate(rs.begin(), rs.begin()+j, rs.end());
      if(is < rs && rs <= bs) {cand.insert(rs);}
    }
    ret += cand.size();
    cand.clear();
  }
  return ret;
}
