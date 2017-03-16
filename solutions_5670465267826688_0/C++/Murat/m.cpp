#include<bits/stdc++.h>
  
using namespace std;

template<class T> inline T sqr(const T& a) { return a * a; }
  
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
  
constexpr ld EPS = 1e-9;
constexpr ld PI = 2 * acos(0.0);
constexpr int N = 100;

struct qua {
  int dig;
  bool neg;
  qua () {}
  qua (int _dig, bool _neg) : dig(_dig), neg(_neg) {}
  void Print() {
    if (neg)
      printf("-");
    char ch;
    switch(dig) {
      case 0:
        ch = '1';
        break;
      case 1:
        ch = 'i';
        break;
      case 2:
        ch = 'j';
        break;
      case 3:
        ch = 'k';
        break;
      default:
        throw 1;
    }
    printf("%c ", ch);
  }
};

const qua kOne = { 0, false };

int to_dig[128];

qua table[4][4];

qua operator*(const qua &x, const qua &y) {
  qua &t = table[x.dig][y.dig];
  if (x.neg != y.neg)
    return { t.dig, !t.neg};
  return { t.dig, t.neg };
}

bool operator==(const qua &x, const qua &y) {
  return x.dig == y.dig && x.neg == y.neg;
}

qua Negate(const qua &x) {
  return { x.dig, !x.neg };
}

qua FromChar(char ch) {
  return { to_dig[int(ch)], false };
}

qua bpow(qua x, li y) {
  qua r = kOne;
  while (y) {
    if (y & 1) {
      r = r * x;
      --y;
    } else {
      x = x * x;
      y >>= 1;
    }
  }
  return r;
}

void Init() {
  to_dig['1'] = 0;
  to_dig['i'] = 1;
  to_dig['j'] = 2;
  to_dig['k'] = 3;
  for (int i = 0; i < 4; ++i)
    table[i][0] = table[0][i] = { i, false };
  for (int i = 1; i < 4; ++i)
    table[i][i] = { 0, true };
  table[1][2] = { to_dig['k'], false };
  table[2][1] = { to_dig['k'], true };

  table[1][3] = { to_dig['j'], true };
  table[3][1] = { to_dig['j'], false };

  table[2][3] = { to_dig['i'], false };
  table[3][2] = { to_dig['i'], true};
}

li FindI(li rep, const vector<qua> &q, const qua total) {
  qua target = FromChar('i');
  int len = int(q.size());
  int rend = (int) min(5ll, rep);
  for (int r = 0; r < rend; ++r) {
    qua acc = bpow(total, r);
    for (int i = 0; i < len; ++i) {
      acc = acc * q[i];
      if (acc == target)
        return i + r * len + 1;
    }
  }
  return -1;
}

li FindK(li rep, li start, const vector<qua> &q, const qua total) {
  int len = int(q.size());
  li cur_end = ((start + len - 1) / len) * len;
  qua acc = FromChar('i');
  qua target = FromChar('k');
  for (int j = (int) (start % len); start < cur_end; ++start, ++j) {
    acc = acc * q[j];
    if (acc == target)
      return start + 1;
  }
  li repeated = start / len;
  int rend = (int) min(5ll, rep - repeated);
  qua saved = acc;
  for (int r = 0; r < rend; ++r) {
    acc = saved * bpow(total, r);
    for (int i = 0; i < len; ++i) {
      acc = acc * q[i];
      if (acc == target)
        return start + r * len + i + 1;
    }
  }
  return -1;
}

bool Solve() {
  int len;
  li rep;
  scanf("%d%lld\n", &len, &rep);
  string s;
  getline(cin, s);
  qua total = kOne;
  vector<qua> q;
  for (int i = 0; i < len; ++i) {
    qua cur = FromChar(s[i]);
    total = total * cur;
    q.push_back(cur);
  }
  qua acc = bpow(total, rep);
  //printf("  Total: ");
  //total.Print();
  //printf("  With reps: ");
  //acc.Print();
  if (!(acc == Negate(kOne)))
    return false;
  li pos_i = FindI(rep, q, total);
  //printf("  i reached at %lld\n", pos_i);
  if (pos_i < 0 || pos_i >= len * rep)
    return false;
  li pos_k = FindK(rep, pos_i, q, total);
  //printf("  j reached at %lld\n", pos_k);
  if (pos_k < 0)
    return false;
  return true;
}

int main() {
  Init();
  int tests;
  scanf("%d", &tests);
  for (int it = 1; it <= tests; ++it) {
    printf("Case #%d: %s\n", it, Solve() ? "YES" : "NO");
  }
  return 0;
}
