#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define fr(a,b,c) for (int a = b ; a < c; ++a)
#define db(x) cerr << #x " == " << x << endl
#define _ << ", " <<
#define sf(f, x) scanf("%"#f, &x)

typedef long long ll;

ll ii(ll x) {
  ll r = 0;
  while (x) r = 10*r + x%10, x /= 10;
  return r;
}

#define M (1<<20)

ll q[M];
ll v[M];

void doit() {
  ll x;
  scanf("%lld", &x);
  printf("%lld\n", v[x]);
}

void prep() {
  memset(v,-1,sizeof v);
  int i = 0, f = 0;
  q[f++] = 1;
  v[1] = 1;

  while (i < f) {
    ll x = q[i++];
    ll y = x+1;
    if (y < M && !~v[y]) q[f++] = y, v[y] = v[x]+1;
    y = ii(x);
    if (y < M && !~v[y]) q[f++] = y, v[y] = v[x]+1;
  }
}

int main() {
  prep();
  int t; sf(d, t);
  fr(i,0,t) {
    printf("Case #%d: ", i+1);
    doit();
  }
  return 0;
}