#include <bits/stdc++.h>
using namespace std;
char s[2024];
int f[100];
int a[20];
char words[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
void remove(int x, int freq) {
  a[x] = freq;
  for (int i = 0; words[x][i]; i++) {
    f[words[x][i]] -= freq;
  }
}
void solve() {
  memset(f, 0, sizeof f);
  memset(a, 0, sizeof a);
  scanf("%s", s);
  for (int i = 0; s[i]; i++) {
    f[s[i]]++;
  }
  remove(0, f['Z']);
  remove(2, f['W']);
  remove(4, f['U']);
  remove(6, f['X']);
  remove(8, f['G']);
  remove(1, f['O']);
  remove(3, f['R']);
  remove(5, f['F']);
  remove(7, f['V']);
  remove(9, f['I']);
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j < a[i]; j++) {
      printf("%d", i);
    }
  }
  for (char c = 'A'; c <= 'Z'; c++) {
    assert(f[c] == 0);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    solve();
    printf("\n");
  }
  return 0;
}
