#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

#define N 1000005

int answer[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("in.out","w",stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int maxi = 0;
  for(int i = 1; i <= N; i++) {
    int msk = 0;
    int j = 1;
    for(; msk != ((1 << 10) - 1); j++) {
      ll temp = 1LL * i*j;
      while(temp > 0) {
        msk |= 1 << (temp % 10);
        temp /= 10;
      }
    }
    answer[i] = i*(j - 1);
  }

  int T, n;

  cin >> T;

  for(int i = 1; i <= T; i++) {
    cin >> n;
    cout << "Case #" << i << ": ";
    if (n == 0) cout << "INSOMNIA";
    else cout << answer[n];
    cout << endl;
  }



  return 0;
}
