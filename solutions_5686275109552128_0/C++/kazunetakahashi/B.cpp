#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int D;
int P[1010];

void input() {
  cin >> D;
  for (auto i=0; i<D; i++) {
    cin >> P[i];
  }
}

void output() {
  int X[1010];
  fill(X, X+1010, 0);
  for (auto i=0; i<D; i++) {
    X[P[i]]++;
  }
  int ans = 100100100;
  for (auto i=1; i<=1000; i++) {
    int tans = 0;
    for (auto j=1; j<=1000; j++) {
      tans += (j-1)/i * X[j];
    }
    tans += i;
    ans = min(ans, tans);
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
