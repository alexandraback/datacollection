#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long mem[1000000] = {0};

long long reverse(long long x) {
  long long r = 0;
  while(x > 0) {
    r = r * 10 + (x % 10);
    x = x/10;
  }
  return r;
}

long long solve(long long N) {
  //cout << N << endl;
  if (mem[N] != 0) return mem[N];
  long long result = 0;

  long long rev = reverse(N);
  if (rev >= N || N % 10 == 0) {
    result = solve(N-1) + 1;
  } else {
    result = min(solve(N-1), solve(rev)) + 1;
  }

  mem[N] = result;
  return result;
}

int main() {
  //mem = new long long[1000000];
  mem[1] = 1;

  int T = 0;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    long long N = 0;
    cin >> N;
    long long result = solve(N);
    cout << "Case #" << i << ": " << result << endl;
  }
  return 0;
}
