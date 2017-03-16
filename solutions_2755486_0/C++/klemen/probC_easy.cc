#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAXM 1001000

using namespace std;

int N = 0;

class Event {
 public:
  int time;
  char type;  // 0 = test, 1 = attack
  int height;
  int startX, endX;
  int startS, endS;

  bool operator<(const Event& other) const {
    if (time == other.time)
      return type < other.type;
    return time < other.time;
  }
};

vector<Event> events;

int wall[5000];

bool wallTest(int l, int r, int h) {
  l += 1000;
  r += 1000;
  for (int i = l; i < r; i++) {
    if (wall[i] < h)
      return true;
  }
  return false;
}


void wallAttack(int l, int r, int h) {
  l += 1000;
  r += 1000;
  for (int i = l; i < r; i++) {
    if (h > wall[i])
      wall[i] = h;
  }
}

int main() {
  int T = 0;
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d", &N);
    events.clear();
    for (int i = 0; i < 5000; i++) {
      wall[i] = 0;
    }
    for (int i = 0; i < N; i++) {
      int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
      scanf("%d %d %d %d %d %d %d %d", &di, &ni, &wi, &ei, &si, &delta_di, &delta_pi, &delta_si);
      for (int j = 0; j < ni; j++) {
        Event current;
        current.time = di;
        current.height = si;
        current.startX = wi;
        current.endX = ei;

        current.type = 0;
        events.push_back(current);
        current.type = 1;
        events.push_back(current);

        di += delta_di;
        wi += delta_pi;
        ei += delta_pi;
        si += delta_si;
      }
    }

    sort(events.begin(), events.end());
    int rv = 0;
    for (int i = 0; i < events.size(); i++) {
      if (events[i].type == 0) {
        //printf("%d - %d %d | %d %d - %d\n", events[i].time, events[i].startX, events[i].endX,
        //                                    events[i].startS, events[i].endS, events[i].height);
        if (wallTest(events[i].startX, events[i].endX, events[i].height)) {
          rv++;
          //printf("HIT!\n");
        }
      }
      else {
        wallAttack(events[i].startX, events[i].endX, events[i].height);
        //printf("## %d\n", events[i].time);
        //printTree();
        //printf("---\n");
      }
    }
    printf("Case #%d: %d\n", t + 1, rv);
  }
}
