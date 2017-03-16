#include <cstdio>

using namespace std;

int main() {
  int T, n;
  int checked[10], cnt, i, j;
  scanf("%d", &T);
  for (i = 0; i < T; i++) {
    scanf("%d", &n);
    if (n == 0) {
      printf("Case #%d: INSOMNIA\n", i + 1);
    } else {
      for (j = 0; j < 10; j++) checked[j] = 0;
      cnt = 0;
      for (j = 1; ; j++) {
	int num = j * n;
	while (num > 0) {
	  if (checked[num % 10] == 0) {
	    checked[num % 10] = 1;
	    cnt++;
	  }
	  num /= 10;
	}
	if (cnt == 10) {
	  printf("Case #%d: %d\n", i + 1, j * n);
	  break;
	}
      }
    }
  }
  return 0;
}
