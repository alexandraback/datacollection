#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
string S;

void input() {
  cin >> N;
  cin >> S;
}

void output() {
  int sum = 0;
  int ans = 0;
  for (auto i=0; i<=N; i++) {
    if (sum < i) {
      ans += (i - sum);
      sum = i;
      // cerr << "i = " << i << ", ans: " << ans << endl;
    }
    sum += S[i] - '0';
  }
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  for (auto t=1; t<=T; t++) {
    cout << "Case #" << t << ": "; 
    input();
    output();
  }
}
