#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>
#include<iomanip>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);

  int64_t T;
  cin >> T;
  for(int64_t t=1;t<=T;t++) {
    cout << "Case #" << t << ": ";
    int64_t K,C,S;
    cin >> K >> C >> S;
    if((K+C-1)/C > S) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    int64_t d=0;
    for(int64_t j=1;j<=(K+C-1)/C - 1;j++) {
      int64_t num=0;
      for(int64_t k=0;k<C;k++) {
        num=num*K+d;
        d++;
      }
      cout << num+1 << " ";
    }
    int64_t num=0;
    int64_t len=0;
    for(;d<K;d++) {
      num=num*K+d;
      len++;
    }
    for(;len<C;len++) {
      num=num*K;
    }
    cout << num+1 << "\n";
  }
  return 0;
}

