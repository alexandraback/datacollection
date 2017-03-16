#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("in.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string S;

  int T;
  cin >> T;

  for(int t = 1; t <= T; t++) {
    cin >> S;
    //cout << S << endl;
    cout << "Case #" << t << ": ";

    int i = 0, j;
    int numOfComps = 0;
    while(i < S.size()) {
      j = i;
      while(j < S.size() && S[j] == S[i]) {
        j++;
      }
      if (S[i] == '-') {
        numOfComps++;
      }
      i = j;
    }
    cout << (2 * numOfComps) - (S[0] == '-');
    cout << endl;
  }



  return 0;
}
