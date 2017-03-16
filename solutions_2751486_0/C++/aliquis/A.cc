#include <cstdio>

int main()
{
  int T;
  char buffer[1000010];
  scanf("%d", &T);
  for (int cases=1; cases<=T; ++cases) {
    long long n, c=0, t=0, l=0;
    scanf("%s%lld", buffer, &n);
    for (int i=0; buffer[i]; ++i) {
      switch (buffer[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        l=0;
        break;
      default:
        ++l;
      }
      if (l < n) {
        t += c;
      } else {
        c = i - n + 2;
        if (c < 0)
          c = 0;
        t += c;
      }
    }
    printf("Case #%d: %lld\n", cases, t);
  }
  return 0;
}
