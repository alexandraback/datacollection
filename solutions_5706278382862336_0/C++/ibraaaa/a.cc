#include <algorithm>
#include <assert.h>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <numeric>
#include <limits>
#include <iomanip>
using namespace std;

#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define LL long long
#define LD long double
#define vi vector<int>
#define vl vector<LL>
#define vs vector<string>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>
#define SET(v, i) (v | (1 << i))
#define TEST(v, i) (v & (1 << i))
#define TOGGLE(v, i) (v ^ (1 << i))

struct Parents {
  pair<LL, LL> m;
  pair<LL, LL> f;
  Parents(const pair<LL, LL>& _m, const pair<LL, LL>& _f)
    : m(_m), f(_f) {}

  Parents() {}
};

vector<set<pair<LL, LL> > > num(41);

map<pair<LL, LL>, Parents> parent_map;

LL GCD(LL a, LL b) {
  return b == 0 ? a : GCD(b, a % b);
}

void Solve() {
  num[0].insert(make_pair(0, 1));
  num[0].insert(make_pair(1, 1));
  for (int i = 1; i < 20; ++i) {
    num[i].insert(make_pair(0, 1));
    num[i].insert(make_pair(1, 1));
    for (auto it = num[i - 1].begin(); it != num[i - 1].end(); ++it) {
      auto it2 = it;
      ++it2;
      for (; it2 != num[i - 1].end(); ++it2) {
        LL a = it->first, b = it->second;
        LL c = it2->first, d = it2->second;
        LL up = a * d + c * b;
        LL down = 2 * b * d;
        LL gcd = GCD(up, down);
        up /= gcd;
        down /= gcd;
        if (up > 1000 || down > 1000)
          break;

        if (!parent_map.count(make_pair(up, down)))
          parent_map[make_pair(up, down)] = Parents(*it, *it2);

        num[i].insert(make_pair(up, down));
      }
    }
  }

}

int Find(const pair<LL, LL>& v) {
  if (v.first == 0 && v.second == 1)
    return 10000;
  if (v.first == 1 && v.second == 1)
    return 0;

//  cout << v.first << "\t" << v.second << endl;
  return min(1 + Find(parent_map[v].f), 1 + Find(parent_map[v].m));
}

int main() {
  int t;
  scanf("%d", &t);
  LL p, q;
  Solve();
  for (int i = 1; i <= t; ++i) {
    scanf("%lld/%lld", &p, &q);
    pair<LL, LL> ip = make_pair(p, q);
    printf("Case #%d: ", i);
    bool found = false;
    for (int j = 0; j < sz(num); ++j) {
      if (num[j].count(ip)) {
        int ret = Find(ip);
        printf("%d\n", ret);
        found = true;
        break;
      }
    }

    if (!found)
      printf("impossible\n");
  }

  return 0;
}
