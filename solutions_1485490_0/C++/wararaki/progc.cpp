#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int n, m;
lli mx;
lli a[101], b[101];
int A[101], B[101];

void solve(int p, int q, lli sm)
{
  if(p == n && q == m) mx = max(mx, sm);

  lli t = 0;
  if(p < n && q < m && A[p] == B[q]){
    t = min(a[p], b[q]);
    a[p] -= t;
    b[q] -= t;
  }

  if(p < n) solve(p+1, q, sm+t);
  if(q < m) solve(p, q+1, sm+t);
  
  a[p] += t;
  b[q] += t;
}

int main()
{
  int T;

  while(cin>>T && T)
    for(int cs = 1; cs <= T; ++cs){
      cin >> n >> m;
      mx = 0;
      for(int i = 0; i < n; ++i) cin >> a[i] >> A[i];
      for(int j = 0; j < m; ++j) cin >> b[j] >> B[j];
      solve(0, 0, 0);
      cout << "Case #" << cs << ": " << mx << endl;
    }

  return 0;
}
