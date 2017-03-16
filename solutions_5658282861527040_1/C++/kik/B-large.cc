#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <utility>
#include <tuple>

using namespace std;

typedef unsigned long long ull;

typedef tuple<ull, ull, ull, ull, ull> k_t;

map<k_t, ull> memo;

struct X
{
  ull v1, v2;
  ull bit;

  X(ull v1, ull v2, ull bit)
    : v1(v1), v2(v2), bit(bit)
  {
  }
};

void split(vector<X>& r, ull A1, ull A2)
{
  ull A1x = A1 >> 1;
  ull A2x = A2 >> 1;
  if (A1 & 1) {
    if (A2 & 1) {
      r.push_back(X(A1x, A1x + 1, 1));
      r.push_back(X(A1x + 1, A2x, 0));
      r.push_back(X(A1x + 1, A2x, 1));
      r.push_back(X(A2x, A2x + 1, 0));
    } else {
      r.push_back(X(A1x, A1x + 1, 1));
      r.push_back(X(A1x + 1, A2x, 0));
      r.push_back(X(A1x + 1, A2x, 1));
    }
  } else {
    if (A2 & 1) {
      r.push_back(X(A1x, A2x, 0));
      r.push_back(X(A1x, A2x, 1));
      r.push_back(X(A2x, A2x + 1, 0));
    } else {
      r.push_back(X(A1x, A2x, 0));
      r.push_back(X(A1x, A2x, 1));
    }
  }
}

ull solve(ull A1, ull A2, ull B1, ull B2, ull K)
{
  if (A1 >= A2 || B1 >= B2) return 0;
  if (A2 == 1 && B2 == 1) return K > 0 ? 1 : 0;

  k_t k = make_tuple(A1, A2, B1, B2, K);
  auto xx = memo.find(k);
  if (xx != memo.end()) {
    return xx->second;
  }

  vector<X> as;
  vector<X> bs;

  split(as, A1, A2);
  split(bs, B1, B2);

  ull r = 0;
  for (int i = 0; i < as.size(); i++) {
    for (int j = 0; j < bs.size(); j++) {
      ull bit = as[i].bit & bs[j].bit;
      if (!bit && (K & 1)) {
        r += solve(as[i].v1, as[i].v2, bs[j].v1, bs[j].v2, K / 2 + 1);
      } else {
        r += solve(as[i].v1, as[i].v2, bs[j].v1, bs[j].v2, K / 2);
      }
    }
  }

  memo[k] = r;

  return r;
}

int main()
{
  int T;

  cin >> T;

  for (int cas = 1; cas <= T; cas++) {
    ull A, B, K;
    cin >> A >> B >> K;

    ull r = solve(0, A, 0, B, K);

    cout << "Case #" << cas << ": " << r << endl;
  }

  return 0;
}
