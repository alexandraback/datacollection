#include <bits/stdc++.h>

using namespace std;

template<class T> inline T sqr(const T& a) {
  return a * a;
}

template<class T> inline T middle(const T &a, const T &b) {
  return (a + b) / 2;
}

template<class T> inline int len(const T &c) {
  return static_cast<int>(c.size());
}

typedef long long li;
typedef long double ld;
typedef pair<li, li> pt;

const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 100000;
const int N32 = N * 32;
const int C = 20;

int sieve[N];
int p100[100];

inline void SieveSet(int n) {
  sieve[n >> 5] |= 1 << (n & 31);
}

inline bool SieveGet(int n) {
  return (sieve[n >> 5] & (1 << (n & 31))) > 0;
}

void init() {
  SieveSet(0);
  SieveSet(1);
  for (int i = 4; i < N32; i += 2) {
    SieveSet(i);
  }
  int k = 0;
  p100[k++] = 2;
  for (int i = 3; i < N32; i += 2) {
    if (!SieveGet(i)) {
      if (k < 100) {
        p100[k++] = i;
      }
      for (int j = i * 3; j < N32; j += i) {
        SieveSet(j);
      }
    }
  }
}

bool IsPrime(li x, li &di) {
  if (x < N32) {
    if (!SieveGet((int) x)) {
      return true;
    }
  }
  if (x % 2 == 0) {
    di = 2;
    return false;
  }
  for (li i = 3; i * i <= x; i += 2) {
    if (x % i == 0) {
      di = i;
      return false;
    }
  }
  return true;
}

bool Valid(li bits, int leng, vector<li> &dis) {
  dis.clear();

  li di;
  if (IsPrime(bits, di)) {
    return false;
  }
  dis.push_back(di);

  for (li b = 3; b <= 10; ++b) {
    vector<li> cur(C, 0);
    vector<li> pw(C, 1);
    for (int i = 0; i < leng; ++i) {
      if (bits & (1 << i)) {
        for (int j = 0; j < C; ++j) {
          cur[j] = (cur[j] + pw[j]) % p100[j];  
        }
      }
      for (int j = 0; j < C; ++j) {
        pw[j] = (pw[j] * b) % p100[j];  
      }
    }
    bool flag = false;
    for (int j = 0; j < C; ++j) {
      if (cur[j] == 0) {
        dis.push_back(p100[j]);
        flag = true;
        break;
      }
    }
    if (!flag) {
      return false;
    }
  }

  assert(9 == len(dis));
  return true;
}

void HandleCase() {
  int n, m;
  scanf("%d%d", &n, &m);
  li basic = (1ll << (n - 1)) | 1ll;

  int nmask = 1 << (n - 2);
  vector<li> dis;
  vector<pair<li, vector<li> > > found;
  for (int mask = 0; mask < nmask; ++mask) {
    li cur = basic | (mask << 1);
    if (Valid(cur, n, dis)) {
      found.push_back({cur, dis});
      if (len(found) >= m) {
        break;
      }
    }
  }

  assert(len(found) >= m);
  puts("");
  for (auto &p : found) {
    for (int i = n - 1; i >= 0; --i) {
      printf("%d", (p.first & (1ll << i)) ? 1 : 0);
    }
    for (li di : p.second) {
      printf(" %lld", di);
    }
    puts("");
  }
}

int main() {
  init();
  int tests;
  scanf("%d", &tests);
  for (int test = 1; test <= tests; ++test) {
    printf("Case #%d: ", test);
    HandleCase();
  }
  return 0;
}
