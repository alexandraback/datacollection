#include <iostream>
#include <map>
#include <vector>

using namespace std;

void hoge(vector<int> &S, int s) {

  for (int i = 0; i < S.size(); ++i) {
    if (s >> i & 1) cout << S[i] << ' ';
  }
  cout << endl;

}

int main() {

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; ++i) {
      cin >> S[i];
    }
    map<int,int> m;
    for (int s = 1; s < 1 << N; ++s) {
      int sum = 0;
      for (int i = 0; i < N; ++i) {
        if (s >> i & 1) sum += S[i];
      }
      if (m.find(sum) != m.end()) {
        cout << "Case #" << t << ':' << endl;
        hoge(S, m[sum]);
        hoge(S, s);
        goto next;
      }
      else {
        m[sum] = s;
      }
    }
    cout << "Case #" << t << ':' << endl;
    cout << "Impossible" << endl;
  next:;
  }

  return 0;

}
