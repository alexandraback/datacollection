#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<vector>

using namespace std;

int main() {
  int T, n, i, j, cn, A, added, current, res;
  cin >> T;
  int q[104];
  for(cn=0; cn<T; cn++){
    cin >> A >> n;
    for(i=0; i<n; i++)
      cin >> q[i];
    sort(q, q+n);
    res = n;
    added = 0;
    current = A;
    if (A > 1) {
      for(i=0; i<n; i++) {
	while(current <= q[i]) {
	  added++;
	  current = current * 2 - 1;
	}
	if (res > added + n - 1 - i) 
	  res = added + n - 1 - i;
	current += q[i];
      }
    }
    cout << "Case #" << cn+1 << ": " << res << "\n";
  }
  return 0;
}