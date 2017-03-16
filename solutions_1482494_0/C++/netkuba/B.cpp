#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int caseCount = 0;
void make() {
  int n; scanf(" %d", &n);
  pair<int, int> * level = new pair<int, int>[n];
  for (int i=0; i<n; ++i) {
    scanf(" %d %d", &level[i].first, &level[i].second);
  }
  int * solved = new int[n];
  memset(solved, 0, sizeof(int) * n);
  int curr = 0, solvedCount = 0, result = 0;

  bool jmp;
  while (solvedCount < n) {
    jmp = false;
    for (int i=0; i<n; ++i) {
      if ((solved[i] < 2) && (curr >= level[i].second)) {
        curr += 2 - solved[i];
        solved[i] = 2;
        ++result;
        ++solvedCount;
        jmp = true;
        break;
      }
    }
    if (jmp) continue;

    int best = -1;
    for (int i=0; i<n; ++i) {
      if ((solved[i] < 1) && (curr >= level[i].first)) {
        if (best == -1) best = i;
        if (level[i].second > level[best].second) {
          best = i;
        }
      }
    }
    if (best != -1) {
      ++curr;
      solved[best] = 1;
      ++result;
      continue;
    }
    
    break;
  }

  delete[] level;

  if (solvedCount ==  n) {
    printf("Case #%d: %d\n", ++caseCount, result);
  } else {
    printf("Case #%d: Too Bad\n", ++caseCount);
  }
}

int main() {
  int t; scanf(" %d", &t);
  while(t--) {
    make();
  }
  return 0;
}
