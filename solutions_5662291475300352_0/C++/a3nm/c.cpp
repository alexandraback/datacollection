#include <stdio.h>
#include <vector>
#include <queue>

#define MAXN 1000002

using namespace std;

typedef pair<int, int> pii;

double pos[2], time[2];
int nhike;

int ans() {
  //printf("%lf %lf and %lf %lf, nhike %d\n", pos[0], time[0], pos[1], time[1], nhike);
  if (nhike <= 1)
    return 0;
  if (time[0] == time[1])
    return 0;
  if (time[0] > time[1]) {
    // swap
    int tmp;
    tmp = time[0];
    time[0] = time[1];
    time[1] = tmp;
    tmp = pos[0];
    pos[0] = pos[1];
    pos[1] = tmp;
  }
  //printf("%lf %lf and %lf %lf\n", pos[0], time[0], pos[1], time[1]);
  // now 0 is fastest
  if (pos[0] < pos[1]) {
    // fastest first
    double time_of_slow = (360.0 - pos[1]) * time[1] / 360.0;
    double speed0 = 360./time[0];
    double speed1 = 360./time[1];
    double time_before_cross = 1.0 * (pos[1] - pos[0]) / (speed0 - speed1);
    if (time_of_slow < time_before_cross)
      return 0; // stay just before fast
    // else, they coincide
    pos[0] += 360. * time_before_cross / time[0];
    pos[1] = pos[0];
  }
  // slowest 1 is first
  // does fast catch slow again before its lap?
  double time_of_slow = (360.0 - pos[1]) * time[1] / 360.0;
  double speed0 = 360./time[0];
  double speed1 = 360./time[1];
  double time_before_cross = 1.0 * (360. + (pos[1] - pos[0])) / (speed0 - speed1);
  //printf("time slow: %lf time crosS: %lf\n", time_of_slow, time_before_cross);
  if (time_of_slow < time_before_cross) {
    return 0; // stay just before slow
  }
  return 1; // no choice!
}

int main() {
  int T;
  scanf("%d", &T);
  for (int ncase = 0; ncase < T; ncase++) {
    int N;
    scanf("%d", &N);
    nhike = 0;
    for (int i = 0; i < N; i++) {
      int D, H, M;
      scanf("%d%d%d", &D, &H, &M);
      for (int j = 0; j < H; j++) {
        if (nhike == 2)
          break;
        pos[nhike] = D;
        time[nhike] = M + j;
        //printf("nhike now %d read pos %f time %f and %d for ncase %d j %d\n", nhike, pos[nhike], time[nhike], M,  ncase, j);
        nhike++;
        //printf("nhike now %d for ncase %d\n", nhike, ncase);
      }
    }
    printf("Case #%d: %d\n", ncase + 1, ans());
  }
  return 0;
}
