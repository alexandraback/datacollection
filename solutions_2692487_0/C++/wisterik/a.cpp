#include <iostream>
#include <vector>
#include <algorithm>

#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define trace(x) { cerr << #x << " = " << x << endl; }

using namespace std;

typedef long long ll;

int solve(int A, int N, vector<int> m) {

  if(A == 1) {
    return N;
  }

  sort(all(m));

  int ans = 1 << 27;
  int cnt = 0;

  rep(i, N) {
    if(A > m[i]) {
      A += m[i];
    }
    else {
      ans = min(ans, cnt + N - i);
      while(A <= m[i]) {
        A += A - 1;
        cnt++;
      }
      A += m[i];
    }
  }

  ans = min(ans, cnt);
  
  return ans;
}

void run() {

  int T;
  cin >> T;

  rep(case_, T) {
    int A, N;
    cin >> A >> N;

    vector<int> m(N);
    rep(i, N) cin >> m[i];

    cout << "Case #" << (case_ + 1) << ": " << solve(A, N, m) << endl;  
  }

}

#undef int
int main() {
  run();
  return 0;
}
