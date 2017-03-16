// :)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Users/Ayur/Downloads/B-small-attempt0.in.txt", "r", stdin);
  freopen("/Users/Ayur/Downloads/B-small", "w", stdout);
  int i, j, n, N, tc, tt, x;
  cin >> tt;
  for (tc = 1; tc <= tt; tc++) {
    cout << "Case #" << tc << ": ";
    cin >> n;
    a.clear();
    for (i = 0; i < 2 * n - 1; i++) {
      for (j = 0; j < n; j++) {
        cin >> x;
        a.push_back(x);
      }
    }
    N = (int)a.size();
    sort(a.begin(), a.end());
    b.clear();
    i = 0;
    while (i < N) {
      j = i;
      while (j < N && a[j] == a[i])
        j++;
      if ((j - i) & 1)
        b.push_back(a[i]);
      i = j;
    }
    assert((int)b.size() == n);
    for (i = 0; i < n; i++)
      cout << b[i] << ' ';
    cout << '\n';
  }
  return 0;
}