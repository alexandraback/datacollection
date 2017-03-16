#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

long solve(long pos, long* v, long n, long e, long r, long eCur) {
  if (pos == n) return 0;

  long m = -1;
  long eNext;
  for (int es = 0; es <= eCur; es++) {
    eNext = min(e, eCur - es + r);
    m = max(solve(pos+1,v,n,e,r,eNext) + v[pos] * es, m);
  }

  return m;
}

int main() {
  int probs;
  cin >> probs;

  for (int p = 1; p <= probs; p++) {
    long r,e,n;
    cin >> e >> r >> n;

    long v[n];

    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    long long gain = solve(0,v,n,e,r,e);

    printf("Case #%i: %lli", p, gain);
    printf("\n");
  }
  return 0;
}
