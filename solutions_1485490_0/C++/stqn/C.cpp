#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

int N, M;
vector<int> a, b;
vector<ll> A, B;

ll mem[128][128] = {};

ll recur(int i, int j) {

  if (i >= N || j >= M) return 0;
  if (mem[i][j]) return mem[i][j];
  if (a[i] != b[j]) return max(recur(i + 1, j), recur(i, j + 1));

  ll res = min(A[i], B[j]);
  ll foo = A[i] - B[j];
  int _i = i;
  int _j = j;
  ll _res = res;
  for (;;) {
    res = max(res, _res + recur(_i + 1, _j + 1));
    if (foo < 0) {
      while (++_i < N && a[_i] != a[i]);
      if (_i >= N) break;
      _res += min(A[_i], abs(foo));
      foo += A[_i];
    }
    else if (foo > 0) {
      while (++_j < M && b[_j] != b[j]);
      if (_j >= M) break;
      _res += min(B[_j], abs(foo));
      foo -= B[_j];
    }
    else break;
  }

  return mem[i][j] = res;

}

int main() {

  int T;
  cin >> T;
  for (int x = 1; x <= T; ++x) {
    cin >> N >> M;
    a.resize(N); A.resize(N);
    b.resize(M); B.resize(M);
    for (int i = 0; i < N; ++i)
      cin >> A[i] >> a[i];
    for (int i = 0; i < M; ++i)
      cin >> B[i] >> b[i];
    memset(mem, 0, sizeof(mem));
    ll ans = recur(0, 0);
    cout << "Case #" << x << ": " << ans << endl;
  }

  return 0;

}
