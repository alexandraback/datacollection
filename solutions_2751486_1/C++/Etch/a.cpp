#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int T;
char l[1010101];
int n;

bool isCons(char c) {
  return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

long long solve() {
    int s = strlen(l);
    long long ans = 0;
    int start = 0, lastStart = -1;
    int consCnt = 0;
    for (int i = 0; i < s; i++) {
      if (isCons(l[i]))
          consCnt++;
      else
          consCnt = 0;

      if (consCnt >= n) {
        start = i - n + 1;
        ans += (long long)(start - lastStart) * (long long)(s - i);
        lastStart = start;
      }
    }
    return ans;
}

int main() {
  scanf("%d\n", &T);
  int k = 0;
  while (T--) {
    scanf("%s %d", l, &n);
    printf("Case #%d: ", ++k);
    cout << solve() << endl;
  }
}
