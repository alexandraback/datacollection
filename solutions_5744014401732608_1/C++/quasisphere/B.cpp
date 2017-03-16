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
    int64_t B, M;
    cin >> B >> M;

    cout << "Case #" << t << ": ";
    if(((int64_t)1 << (B-2)) < M) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    cout << "POSSIBLE\n";

    if(B == 2) {
      cout << "01\n00\n";
      continue;
    }

    if(((int64_t)1 << (B-2)) == M) {
      cout << '0';
      for(int64_t j=2;j<=B;j++) {
        cout << '1';
      }
      cout << '\n';
    } else {
      cout << '0';
      int64_t mybit=((int64_t) 1 << (B-3));
      for(int64_t j=2;j<B;j++) {
        if(M & mybit) {
          cout << '1';
        } else {
          cout << '0';
        }
        mybit/=2;
      }
      cout << "0\n";
    }
    for(int64_t i=2;i<=B;i++) {
      for(int64_t j=1;j<=B;j++) {
        if(j > i) {
          cout << '1';
        } else {
          cout << '0';
        }
      }
      cout << '\n';
    }
  }
  return 0;
}
 
