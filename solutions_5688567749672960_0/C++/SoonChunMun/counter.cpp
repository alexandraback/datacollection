#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

int t, n;

int rev(int i) {
  int j = 0;
  while (i>0) { j = j*10 + i%10; i/=10; }
  return j;
}

int main() {
  scanf("%d", &t);
  deque<iii> q;
  int v;

  for (int ca=1; ca<=t; ca++) {
    scanf("%d", &n);
    q.clear();
    v = 0;

    map<int, int> seenfront;
    map<int, int> seenback;

    q.push_back(iii(ii(1,0),1));
    q.push_back(iii(ii(1,1),n));

    seenback[n] = 0;
    // side 0 is from 1
    // side 1 is from n

    while (!q.empty()) {

      iii p = q.front(); q.pop_front();
      ii pos = p.first;

      int step = pos.first;
      int side = pos.second;
      int num = p.second;

      if (side == 0) {
        if (seenfront.find(num) != seenfront.end()) continue;

        seenfront[num] = step;

        if (seenback.find(num) != seenback.end()) {
          v = step + seenback[num];
          break;
        }
        // printf("%d\n", num);

        q.push_back(iii(ii(step+1, side), num+1));
        q.push_back(iii(ii(step+1, side), rev(num)));

      } else {
        if (seenback.find(num) != seenback.end()) continue;
        seenback[num] = step;

        if (seenfront.find(num) != seenfront.end()) {
          v = step + seenfront[num];
          break;
        }

        q.push_back(iii(ii(step+1, side), num-1));
        q.push_back(iii(ii(step+1, side), rev(num)));
      }

    }

    printf("Case #%d: %d\n", ca, v);
  }
  return 0;

}
