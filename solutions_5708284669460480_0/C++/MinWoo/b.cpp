
/*********************************
 * Google Codejam 2015: Round 1C
 * Author: MinWoo Byeon 
 *********************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

double solve(string key, string target, int S) {
  int maxv = 0;
  double sum = 0;
  int n = 0;
  stack<string> st;
  st.push("");
  while ( not st.empty() ) {
    string curr = st.top(); st.pop();
    if ( curr.length() == S ) {
      int cnt = 0;
      for ( int i=0 ; i<=curr.length()-target.length() ; ++i ) {
        if ( curr.substr(i, target.length()) == target ) {
          ++cnt;
        }
      }
      sum += cnt;
      ++n;
      maxv = max(maxv, cnt);
    }
    else {
      for ( int i=0 ; i<key.size() ; ++i ) {
        st.push(curr + key[i]);
      }
    }
  }
  return maxv - (sum / n);
}

int main() {
  int TC;
  cin >> TC;
  for ( int tc=1 ; tc<=TC ; ++tc ) {
    string keys, target;
    int K, L, S;
    cin >> K >> L >> S >> keys >> target;
    printf("Case #%d: %.8f\n", tc, solve(keys, target, S));
  }
}

