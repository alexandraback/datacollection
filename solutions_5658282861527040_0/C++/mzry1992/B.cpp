#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);
  int totCas;
  scanf("%d", &totCas);
  for (int cas = 1; cas <= totCas; cas++) {
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    int ans = 0;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if ((i & j) < k) {
          ans++;
        }
      }
    }
    printf("Case #%d: %d\n", cas, ans);
  }
	return 0;
}

