#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int maxi;

int occurrences(char str[], int str_len, char substr[], int substr_len) {
  int res = 0;
  int i, j;
  for(i = 0; i < str_len; i++) {
    for(j = 0; j < substr_len && i+j < str_len; j++) {
      if(str[i+j] != substr[j]) break;
    }
    if(j == substr_len) res++;
  }
  return res;
}

int rec(char macaco[], int i, char keyboard[], int K, char word[], int L, int S) {
  int aux;
  if(i == S) {
    macaco[i] = '\0';
    aux = occurrences(macaco, i, word, L);
    if(maxi < aux) maxi = aux;
    return aux;
  }

  int res = 0;
  for(int j = 0; j < K; j++) {
    macaco[i] = keyboard[j];
    res += rec(macaco, i+1, keyboard, K, word, L, S);
  }
  return res;
}

int main() {
  int T;
  int K, L, S;
  char keyboard[10], word[10];
  char macaco[10];

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {
    scanf("%d %d %d", &K, &L, &S);
    scanf("%s %s", keyboard, word);

    int i, j;
    for(i = 0; i < L; i++) {
      for(j = 0; j < K; j++) {
        if(keyboard[j] == word[i]) break;
      }
      if(j == K) break;
    }

    if(i != L) printf("Case #%d: 0.0\n", caso);
    else {
      maxi = 0;
      int num = rec(macaco, 0, keyboard, K, word, L, S);

      printf("Case #%d: %f\n", caso, maxi - num/pow(K, S));
    }
  }

  return 0;
}
