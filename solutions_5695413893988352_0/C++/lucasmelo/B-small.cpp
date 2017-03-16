#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define sz(a) ((int)(a.size()))

string C, J;

bool consistent(string &s, int num) {
  int n = sz(s);
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] != '?' && s[i] - '0' != (num % 10)) {
      return false;
    }
    num /= 10;
  }
  return true;
}

char aux[2903];
void print(int nd, int num) {
  sprintf(aux, "%%0%dd", nd);
  printf(aux, num);
}

int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int cn = 1; cn <= t; cn++) {
    cin >> C >> J;
    int mnc, mnj;
    mnc = -1;

    for (int i = 0; i < (int)pow(10, sz(C)); ++i) {
      if (!consistent(C, i)) continue;
      for (int j = 0; j < (int)pow(10, sz(C)); ++j) {
        if (!consistent(J, j)) continue;

        if (mnc == -1 || (abs(mnc - mnj) > abs(i - j) ||
                          (abs(mnc - mnj) == abs(i - j) &&
                           (i < mnc || (i == mnc && j < mnj))))) {
          mnc = i;
          mnj = j;
        }
      }
    }

    printf("Case #%d: ", cn);
    print(sz(C), mnc);
    printf(" ");
    print(sz(J), mnj);
    printf("\n");
  }
  return 0;
}
