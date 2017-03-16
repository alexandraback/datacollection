#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void count_dig(long long int N, int dig[]) {
  int d = N%10;

  do {
    dig[d] = 1;
    N = N/10;
    d = N%10;
  } while(N != 0);
}

bool complete(int dig[]) {
  for(int i = 0; i < 10; i++)
    if(dig[i] == 0) return false;

  return true;
}

int main() {
  int T;
  int N;

  scanf("%d", &T);

  for(int caso = 1; caso <= T; caso++) {
    scanf("%d", &N);
    if(N == 0) printf("Case #%d: INSOMNIA\n", caso);
    else {
      long long int i;
      int dig[] = {0,0,0,0,0,0,0,0,0,0};

      for(i = 1; true; i++) {
        count_dig(N*i, dig);
        if(complete(dig))
          break;
      }

      printf("Case #%d: %lld\n", caso, N*i);

    }
  }

  return 0;
}
