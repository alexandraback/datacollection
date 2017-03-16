
#include <cstdio>
#include <cstring>

int counting(int x, int h) {

  int store[10];
  int s_len = 0;

  int R = 0;

  int digits[10];
  int n = 0;
  for (int t = x; t>0; t/=10) {
    digits[n++] = t%10;
  }

  for (int i = n-2; i >= 0; i--) {
    int y = 0;
    for (int j = i; j >= 0; j--) {
      y = y*10 + digits[j];
    }
    for (int j = n-1; j > i; j--) {
      y = y*10 + digits[j];
    }

    if (y > x && y <= h) {

      int s = 0;
      for (; s < s_len; s++) {
        if (store[s] == y) break;
      }
      if (s >= s_len) {

        R++; 
        store[s_len++] = y;
      }
    }

  }

  return R;
}

int main(int argc, char** argv) {

  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    printf("Case #%d: ", t);

    int l, h;
    scanf("%d%d",&l, &h);

    int R = 0;
    for (int x = l; x <= h; x++) {
      R += counting(x, h);
    }

    printf("%d\n", R);
  }

  return 0;
}
