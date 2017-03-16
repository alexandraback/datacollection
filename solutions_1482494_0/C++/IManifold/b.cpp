#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int INF = 1000000000;
const int MAX = 1010;
int req[MAX][2], n, tt;

const int MAX_S = 20;
int memo[MAX_S][1<<MAX_S];

inline int isset(int a, int b, int c) {
  return (a & (1<<(2 * b + c)));
}

inline int doset(int a, int b, int c) {
  return (a | (1<<(2 * b + c)));
}

int solve(int stars, int solved) {
  //printf("enter %d %d\n", stars, solved);
  if (stars == 2 * n) {
    return 0;
  }
  if (memo[stars][solved] < 0) {
    int min = INF;
    for (int i = 0; i < n; i++) {
      if (!isset(solved, i, 1) && req[i][1] <= stars) {
        int newstars = stars + 1;
        if (!isset(solved, i, 0)) newstars++;
        int sol = 1 + solve(newstars, doset(solved, i, 1));
        if (sol < min) min = sol;
      } else if (!isset(solved, i, 1) && !isset(solved, i, 0) && req[i][0] <= stars) {
        int sol = 1 + solve(stars + 1, doset(solved, i, 0));
        if (sol < min) min = sol;
      }
    }
    memo[stars][solved] = min;
    //printf("min %d %d = %d\n", stars, solved, min);
  }
  //printf("exit %d %d = %d\n", stars, solved, memo[stars][solved]);
  return memo[stars][solved];
}

int main () {
  scanf("%d", &tt);
  for (int t = 1; t <= tt; t++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &req[i][0], &req[i][1]);
    }
    for (int i = 0; i < 2*n; i++) {
      for (int j = 0; j < (1<<(2*n)); j++) {
        memo[i][j] = -1;
        //printf("%d, %d\n", i, j);
      }
    }
    printf("Case #%d: ", t);
    int sol = solve(0, 0);
    if (sol >= INF) printf("Too Bad\n");
    else printf("%d\n", sol);
  }

  return 0;
}
