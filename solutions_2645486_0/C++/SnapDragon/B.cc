#include <cstring>
#include <iostream>
using namespace std;

int E, R, N;
int V[11];

int memo[20][20];
int doit(int d, int e) {
  int& ret = memo[d][e];
  if (ret != -1) return ret;
  ret = 0;
  if (d == N) return ret;
  for (int i = 0; i <= e; i++)
    ret = max(ret, V[d]*i + doit(d+1, min(E, e-i+R)));
  return ret;
}

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    cin >> E >> R >> N;
    for (int i = 0; i < N; i++) cin >> V[i];
    memset(memo, -1, sizeof(memo));
    cout << "Case #" << prob++ << ": ";
    cout << doit(0, E) << endl;
  }
}
