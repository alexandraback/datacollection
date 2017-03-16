#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  cout << "Case #" << tc << ": ";
  int N;
  cin >> N;
  if (N == 0) {
    cout << "INSOMNIA" << endl;
    return;
  }
  vector<bool> seen(10);
  int left = 10;
  int O = 0;
  while (left) {
    O += N;
    int tmp = O;
    while (tmp) {
      left -= !seen[tmp%10];
      seen[tmp%10] = true;
      tmp /= 10;
    }
  }
done:
  cout << O << endl;
}

int main() {
  int N;
  cin >> N;
  rep(i,1,N+1) solve(i);
}
