#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int N;
int F[1024];
int used[1024];

int loop[1024];
int tail[1024];

void FindLoop(int p, int len) {
  used[p] = len;
  int next = F[p];
  if (used[next] > 0) {
    loop[next] = max(loop[next], len - used[next] + 1);
    if (F[next] == p) {
      tail[next] = max(tail[next], used[next] - 1);
    }
  } else {
    FindLoop(next, len+1);
  }
}

int Solve() {
  memset(loop, 0, sizeof(loop));
  memset(tail, 0, sizeof(tail));
  for (int i = 0; i < N; ++i) {
    memset(used, 0, sizeof(used));
    FindLoop(i, 1);
  }
  int r = 0;
  memset(used, 0, sizeof(used));
  int chain = 0;
  for (int i = 0; i < N; ++i) {
    // cerr << i << ": " << loop[i] << " " << tail[i] << endl;
    r = max(r, loop[i]);
    if (F[F[i]] == i && i < F[i]) {
      chain += tail[i] + tail[F[i]] + 2;
    }
  }
  return max(r, chain);
}

int main() {
  int nnn;
  cin >> nnn;
  for (int iii = 0; iii < nnn; ++iii) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
      cin >> F[i];
      --F[i];
    }
    cout << "Case #" << iii+1 << ": " << Solve() << endl;
  }
}
