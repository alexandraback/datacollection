#include <map>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int motes[1000000+1];
int needed[1000000+1];

int calc(int from, int to, int& result) {
  int added = 0;
  while (from <= to) {
    from += from-1;
    ++added;
  }

  result = from;
  return added;
}

void solve (int a_case) {

  int A, N;
  cin >> A >> N;
  for (int i = 0; i < N; ++i) cin >> motes[i];

  if (A < 2) {
    printf("Case #%d: %d\n", a_case, N);
    return;
  }

  std::sort(motes, motes+N);

  for (int i = 0; i < N; ++i) {
    if (motes[i] < A) {
      needed[i+1] = needed[i];
      A += motes[i];
    } else {
      int newA;
      needed[i+1] = needed[i] + calc(A, motes[i], newA);
      A = newA + motes[i];
    }
  }

  int minimum = N;
  for (int i = 0; i < N; ++i) {
    int cost = needed[i+1] + (N - (i+1));
    // cout << motes[i] << " " << needed[i+1] << ". cost: " <<  cost << endl;

    minimum = std::min(minimum, cost);
  }

  printf("Case #%d: %d\n", a_case, minimum);
}

int main ()
{
  int n;
  string dummy;

  cin >> n;
  getline(cin, dummy);
  for (int i = 0; i < n; ++i) solve(i+1);

  return 0;
}

