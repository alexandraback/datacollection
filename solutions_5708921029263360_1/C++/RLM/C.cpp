#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    int J, P, S, K;
    cin >> J >> P >> S >> K;
    cout << "Case #" << t << ": ";
    if (S <= K) {
      cout << J*P*S << endl;
      for (int j = 1; j <= J; ++j) for (int p = 1; p <= P; ++p)
        for (int s = 1; s <= S; ++s)
          cout << j << ' ' << p << ' ' << s << endl;
    }
    else {
      cout << J*P*K << endl;
      for (int j = 1; j <= J; ++j) {
        int s = j-1;
        for (int p = 1; p <= P; ++p) {
          for (int k = 1; k <= K; ++k) {
            cout << j << ' ' << p << ' ' << s%S+1 << endl;
            ++s;
          }
        }
      }
    }
  }
}