/*
 * Google Code Jam 2014. Round 1C. Problem A
 * Vladimir Rutsky
 * 11.05.2014
 */

#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>
#include <set>
#include <cassert>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;
typedef long long ll_t;

string solve(ll_t P, ll_t Q)
{
  assert(P > 0 && Q > 0);

  if (P > Q)
    return "impossible";

  ll_t qa = Q, qb = 1;
  while (qa % 2 == 0)
  {
    qa /= 2;
    qb *= 2;
  }
  assert(Q == qa * qb);

  if (qa != 1)
  {
    if (P % qa != 0)
    {
      return "impossible";
    }
    else
    {
      P /= qa;
      Q /= qa;
      assert(Q == qb);
    }
  }

  while (Q % 2 == 0 && P % 2 == 0)
  {
    P /= 2;
    Q /= 2;
  }

  size_t k = 0;
  ll_t t = Q;
  while (t != 1)
  {
    assert(t % 2 == 0);
    ++k;
    t /= 2;
  }
  assert(ll_t(1) << k == Q);

  ll_t p = P;
  ll_t k1 = k;
  while (p != 1)
  {
    p = (p - p % 2) / 2;
    --k1;
  }
  assert(k1 >= 0);

  return to_string(k1);
}

int main()
{
  FILE * res = stdin;
  //res = std::freopen("small.in", "rt", stdin);
  //res = std::freopen("A-small-attempt0.in", "rt", stdin);
  //res = std::freopen("A-large.in", "rt", stdin);
  assert(res);

  size_t T;
  cin >> T;

  for (size_t ci = 1; ci <= T; ++ci)
  {
    ll_t P, Q;
    char tmp;
    cin >> P >> tmp >> Q;
    assert(tmp == '/');

    cout << "Case #" << ci << ": " << solve(P, Q) << "\n";
  }
}
