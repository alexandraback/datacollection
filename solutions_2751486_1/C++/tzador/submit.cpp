#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
char name[1000010];
bool vowel[1000010];
int cons[1000010];
int ending[1000010];
int solve(int n, int l) {
  for (int i = 0; i < l; i++) {
    char c = name[i];
    vowel[i] = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : 0;
  }
  cons[0] = 1 - vowel[0];
  for (int i = 1; i < l; i++) {
    if (!vowel[i])
      cons[i] = cons[i - 1] + 1;
    else
      cons[i] = 0;
  }
  for (int i = 0; i < n - 1; i++)
    ending[i] = 0;
  for (int i = n - 1; i < l; i++) {
    if (cons[i] >= n)
      ending[i] = i + 2 - n;
    else
      ending[i] = ending[i - 1];
  }
  int res = 0;
  for (int i = 0; i < l; i++)
    res += ending[i];
  return res;
}
int main() {
  int T;
  scanf("%d\n", &T);
  for (int t = 1; t <= T; t++) {
    int n;
    scanf("%s %d\n", name, &n);
    int l = strlen(name);
    printf("Case #%d: %d\n", t, solve(n, l));
  }
}
