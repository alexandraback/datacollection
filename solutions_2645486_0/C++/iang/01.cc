#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN 10000

int Max, Gain, N;
int prio[MAXN];

int c(int level, int remaining) {
  if (level == N) return 0;
  if (remaining > Max) remaining = Max;

  int max = 0;
  for (int i=remaining; i>=0; i--) {
    int spend = i;
    int gain = spend * prio[level];
    int next = c(level+1, remaining - spend + Gain);
    if (gain + next > max) max = gain + next;
  }

  return max;
}

void go(int tc) {
  cin >> Max >> Gain >> N;
  for (int i=0; i<N; i++) {
    cin >> prio[i];
  }

  int max = c(0, Max);
  printf("Case #%d: %d\n", tc, max);
}

int main() {
  int tc;
  cin >> tc;
  for (int i=0; i<tc; i++)
    go(i+1);
}

// vim: ts=2 sts=2

