
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <map>

using namespace std;

int A, B, K;
int solve(int CASE) {

  cin >> A >> B >> K;

  unsigned long long yes = 0;

  for (unsigned long long i = 0; i < A; ++i)
    for (unsigned long long j = 0; j < B; ++j)
      if ((i&j) < K) ++yes;


  printf("Case #%d: %llu\n", CASE, yes);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    solve(i+1);

  return 0;
}

