#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

vector<pair<long long, int> > rastavi(long long X) {
  vector<pair<long long, int> > sol;
  long long p = 1;
  int i = 0;

  for (; (p*2) <= X; p *= 2, ++i) {
    sol.push_back(make_pair(p, i));
  }

  assert(X & p);
  assert(X < (p*2));
  X -= p;
  long long t = p;

  for ( ; p; p /= 2, --i) {
    if (p & X) {
      sol.push_back(make_pair(t, i));
      t += p;
      X -= p;
    }
  }
  sol.push_back(make_pair(t, 0));
  return sol;
}

long long calc(pair<long long, int> A, pair<long long, int> B, long long K) {
  long long sol = 0;
  long long koeficijent = 1LL;
  long long p = 1;
  int i = 0;

  bool debug = false;
  if (A == make_pair(32LL, 3) && B == make_pair(32LL, 4)) debug = true;

  for ( ; p <= A.first || p <= B.first || p <= K; p *= 2, i++);

  for ( ; i >= 0; p /= 2, --i) {
    long long Kdigit = !!(K & p);
    long long Adigit = !!(A.first & p);
    long long Bdigit = !!(B.first & p);
    bool Aany = i < A.second;
    bool Bany = i < B.second;

    if (Aany && Bany) {
      if (Kdigit == 0) koeficijent *= 3;
      if (Kdigit == 1) sol += (3 * p * p) * koeficijent;
    }
    if (!Aany && Bany) {
      if (Adigit == 0 && Kdigit == 0) koeficijent *= 2;
      if (Adigit == 1 && Kdigit == 0) continue;
      if (Adigit == 0 && Kdigit == 1) {
        sol += (1LL << A.second) * (1LL << (i+1)) * koeficijent;
        break;
      }
      if (Adigit == 1 && Kdigit == 1) {
        sol += (1LL << A.second) * (1LL << i); // if we set B to be 0
        continue; // if we set B to be 1
      }
    }
    if (Aany && !Bany) {
      if (Bdigit == 0 && Kdigit == 0) koeficijent *= 2;
      if (Bdigit == 1 && Kdigit == 0) continue;
      if (Bdigit == 0 && Kdigit == 1) {
        sol += (1LL << B.second) * (1LL << (i+1)) * koeficijent;
        break;
      }
      if (Bdigit == 1 && Kdigit == 1) {
        sol += (1LL << B.second) * (1LL << i); // if we set A to be 0
        continue; // if we set A to be 1
      }
    }
    if (!Aany && !Bany) {
      long long ABdigit = Adigit && Bdigit;
      if (Kdigit == 0 && ABdigit == 1) {
        break;
      }
      if (Kdigit == 1 && ABdigit == 1) continue;
      if (Kdigit == 1 && ABdigit == 0) {
        sol = (1LL << A.second) * (1LL << B.second);
        break;
      }
      if (Kdigit == 0 && ABdigit == 0) continue;
    }
  }

  return sol;
}

long long solve(long long A, long long B, long long K) {
  vector<pair<long long, int> > Arastav, Brastav;

  Arastav = rastavi(A);
  Brastav = rastavi(B);

  long long sol = 0;
  for (int i = 0; i < Arastav.size(); ++i) {
    for (int j = 0; j < Brastav.size(); ++j) {
      sol += calc(Arastav[i], Brastav[j], K);
    }
  }

  return sol;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    long long a, b, k;
    scanf("%lld%lld%lld", &a, &b, &k);
    if (a == 1) {
      printf("Case #%d: %lld\n", tt, b);
    } else if (b == 1) {
      printf("Case #%d: %lld\n", tt, a);
    }else if (k == 0) {
      printf("Case #%d: 0\n", tt);
    } else {
      printf("Case #%d: %lld\n", tt, solve(a - 1, b - 1, k) + a + b - 1);
    }
  }
  return 0;
}
