#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <vector>

using namespace std;

#define MAX 64
long long num, d[MAX], b[MAX];

#define LEN 100100100
char crivo[LEN];
vector<long long> p;

void next(void) {
  int ok = 0;
  while(!ok) {
    num++;
    if (num%2 == 0) continue;

    ok = 1;
    for(int i = 2; i <= 10 && ok; i++) {
      long long temp = num;
      long long base = 1;
      b[i] = 0;
      while(temp > 0) {
        if (temp%2) b[i] += base;
        base *= (long long)i;
        temp = temp >> 1;
      }

      int primo = 0;
      primo = 1;
      for(int j = 0; j < (int)p.size() && p[j]*p[j] <= b[i] && primo; j++) {
        if (b[i]%p[j] == 0) {
          primo = 0;
          d[i] = p[j];
        }
      }

      if (primo) ok = 0;
    }
  }
  //for(int i = 2; i <= 10; i++) printf("[%lld %lld]", b[i], d[i]);
}

int main() {
  int T;

  memset(crivo, 1, sizeof(crivo));
  for(int i = 4; i < LEN; i += 2) {
    crivo[i] = 0;
  }
  p.push_back(2);
  for(int i = 3; i < LEN; i += 2) {
    if (crivo[i]) {
      p.push_back(i);
      for(int j = 2*i; j < LEN; j += i) {
        crivo[j] = 0;
      }
    }
  }

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {
    int N,J;

    scanf("%d %d", &N, &J);
    num = (1LL<<(N-1));

    printf("Case #%d:\n", caso);
    for(int i = 0; i < J; i++) {
      next();
      long long t = num;
      string s = "";
      for(int j = 0; j < N; j++) {
        s += (t%2) ? "1" : "0";
        t = t >> 1;
      }
      reverse(s.begin(), s.end());
      printf("%s", s.c_str());
      for(int j = 2; j <= 10; j++) {
        printf(" %lld", d[j]);
      }
      printf("\n");
    }
  }
  return 0;
}

