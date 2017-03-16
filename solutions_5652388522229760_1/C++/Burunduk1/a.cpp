#include <cstdio>
#include <algorithm>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  if (!n) {
    puts("INSOMNIA");
    return;
  }
  long long i = 0;
  int *used = new int[10]();
  do {       
    i += n;
    for (int x = i; x > 0; x /= 10)
      used[x % 10] = 1;
  } while (count(used, used + 10, 1) != 10);
  printf("%lld\n", i);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
