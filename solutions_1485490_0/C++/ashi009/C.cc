#include <iostream>
#include <algorithm>

using namespace std;

long long a[101], b[101];
int A[101], B[101];

long long LCS(int n, long long aa, int m, long long bb) {
  if (n < 1 || m < 1)
    return 0;
  if (A[n] == B[m]) {
    if (aa == bb)
      return aa + LCS(n-1, a[n-1], m-1, b[m-1]);
    else if (aa > bb)
      return bb + LCS(n, aa - bb, m-1, b[m-1]);
    else
      return aa + LCS(n-1, a[n-1], m, bb - aa);
  } else {
    return max(LCS(n-1, a[n-1], m, bb), LCS(n, aa, m-1, b[m-1]));
  }
}

int main() {
  int T;
  int n, m;
  cin >> T;
  for (int Case = 1; Case <= T; Case++) {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
      cin >> a[i] >> A[i];
    for (int i = 1; i <= m; i++)
      cin >> b[i] >> B[i];
    
    cout << "Case #" << Case << ": " << LCS(n, a[n], m, b[m]) << endl;
  }
}

