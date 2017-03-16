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

int denomin[35];
int y;

int possible(int val) {
  if(val == 0) return 1;

  for(int j = val-1; j >= 1; j--) {
    if(denomin[j] == 1 && ((val-j == j && possible(val-j) == 1) || (val-j < j &&(denomin[val-j] == 1 || possible(val-j))))) return 1;
  }
  return 0;
}

void print(int v) {
  if(denomin[v] == 1) fprintf(stderr, "%d\n", v);
  else {
    for(int i = v-1; i >= 1; i--) {
      if(denomin[i] == 1 && v-i < i && possible(v-i) == 1) {
        fprintf(stderr, "%d + ", i);
        print(v-i);
        return;
      }
    }
  }
}



int main() {
  int T;
  int C, D, V;
  int aux;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {
    scanf("%d %d %d", &C, &D, &V);
    for(int i = 1; i <= V; i++) {
      denomin[i] = 0;
    }

    fprintf(stderr, "\n---------\nV = %d\n", V);
    fprintf(stderr, "MOEDAS ORIGINAIS:\n");
    for(int i = 0; i < D; i++) {
      scanf("%d", &aux);
      fprintf(stderr, "%d ", aux);
      denomin[aux] = 1;
    }
    fprintf(stderr, "\n");

    y = 0;
    int j;
    for(int i = 1; i <= V; i++) {
      if(denomin[i] == 0) {
        for(j = i-1; j >= 1; j--) {
          if(denomin[j] == 1){
            if(i-j < j && (denomin[i-j] == 1 || possible(i-j) == 1))
              break;
            if(i-j == j && possible(i-j) == 1)
              break;
          }
        }
        if(j == 0) {
          denomin[i] = 1;
          y++;
        }
      }
    }

    fprintf(stderr, "MOEDAS:\n");
    for(int i = 1; i <= V; i++) {
      if(denomin[i] == 1) fprintf(stderr, "%d ", i);
    }
    fprintf(stderr, "\n");
    for(int i = 1; i <= V; i++) {
      fprintf(stderr, "%d = ", i);
      print(i);
    }

    printf("Case #%d: %d\n", caso, y);
  }

  return 0;
}
