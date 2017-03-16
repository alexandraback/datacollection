#include <cstdio>
#include <algorithm>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>
using namespace std;

int64_t ans1, ans2;
int64_t best1, best2;
string curs1;
string s1, s2;

void findBestSlower(int64_t idx2, int64_t ep) {
  if (idx2 == s1.size()) {
    if (ans1 == -1 || abs(ans1 - ans2) > abs(best1 - best2) || (abs(ans1 - ans2) == abs(best1 - best2) && (best1 < ans1 || (best1 == ans1 && best2 < ans2)))) {
      ans1 = best1;
      ans2 = best2;
    }
    return;
  }

  if (s2[idx2] == '?') {
    for (int i = 0; i <= 9; ++i) {
      best2 += ep * i;
      findBestSlower(idx2 + 1, ep * 10);
      best2 -= ep * i;
    }
  } else {
    best2 += ep * (s2[idx2] - '0');
    findBestSlower(idx2 + 1, ep * 10);
    best2 -= ep * (s2[idx2] - '0');
  }
}

void findBestSlow(int64_t idx2, int next, bool first) {
  //printf("%ld %d %ld %ld\n", idx2, next, best1, best2);

  if (idx2 == -1) {
    if (ans1 == -1 || abs(ans1 - ans2) > abs(best1 - best2) || (abs(ans1 - ans2) == abs(best1 - best2) && (best1 < ans1 || (best1 == ans1 && best2 < ans2)))) {
      ans1 = best1;
      ans2 = best2;
    }
    return;
  }
  //printf("%d %c\n", idx2, s2[idx2]);
  if (s2[idx2] == '?') {
    if (first) {
      for (int i = 0; i <= 9; ++i) {
        best2 *= 10;
        best2 += i;
        int nnext = next;
        if (nnext == -1 && i > curs1[idx2] - '0') nnext = 0;
        if (nnext == -1 && i < curs1[idx2] - '0') nnext = 9;
        findBestSlow(idx2 - 1, nnext, false);
        best2 /= 10;
      }
      return;
    }

    if (next != -1) {
      best2 *= 10;
      best2 += next;
      findBestSlow(idx2 - 1, next, first);
      best2 /= 10;
    } else {
      int cc = curs1[idx2] - '0';
      int clo = (cc + 9) % 10;
      int chi = (cc + 1) % 10;
      if (clo >= 0) {
        best2 *= 10;
        best2 += (clo);
        findBestSlow(idx2 - 1, 9, first);
        best2 /= 10;
      }
      if (chi <= 9) {
        best2 *= 10;
        best2 +=  (chi);
        findBestSlow(idx2 - 1, 0, first);
        best2 /= 10;
      }
      best2 *= 10;
      best2 += cc;
      findBestSlow(idx2 - 1, next, first);
      best2 /= 10;
    }
  } else {
    best2 *= 10;
    best2 += (s2[idx2] - '0');
    int nnext = next;
    if (nnext == -1 && (s2[idx2] - '0') > curs1[idx2] - '0') nnext = 0;
    if (nnext == -1 && (s2[idx2] - '0') < curs1[idx2] - '0') nnext = 9;
    findBestSlow(idx2 - 1, nnext, first);
    best2 /= 10;
  }
}

void solve(int64_t idx1, int64_t ep) {
  if (idx1 == s1.size()) {
    best2 = 0;
    findBestSlow(s1.size() - 1, -1, true);
    //findBestSlower(0, 1);
    return;
  }

  if (s1[idx1] == '?') {
    for (int i = 0; i <= 9; ++i) {
      best1 += ep * i;
      curs1[idx1] = i + '0';
      solve(idx1 + 1, ep * 10);
      best1 -= ep * i;
    }
  } else {
    best1 += ep * (s1[idx1] - '0');
    curs1[idx1] = s1[idx1];
    solve(idx1 + 1, ep * 10);
    best1 -= ep * (s1[idx1] - '0');
  }
}


int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    char buf1[50], buf2[50];
    scanf(" %s %s ", buf1, buf2);
    best1 = best2 = 0;
    ans1 = ans2 = -1;
    s1 = string(buf1);
    s1 = string(s1.rbegin(), s1.rend());
    s2 = string(buf2);
    s2 = string(s2.rbegin(), s2.rend());
    curs1 = string(s1.size(), '0');
    solve(0, 1);
    string ans1s, ans2s;
    stringstream ss1, ss2;
    ss1 << setfill('0') << setw(s1.size()) << ans1;
    ss2 << setfill('0') << setw(s1.size()) << ans2;

    printf("Case #%d: %s %s\n", t, ss1.str().c_str(), ss2.str().c_str());
  }
}
