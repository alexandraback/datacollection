#include <iostream>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;

long long a[101], b[101];
int A[101], B[101];

typedef tuple<int, long long, int, long long> memo_key_t;
map<memo_key_t, long long> memo;

long long LCS(int n, long long aa, int m, long long bb) {

  if (n < 1 || m < 1)
    return 0;
    
  auto key = make_tuple(n, aa, m, bb);
  auto it = memo.find(key);
  if (it != memo.end())
    return it->second;
  
  long long res;
  if (A[n] == B[m]) {
    if (aa == bb)
       res = aa + LCS(n-1, a[n-1], m-1, b[m-1]);
    else if (aa > bb)
      res = bb + LCS(n, aa - bb, m-1, b[m-1]);
    else
      res = aa + LCS(n-1, a[n-1], m, bb - aa);
  } else {
    res = max(LCS(n-1, a[n-1], m, bb), LCS(n, aa, m-1, b[m-1]));
  }
  
  return memo[key] = res;
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
    
    memo.clear();
    
    cout << "Case #" << Case << ": " << LCS(n, a[n], m, b[m]) << endl;
  }
}

