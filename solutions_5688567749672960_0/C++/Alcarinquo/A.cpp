#include <iostream>
#include <cstdio>

using namespace std;

long long int rev(long long int a) {
  long long int res = 0;
  while(a != 0) {
    res = res*10+a%10;
    a = a/10;
  }
  return res;
}

int main() {
  int T;
  long long int N, res, num, aux, alc, res2, cont;
  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {
    scanf("%lld", &N);

    alc = N;
    if(N%10 == 0) alc = N-1;

    res = 1;
    num = 1;
    while(num < alc) {
      aux = rev(num);

      if(aux <= alc && aux > num) {
        num = aux;
      } else {
        num = num+1;
      }
      res++;
    }
    res += N-alc;

    cont = alc;
    while(cont > 0 && cont > N-1000) {
      if(cont%10 == 0) {
        cont--;
        continue;
      }
      alc = rev(cont);
      num = 1;
      res2 = 1;
      while(num < alc) {
        aux = rev(num);

        if(aux <= alc && aux > num) {
          num = aux;
        } else {
          num = num+1;
        }
        res2++;
      }
      res2 += 1+N-cont;
      if(res2 < res) res = res2;
      cont = cont-1;
    }

    printf("Case #%d: %lld\n", caso, res);
  }
  return 0;
}
