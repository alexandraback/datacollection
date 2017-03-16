#include <cstdio>
#include <cstring>

int main() {
  int T;
  scanf("%d", &T);
  for (int x = 1; x <= T; ++x) {
    printf("Case #%d: ", x);
    char S[101];
    scanf("%s", S);
    int len = strlen(S);
    int cnt = 0;
    while (true) {
      int c = 0;
      for (int i = 0; i < len; ++i) {
        if (S[i] == '-') ++c;
      }
      if (c == 0) {
        printf("%d\n", cnt);
        break;
      }
      ++cnt;
      if (S[0] == '+') {
        for (int i = 0; S[i] == '+'; ++i) {
          S[i] = '-';
        }
      } else {
        int j = len - 1;
        while (S[j] == '+') --j;
        char T[101];
        for (int i = 0; i <= j; ++i) {
          if (S[i] == '+') T[j - i] = '-';
          else T[j - i] = '+';
        }
        for (int i = 0; i <= j; ++i) S[i] = T[i];
      }
    }
  }
}
