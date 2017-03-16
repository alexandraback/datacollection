#include <stdio.h>
#include <vector>
#include <queue>

#define MAXN 1000002

using namespace std;

typedef pair<long long, long long> pii;

long long ndigits(long long a) {
  int n = 0;
  while (a) {
    a /= 10;
    n++;
  }
  return n;
}

long long pow10(int a) {
  long long n = 1;
  while (a) {
    n *= 10;
    a--;
  }
  return n;
}

int reverse(int a) {
  int rev = 0;
  while (a) {
    rev *= 10;
    rev += (a % 10);
    a /= 10;
  }
  //printf("reverse of %d is %d\n", orig, rev);
  return rev;
}

long long sub(long long f, long long t) {
  int nt = ndigits(t);
  long long opt = t - f; // not split
  //printf("to go from %lld to %lld baseline is %lld\n", f, t, opt);
  long long base = 1;// cost of mirroring once
  // the trailing zeroes
  for (int i = 1; i < nt; i++) {
    long long tst = pow10(i);
    if (((t % tst) == 0) && ((f % tst) > 0)) {
      // must increment
      base += tst - (f % tst);
      f += tst - (f % tst);
    }
  }
  //printf("now to go from %lld to %lld base is %lld\n", f, t, base);
  // all possible split points
  for (int i = 1; i < nt; i++) {
    long long cost = base; 
    // first, create the lower part
    long long sep = pow10(i);
    //printf("split at %d dig split is %lld\n", i, sep);
    long long lowf = f % sep, lowt = t % sep;
    cost += lowt - lowf;
    //printf("cost %lld because %lld to %lld\n", lowt - lowf, lowt, lowf);
    long long hif = f - lowf, hit = t - lowt;
    hif /= sep;
    hit /= sep;
    long long mf = reverse(hif), mt = reverse(hit);
    cost += mt - mf;
    opt = min(opt, cost);
  }
  return opt;
}

long long score(long long f, long long t) {
  //printf("score %lld %lld\n", f, t);
  int nt = ndigits(t);
  if (ndigits(f) < nt) {
    long long m = pow10(nt-1);
    long long val = score(f, m-1) + 2;
    //printf("score %lld %lld, pay %lld and then score %lld %lld\n",
        //f, t, val, m+1, t);
    return val + score(m+1, t);
  }
  if (ndigits(t) == 1)
    return t - f + 1;
  if (f == t)
    return 0;
  if (f == t+1)
    return -1; // special
  return min(sub(f, t), sub(f, t-1) + 1); // leading zeroes
}
  

int main() {
  int T;
  scanf("%d", &T);
  for (int ncase = 0; ncase < T; ncase++) {
    int N;
    scanf("%d", &N);
    printf("Case #%d: %lld\n", ncase + 1, score(1, N));
  }
  return 0;
}
