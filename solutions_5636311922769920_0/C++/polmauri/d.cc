#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;

ll fun(int k, Vi v) {
  ll res = 0;
  int c = v.size();
  ll p = 1;
  for (int i = 0; i < c; ++i) {
    res += p*v[i];
    p *= k;
  }
  return res;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int K, C, S;
    cin >> K >> C >> S;
    cout << "Case #" << cas << ":";
    if (S*C < K) {
      cout << " IMPOSSIBLE" << endl;
    } else {
      for (int i = 0; i < K; i += C) {
        Vi v(C);
        for (int j = 0; j < C; ++j) {
          v[j] = (i + j)%K;
        }
        cout << " " << fun(K, v) + 1;
      }
      cout << endl;
    }
  }
}
