#include <climits>
#include <iostream>
#include <map>
using namespace std;

map<long, long> memo;

long reverse(long N) {
  long M = 0;
  while (N > 0)  {
    M = 10*M + N % 10;
    N /= 10;
  }
  return M;
}

long countMinSteps(long N) {
  if (memo.count(N)) { return memo[N]; }
  long steps = 1 + countMinSteps(N-1);
  if (N > 10 && N % 10 != 0) {
    long reversedN = reverse(N);
    if (reversedN < N) {
      steps = min(steps, 1 + countMinSteps(reversedN));
    }
  } 
  memo[N] = steps;
  return steps;
}

int main(int argc, char *argv[]) {
  memo.clear();
  memo[1] = 1;
  int T;
  cin >> T;
  for (long N = 1; N <= 999999; ++N) { 
    countMinSteps(N);
  }
  for (int i = 0; i < T; ++i) {
    long N; cin >> N;
    cout << "Case #" << i + 1 << ": "
         << countMinSteps(N)
         << endl;
  }
  return 0;
}
