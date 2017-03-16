#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct level
{
  int s1, s2;
  int id;
  bool operator<(const level l2) const{
    return s2 < l2.s2;
  }
};

bool cmp(level l1, level l2) {
  return l1.s1 < l2.s1;
}

int main(void) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    vector<level> levels(N);
    for (int i = 0; i < N; ++i) {
      cin >> levels[i].s1 >> levels[i].s2;
    }
    sort(levels.begin(), levels.end());
    for (int i = 0; i < N; ++i) levels[i].id = i;
    vector<level> levels2(levels);
    sort(levels2.begin(), levels2.end(), cmp);
    vector<bool> half(N);
    int ans = 0;
    int stars = 0;
    int i2 = 0;
    priority_queue<level> pq;
    for (int i = 0; i < N; ++i) {
      while (i2 < N && levels2[i2].s1 <= stars) {
        pq.push(levels2[i2]);
        i2++;
      }
      while (levels[i].s2 > stars) {
        if (pq.empty()) {
          ans = -1;
          break;
        }
        level top = pq.top();
        pq.pop();
        if (top.id < i) continue;
        half[top.id] = true;
        ans++;
        stars++;
        while (i2 < N && levels2[i2].s1 <= stars) {
          pq.push(levels2[i2]);
          i2++;
        }
        //printf("1 star on %d (%d)\n", levels[best].id, stars);
      }
      if (ans == -1) break;
      stars += half[i] ? 1 : 2;
      //printf("2 stars on %d (%d)\n", levels[i].id, stars);
    }
    printf("Case #%d: ", t);
    if (ans == -1) {
      printf("Too Bad\n");
    } else {
      printf("%d\n", ans + N);
    }
  }
  return 0;
}
