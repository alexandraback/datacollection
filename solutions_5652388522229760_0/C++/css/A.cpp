#include <cstdio>
using namespace std;

int T, n, a;
bool ext[10];

int ans() {
  a = 0;
  for (bool st = true; st;) {
    a += n;
    st = false;

    for (int k = a; k; k /= 10)
      ext[k % 10] = true;

    for (int i = 0; i < 10; i++)
      if (!ext[i]) st = true;
  }
  return a;
}

int main()
{
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("output.out", "w", stdout);

  scanf("%d", &T);
  for (int cou = 1; cou <= T; cou++) {
    scanf("%d", &n);
    printf("Case #%d: ", cou);

    for (int i = 0; i < 10; i++) ext[i] = false;

    if (n > 0) {
      printf("%d\n", ans());
    } else {
      printf("INSOMNIA\n");
    }
  }

  fclose(stdin);
  fclose(stdout);
}
