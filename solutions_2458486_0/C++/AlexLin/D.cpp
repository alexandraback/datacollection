#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
//{{{Commonly used macro
//-----------------------By cylixstar-----------------------//
#define REP(i, n) for (int n_##__LINE__= (n), i = 0; i < n_##__LINE__; ++i)
#define FOR(i, f, t) for (__typeof__(f) f_##__LINE__=(f), t_##__LINE__=(t), i = f_##__LINE__; i <= t_##__LINE__; ++i)
#define TR(c, it) for (__typeof__((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
#define SZ(a) ((int)(a).size())
#define CLR(a, v) do { memset(a, v, sizeof(a)); } while(0)
#define DBG(a) do { std::cout << "[" << __FUNCTION__ << "]" << #a << ": " << a << endl; } while(0)

template<typename T>
inline void checkMax(T& a, const T& b) {
  if (a < b) a = b;
}

template<typename T>
inline void checkMin(T& a, const T& b) {
  if (a > b) a = b;
}

//}}}

const int kMaxK = 200 + 10;
const int kMaxN = 20;
multiset<int> init_key_set;
vector<int> key_inside[kMaxN];
int chest_type[kMaxN];
int num_chest, num_init_key;

void init() {
  init_key_set.clear();
  REP (i, num_chest) key_inside[i].clear();
}

void getKey(int st, multiset<int>& res) {
  int msk = 1;
  REP (i, num_chest) {
    if (msk & st) {
      for (int k: key_inside[i]) {
        res.insert(k);
      }
    }
    msk <<= 1;
  }
  msk = 1;
  REP (i, num_chest) {
    if (msk & st) {
      res.erase(res.find(chest_type[i]));
    }
    msk<<=1;
  }
}

int bp[1<<kMaxN];

void printAns(int cur) {
  if (!cur) return;
  printAns(bp[cur]);
  int d = cur ^ bp[cur];
  printf(" %d", __builtin_ctz(d) + 1);
}

void go() {
  fill(bp, bp + (1<<num_chest), -1);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()) {
    int top = Q.front();
    //printf("Top %d\n", top);
    Q.pop();
    multiset<int> S(init_key_set);
    getKey(top, S);
    /*for (auto k: S) {
      printf(" %d", k);
    }
    puts("");*/
    for (int i = 0, msk = 1; i < num_chest; ++i, msk <<= 1) {
      if (!(msk & top)) {
        if (!S.count(chest_type[i])) continue;
        //printf("Next %d %d %d %d\n", top, top | msk, chest_type[i], S.count(chest_type[i]));
        if (bp[msk | top] >= 0) {
          /*if (bp[msk | top] > top) {
            bp[msk | top] = top;
          }*/
          continue;
        }
        bp[msk | top] = top;
        Q.push((top | msk));
      }
    }
  }
  if (bp[(1<<num_chest) - 1] < 0) {
    puts(" IMPOSSIBLE");
    return;
  }
  int cur = (1<<num_chest) - 1;
  printAns(cur);
  puts("");
}
int main() {
  int n_case;
  scanf("%d", &n_case);
  REP (idx_case, n_case) {
    printf("Case #%d:", idx_case + 1);

    init();
    scanf("%d%d", &num_init_key, &num_chest);
    int t, kk;
    REP (i, num_init_key) {
      scanf("%d", &t);
      init_key_set.insert(t);
    }

    REP (i, num_chest) {
      scanf("%d%d", &t, &kk);
      chest_type[i] = t;
      REP (j, kk) {
        int key_type;
        scanf("%d", &key_type);
        key_inside[i].push_back(key_type);
      }
    }
    go();
  }
  return 0;
}

