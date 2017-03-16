#include<iostream>
#include<cstdio>

using namespace std;

long long pNeeded(long long r) {
  return 2*r + 1;
}

int main() {
  int probs;
  cin >> probs;

  for (int p = 1; p <= probs; p++) {
    long long r,t;
    cin >> r >> t;

    long long count = 0;

    for (long long i = r; true; i += 2) {
      t -= pNeeded(i);

      if (t >= 0)
        count++;
      else
        break;
    }

    printf("Case #%i: %lli", p, count);
    printf("\n");
  }
  return 0;
}
