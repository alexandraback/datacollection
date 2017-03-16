#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define ll long long
int A, N;
ll v[101];
ll mem[101];

ll solve(int p, ll a) {
  if (p >= N) return 0;
  ll& ans = mem[p];
  if (ans != -1) return ans;

  ans = N - p;
  if (a > v[p]) {
    ans = solve(p+1, a+v[p]);
  } else if (a != 1) {
    ll ans2 = 0;
    while (a <= v[p]) {
      a += a - 1;
      ans2++;
    }
    ans2 += solve(p+1, a + v[p]);
    ans = min(ans, ans2);
  }
  return ans;
}

int main() {
  int T;
  cin>>T;
  for (int t=1;t<=T;++t) {
    cin>>A>>N;
    for (int i=0;i<N;++i) cin >> v[i];
    sort(v, v+N);
    memset(mem,-1,sizeof(mem));
    cout << "Case #" << t << ": " << solve(0, A) << endl;
  }
}
