#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long to_base10(const vector<int>& v, int base, int i1, int n) {
  long long cur=0;
  for(int i=0; i<n; i++) {
    cur *= base;
    cur += v[i1+i];
  }
  return cur;
}

int main(void) {
  int T;
  cin >> T;
  for(int ts=1; ts<=T; ts++) {
    cout << "Case #" << ts << ":";
    int K,C,S; cin >> K >> C >> S;
    if(S*C<K) {
      cout << " IMPOSSIBLE";
    } else {
      vector<int> v;
      for(int i=0; i<S*C; i++) v.push_back(i%K);
      for(int i=0; i<S*C; i+=C) {
        if(i>0 && i%K==0) break;
        cout << " " << to_base10(v, K, i, C)+1;
      }
    }
    cout << endl;
  }
}
