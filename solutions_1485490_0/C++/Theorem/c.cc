#include <iostream>
#include <string.h>
#include <sstream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <map>

using namespace std;


long long boxes[200][2];
long long toys[200][2];

struct state {
  long long a, b;

  long long i;
  long long j;
  long long is;
  long long js;
  long long profit;
};

std::map<std::pair<long long, long long>, state> ks;

long long NN, NM;
int N, M;

void mk(state s)
{
  if (s.i > N || s.j > M) return;

  ////printf("%lld %lld %lld %lld\n", s.i, s.j, s.a, s.b);

  std::map<std::pair<long long, long long>, state>::iterator it = ks.find(make_pair(s.a, s.b));
  if (it != ks.end()) {
    if (it->second.profit < s.profit) {
      ks[make_pair(s.a, s.b)] = s;
      //printf("wee %lld AT %lld %lld\n", s.profit, s.a, s.b);
    }
  } else {
      ks[make_pair(s.a, s.b)] = s;
      //printf("wee %lld AT %lld %lld\n", s.profit, s.a, s.b);
  }

  if (s.i == N && s.j == M) return;

  if (boxes[s.i][0] == toys[s.j][0]) {
    long long p = std::min(boxes[s.i][1] - s.is, toys[s.j][1] - s.js);

    //printf("profit %lld (%lld %lld)\n", p, s.is, s.js);
    state n;
    n.a = s.a + p;
    n.b = s.b + p;
    n.profit = s.profit + p;

    if (p == boxes[s.i][1] - s.is) n.i = s.i + 1, n.is = 0;
    else n.i = s.i, n.is = s.is + p;

    if (p == toys[s.j][1] - s.js) n.j = s.j + 1, n.js = 0;
    else n.j = s.j, n.js = s.js + p;

    mk(n);

  } else {

    {
    state n;
    n.a = s.a + boxes[s.i][1] - s.is; n.b = s.b;
    n.i = s.i + 1; n.j = s.j;
    n.is = 0; n.js = s.js;
    n.profit = s.profit;
    mk(n);
    }
    {
    state n;
    n.a = s.a; n.b = s.b + toys[s.j][1] - s.js;
    n.i = s.i; n.j = s.j + 1;
    n.is = s.is; n.js = 0;
    n.profit = s.profit;
    mk(n);
    }

  }
}

void solve (int a_case)
{
  cin >> N >> M;

  NN = 0;
  NM = 0;

  for (int i = 0; i < N; ++i) { cin >> boxes[i][1] >> boxes[i][0]; NN += boxes[i][1]; }
  for (int i = 0; i < M; ++i) { cin >> toys[i][1] >> toys[i][0]; NM += toys[i][1]; }

  state s;
  s.a = s.b = 0;
  s.i = s.j = 0;
  s.is = s.js = 0;
  s.profit = 0;
  mk(s);

  long long best = ks[make_pair(NN, NM)].profit;
  printf("Case #%d: %lld\n", a_case, best);
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

