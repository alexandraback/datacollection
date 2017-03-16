#include <cstdio>
#include <cstring>

struct quat {
  int sign;
  int val;

  void fromChar(char x) {
    sign = 1;
    switch (x) {
      case 'i':
        val = 1;
        break;
      case 'j':
        val = 2;
        break;
      case 'k':
        val = 3;
        break;
      default:
        val = 0;
        break;
    }
  }

  quat operator*(quat o) {
    quat res;
    res.sign = sign * o.sign;
    if (val == 0) {
      res.val = o.val;
    } else if (o.val == 0) {
      res.val = val;
    } else {
      if (val == o.val) {
        res.sign = -res.sign;
        res.val = 0;
      } else if (val % 3 == o.val - 1) {
        res.val = 6 - val - o.val;
      } else {
        res.sign = -res.sign;
        res.val = 6 - val - o.val;
      }
    }
    return res;
  }

  int toInt() {
    if (sign == 1) {
      return val;
    } else {
      return val + 4;
    }
  }
};

long long l, x;
char pat[1 << 20];

// Prefix until right before.
//
quat pref[1 << 17], suff[1 << 17];

bool seen[8][8];
bool used[8][8][8][8];

int main() {
  int t, T;
  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    scanf("%lld %lld", &l, &x);
    scanf("%s", pat);

    // must match i, j, k.
    //
    pref[0].fromChar('1');
    for (int i = 0; i < l; ++i) {
      pref[i + 1].fromChar(pat[i]);
      pref[i + 1] = pref[i] * pref[i + 1];
    }

    // for (int i = 0; i <= l; ++i) {
    //   printf("PREF %d (%d %d)\n", i, pref[i].sign, pref[i].val);
    //   if (i < l) {
    //     quat tmp;
    //     tmp.fromChar(pat[i]);
    //     printf("opa opa %c %d %d\n", pat[i], tmp.sign, tmp.val);
    //   }
    // }

    suff[l].fromChar('1');
    for (int i = l - 1; i >= 0; --i) {
      suff[i].fromChar(pat[i]);
      suff[i] = suff[i] * suff[i + 1];
    }

    bool ok = false;
    // 1. Two splits same pattern.
    //
    memset(seen, 0, sizeof(seen));
    for (int f = 0; f < l && !ok; ++f) {
      quat m;
      m.fromChar('1');
      // Split right before f, and right after s.
      //
      for (int s = f; s < l && !ok; ++s) {
        quat tmp;
        tmp.fromChar(pat[s]);
        m = m * tmp;

        quat b = pref[f];
        quat e = suff[s + 1];
        if (m.sign == 1 && m.val == 2) {
          if (!seen[b.toInt()][e.toInt()]) {
            seen[b.toInt()][e.toInt()] = 1;
            for (int pre = 0; pre + 1 <= x && pre <= 3; ++pre) {
              for (int aft = 0; aft + pre + 1 <= x && aft <= 3; ++aft) {
                if ((pre + aft + 1) % 4 == x % 4) {
                  quat beg;
                  beg.fromChar('1');
                  for (int i = 0; i < pre; ++i) {
                    beg = beg * pref[l];
                  }
                  beg = beg * b;
                  quat end;
                  end.fromChar('1');
                  for (int i = 0; i < aft; ++i) {
                    end = suff[0] * end;
                  }
                  end = e * end;
                  if (beg.sign == 1 && beg.val == 1) {
                    if (end.sign == 1 && end.val == 3) {
                      ok = true;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    // 2. Split in two different segments.
    //
    memset(used, 0, sizeof(used));
    for (int f = 0; f <= l && !ok; ++f) {
      for (int s = 0; s <= l && !ok; ++s) {
        if (!used[pref[f].toInt()][suff[f].toInt()][pref[s].toInt()][suff[s].toInt()]) {
          used[pref[f].toInt()][suff[f].toInt()][pref[s].toInt()][suff[s].toInt()] = 1;
          for (int pre = 0; pre + 2 <= x && pre <= 3; ++pre) {
            for (int mid = 0; mid + pre + 2 <= x && mid <= 3; ++mid) {
              for (int aft = 0; aft + mid + pre + 2 <= x && aft <= 3; ++aft) {
                if ((pre + mid + aft + 2) % 4 == x % 4) {
                  quat beg;
                  beg.fromChar('1');
                  for (int i = 0; i < pre; ++i) {
                    beg = beg * pref[l];
                  }
                  beg = beg * pref[f];
                  quat mi;
                  mi = suff[f];
                  for (int i = 0; i < mid; ++i) {
                    mi = mi * pref[l];
                  }
                  mi = mi * pref[s];
                  quat end;
                  end = suff[s];
                  for (int i = 0; i < aft; ++i) {
                    end = end * pref[l];
                  }
                  // printf("OP %d %d [%d %d %d]: (%d %d) (%d %d) (%d %d)\n", f, s, pre, mid, aft, beg.sign, beg.val, mi.sign, mi.val, end.sign, end.val);
                  if (beg.sign == 1 && beg.val == 1) {
                    if (mi.sign == 1 && mi.val == 2) {
                      if (end.sign == 1 && end.val == 3) {
                        ok = true;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    // printf("%d\n", ok);
    printf("Case #%d: %s\n", t, ok ? "YES" : "NO");
  }
  return 0;
}
