#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int LEN = 15;
char num[LEN], rot[LEN];

const int MAX = 2000000;
vector<int> pairs[MAX+1];

void precompute() {
  for (int n = 1; n <= MAX; n++) {
    sprintf(num, "%d", n);
    int len = strlen(num);
    for (int i = 1; i < len; i++) {
      for (int j = 0; j < len; j++) {
         rot[j] = num[(j+i)%len];
      }
      int m = atoi(rot);
      if (m > n && m <= MAX) {
        pairs[n].push_back(m);
      }
    }
    sort(pairs[n].begin(), pairs[n].end());
    pairs[n].erase(unique(pairs[n].begin(), pairs[n].end()), pairs[n].end());
  }
}

int recpairs(int n, int b) {
  // n >= a
  int count = 0;
  for (int i = 0; i < pairs[n].size(); i++) {
    if (pairs[n][i] <= b) count++;
    else break;
  }
  return count;
}

int main() {
  int tt;
  scanf("%d", &tt);
  precompute();
  for (int t = 1; t <= tt; t++) {
    int a, b;
    scanf("%d %d", &a, &b);
    int pairs = 0;
    for (int n = a; n < b; n++) {
      pairs += recpairs(n, b);
    }
    printf("Case #%d: %d\n", t, pairs);
  }

  return 0;
}
