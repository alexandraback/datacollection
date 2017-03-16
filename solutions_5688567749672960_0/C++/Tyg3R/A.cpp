#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

ll get10tox(int x) {
  ll res = 1;
  while(x > 0) {
    x--;
    res *= 10LL;
  }
  return res;
}

ll getNext(int dig) {
  if(dig & 1) {
    return get10tox(dig/2)+get10tox(dig/2+1)-1LL;
  } else {
    return 2LL*get10tox(dig/2)-1LL;
  }
}

ll getFirst(ll x, int n, int of) {
  int del = of-n;
  while(del--) x /= 10LL;
  return x;
}

ll getLast(ll x, int n, int of) {
  ll nx = x;
  int del = n;
  while(del--) nx /= 10LL;
  while(n--) nx *= 10LL;
  return x-nx;
}

ll reverse(ll x) {
  ll res = 0;
  while(x) {
    ll n = x%10LL;
    x /= 10LL;
    res *= 10LL;
    res += n;
  }
  return res;
}

int main ()
{
  DRI(T);
  FOR(t,0,T) {
    ll N;
    cin >> N;
    if(N < 10LL) {
      printf("Case #%d: %lld\n", t+1, N);
      continue;
    }
    int digits = 0;
    ll n = N;
    while(n > 0LL) {
      digits++;
      n /= 10LL;
    }
    ll res = 0;
    FOR(i,1,digits) {
      res += getNext(i);
    }
    if(N == get10tox(digits-1)) {
      // res ok
    } else if(reverse(getFirst(N,digits/2,digits)) == 1LL) {
      res += getLast(N,(digits+1)/2,digits);
    } else {
      ll res2 = res + (N-get10tox(digits-1));
      ll L = getFirst(N,digits/2,digits);
      ll R = getLast(N,(digits+1)/2,digits);
      ll rL = reverse(L);
      ll res3 = res + R + rL;
      ll nL = L-1LL;
      ll nrL = reverse(nL);
      ll res4 = res + nrL + R + get10tox((digits+1)/2);
      res = min(res2,res4);
      if(R > 0) res = min(res, res3);
    }
    printf("Case #%d: %lld\n", t+1, res);
  }
  return 0;
}
