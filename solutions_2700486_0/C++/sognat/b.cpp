#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long LL;

double result;
int N, X, Y;
int d;
LL binom[1011][1011];

void init() {
  binom[0][0] = 1;
  for (int i = 0; i <= 1010; i++) {
    binom[i][0] = 1;
    binom[i][i] = 1;
    for (int j = 1; j < i; j++) {
      binom[i][j] = binom[i-1][j-1]+binom[i-1][j];
    }
  }
}

int get_w(int N) {
  int w = 1;
  int size = 1;
  while (size <= N) {
    size += w+w+3;
    w += 2;
  }
  return w-2;
}

inline int ab(int a) { return max(a, -a); }

int pyramid(int x, int y, int w) {
  if (d <= w) { return 1; }
  else if (d == w+1) { return 0; }
  else { return -1; }
}

int main() {
  init();

  int T;
  scanf("%d", &T);

  for (int Z = 1; Z <= T; Z++) {
    scanf("%d%d%d", &N, &X, &Y);

    d = ab(X) + ab(Y);
    long long w = get_w(N);
    long long size = w*(w+1)/2;
    int status = pyramid(X, Y, w);
    int tries = N-size;


    result = 0;
    if (status == 1) {
      result = 1;
    } else if (status == -1) {
      result = 0;
    } else if (ab(Y)+1 < w+2) {
      //printf("tries: %d, w: %d, h: %d\n", tries, w, ab(Y)+1);
      result = 0;
      for (int h = ab(Y)+1; h <= tries; h++) {
        //printf("dodaje %lld\n", binom[tries][h]);
        result += binom[tries][h];
      }
      result /= double(1<<tries);


      if (Y+1 <= (tries - w) - 1) {
        result = 1;
      }
    }

    printf("Case #%d: %lf\n", Z, result);
  }

  return 0;
}
