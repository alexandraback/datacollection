#include<iostream>
#include<algorithm>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);++i)
typedef long long LL;

int solve() {
  LL a;
  int n;
  cin >> a >> n;
  int x[n];
  FOR(i,n) 
    cin >> x[i];
  sort(x, x+n);
  int best = n;
  if (a == 1) return best;
  int idx = 0;
  int added = 0;
  while (idx < n) {
    for(;idx < n and x[idx] < a; idx++) {
      a += x[idx];
    }
    best = min(best, added + n-idx);
    a += a-1;
    added++;
  }
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  int z;
  cin >> z;
  FOR(i,z) {
    cout << "Case #" << i+1 << ": " << solve() << endl;
  }
  return 0;
}
