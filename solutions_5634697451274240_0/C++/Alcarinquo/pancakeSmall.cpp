#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool S[100];

int main() {
  int T, i;
  char line[101];
  int N;

  scanf("%d", &T);

  for(int caso = 1; caso <= T; caso++) {
    scanf("%s", line);
    for(i = 0; line[i] != '\0'; i++) {
      if(line[i] == '+')
        S[i] = true;
      else
        S[i] = false;
    }

    N = i;
    int k = 0;

    i--;
    while(i >= 0) {
      if(S[i]) {
        i--;
      } else {
        if(S[0]) {
          k++;
          int l = i-1;
          while(!S[l]) l--;

          for(int j = 0; j <= l/2; j++) {
            bool aux = S[j];
            S[j] = !S[l-j];
            S[l-j] = !aux;
          }
/*
          for(int m = 0; m < N; m++) {
            if(S[m]) putchar('+');
            else putchar('-');
          }
          putchar('\n');*/
        }

        k++;
        for(int j = 0; j <= i/2; j++) {
          bool aux = S[j];
          S[j] = !S[i-j];
          S[i-j] = !aux;
        }
/*
        for(int m = 0; m < N; m++) {
          if(S[m]) putchar('+');
          else putchar('-');
        }
        putchar('\n');*/
      }
    }

    printf("Case #%d: %d\n", caso, k);
  }

  return 0;
}
