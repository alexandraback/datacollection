#include <cstdio>

long long chngbase(int i, long long b) {
  long long r = 0;
  for (long long c = 1; i; c *= b, i >>= 1) {
    if (i&1)
      r += c;
  }
  return r;
}

void printbin(int i) {
  char buf[20];
  char* pbuf = buf+sizeof(buf)-1;
  *pbuf = 0;
  for (; i; i >>= 1) {
    *--pbuf = i&1 ? '1' : '0';
  }
  printf("%s", pbuf);
}

long long divisor(long long i) {
  for (long long j = 2; j*j < i; ++j) {
    if ((i%j) == 0)
      return j;
  }
  return 0;
}

int main() {
  int T, N, J;
  scanf("%d %d %d", &T, &N, &J);
  printf("Case #1:\n");
  for (int s = (1<<(N-1))+1; s < (1<<N); s += 2) {
    long long divs[11];
    divs[2] = divisor(s);
    if (divs[2] == 0)
      continue;
    for (int i = 3; i <= 10; ++i) {
      divs[i] = divisor(chngbase(s, i));
      if (divs[i] == 0)
        break;
      if (i == 10) {
        printbin(s);
        for (int j = 2; j <= 10; ++j) {
          printf(" %lld", divs[j]);
        }
        printf("\n");
        if (--J == 0)
          return 0;
      }
    }
  }
}
