#include <bits/stdc++.h>
using namespace std;

const int N = 2050;
char s1[N], s2[N];
int t, a, b;

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt<=t; tt++) {
    printf("Case #%d: ", tt);
    a = b = N/2;
    s1[a] = '\0';
    scanf("%s", s2);
    int n = strlen(s2);
    for (int i = 0; i<n; i++) {
      if (s2[i]>=s1[a]) s1[--a] = s2[i];
      else s1[b++]= s2[i];
    }
    for (int i = a; i<b; i++) {
      printf("%c", s1[i]);
    }
    printf("\n");
  }
}
