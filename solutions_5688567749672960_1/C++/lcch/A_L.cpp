#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

long long N;
long long p10[16], g[16];

long long rev_num(long long x) {
  long long  tmp = 0;
  while (x > 0) {
    tmp = tmp * 10 + x % 10;
    x /= 10;
  }
  return tmp;
}

int get_len(long long N) {
  int len = 0;
  for (; N > 0; N /= 10) len ++;
  return len;
}

void pre_go() {
  p10[1] = 1;
  for (int i = 2; i <= 15; i++) p10[i] = p10[i-1] * 10;
  
  g[1] = 1, g[2] = 10;
  for (int i = 3; i <= 15; i++) {
    if (i % 2 == 0) {
      g[i] = g[i-1] + p10[i/2+1] + p10[i/2] - 1;
    } else {
      g[i] = g[i-1] + p10[(i+1) / 2] * 2 - 1;
    }
  }
}

long long go(long long N) {
  if (N <= 10) return N;
  int len = get_len(N);
  if (N == p10[len]) return g[len];

  long long ans = 0;
  ans += g[len];
  if (N % 10 == 0) {
    N--;
    ans += 1;
  }

  long long tmp = N - p10[len], tmp1, tmp2;
  long long fir, sec;
  if (len % 2 == 0) {
    sec = N / p10[len / 2 + 1];
    fir = N % p10[len / 2 + 1];
    tmp = min(tmp, rev_num(sec) + fir);
  } else {
    sec = N / p10[len / 2 + 1];
    fir = N % p10[len / 2 + 1];
    tmp1 = rev_num(sec) + fir;
    
    sec = N / p10[len / 2];
    fir = N % p10[len / 2];
    tmp2 = rev_num(sec) + fir;
    
    tmp = min(tmp, min(tmp1, tmp2));
  }
  ans += tmp;
  return ans;
}

int main()
{
  freopen("A-large.in", "r", stdin);
  freopen("A_large.out", "w", stdout);
  pre_go();
  int TextN;
  cin >> TextN;
  for (int TT = 1; TT <= TextN; TT++) {
    cin >> N;
    cout << "Case #" << TT << ": " << go(N) << endl;
  }
  return 0;
}