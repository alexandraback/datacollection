#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define sz(a) ((int)(a.size()))

string C, J;

char aux[2903];
void print(int nd, int num) {
  sprintf(aux, "%%0%dd", nd);
  printf(aux, num);
}

int mnc;
int mnj;

void test(int c, int j) {
  if (mnc == -1 ||
      (abs(mnc - mnj) > abs(c - j) ||
       (abs(mnc - mnj) == abs(c - j) && (c < mnc || (c == mnc && j < mnj))))) {
    mnc = c;
    mnj = j;
  }
}

int func(int num, int pos, string &s, int digit) {
  for (; pos < sz(s); ++pos) {
    num *= 10;
    if (s[pos] == '?') {
      num += digit;
    } else {
      num += s[pos] - '0';
    }
  }
  return num;
}

void dfs(int pos, int c, int j) {
  if (pos == sz(C)) {
    test(c, j);
  } else {
    if (C[pos] == '?' && J[pos] == '?') {
      // all 0
      dfs(pos + 1, c * 10, j * 10);
      // C =  1 , J = 1
      test(func(c * 10 + 1, pos + 1, C, 0),
           func(j*10 + 0, pos + 1, J, 9));
      // C = 0 , J = 1
      test(func(c * 10 + 0, pos + 1, C, 9),
           func(j*10 + 1, pos + 1, J, 0));
    } else if (C[pos] != '?' && J[pos] == '?') {
      // equal
      dfs(pos + 1, c * 10 + C[pos] - '0', j * 10 + C[pos] - '0');
      // greater
      if (C[pos] - '0' + 1 <= 9) {
        test(func(c * 10 + C[pos] - '0', pos + 1, C, 9),
             func(j * 10 + C[pos] - '0' + 1, pos + 1, J, 0));
      }
      // lesser
      if (C[pos] - '0' - 1 >= 0) {
        test(func(c * 10 + C[pos] - '0', pos + 1, C, 0),
             func(j * 10 + C[pos] - '0' - 1, pos + 1, J, 9));
      }
    } else if (C[pos] == '?' && J[pos] != '?') {
      // equal
      dfs(pos + 1, c * 10 + J[pos] - '0', j * 10 + J[pos] - '0');
      // bigger
      if (J[pos] - '0' + 1 <= 9) {
        test(func(c * 10 + J[pos] - '0' + 1, pos + 1, C, 0),
             func(j * 10 + J[pos] - '0', pos + 1, J, 9));
      }
      // lesser
      if (J[pos] - '0' - 1 >= 0) {
        test(func(c * 10 + J[pos] - '0' - 1, pos + 1, C, 9),
             func(j * 10 + J[pos] - '0' , pos + 1, J, 0));
      }
    } else {
      if (C[pos] == J[pos]) {
        dfs(pos + 1, c * 10 + C[pos] - '0', j * 10 + J[pos] - '0');
      } else if(C[pos] > J[pos]) {
        test(func(c, pos, C, 0), func(j, pos, J, 9));
      } else {
        test(func(c, pos, C, 9), func(j, pos, J, 0));
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int cn = 1; cn <= t; cn++) {
    cin >> C >> J;
    mnc = -1;
    dfs(0, 0, 0);
    printf("Case #%d: ", cn);
    print(sz(C), mnc);
    printf(" ");
    print(sz(J), mnj);
    printf("\n");
  }
  return 0;
}
