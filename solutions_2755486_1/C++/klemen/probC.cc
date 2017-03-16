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

int endpointsCount = 0;
int endpoints[4 * MAXM];

int segCount = 0;
int segStart[8 * MAXM];
int segLen[8 * MAXM];

void makeSegments() {
  segCount = 0;
  sort(endpoints, endpoints + endpointsCount);
  int prev = endpoints[0];
  for (int i = 0; i < endpointsCount; i++) {
    if (prev != endpoints[i]) {
      segStart[segCount] = prev;
      segLen[segCount] = endpoints[i] - prev;
      segCount++;
      prev = endpoints[i];
    }
  }
}

int treeDepth = 0;
int treeActive[16 * MAXM];
int levelSize[29];
int levelStart[29];
int levelNode[29];

void buildTree() {
  for (int i = 0, cp = 1; i < 29; i++, cp *= 2) {
    levelSize[i] = cp;
    levelStart[i] = cp - 1;
  }
  for (treeDepth = 3; segCount > levelSize[treeDepth]; treeDepth++);
  for (int i = 0; i <= treeDepth; i++) {
    levelNode[i] = levelSize[treeDepth - i];
  }
  // initialize tree
  for (int l = 0; l <= treeDepth; l++) {
    for (int j = 0; j < levelSize[l]; j++) {
      treeActive[levelStart[l] + j] = 0;
    }
  }
}

bool treeTest(int level, int pos, int ql, int qr, int height, int carry) {
  int l = pos * levelNode[level], r = l + levelNode[level] - 1;
  if (qr >= l && ql <= r) {  // request intersects this segment
    int cur = max(treeActive[levelStart[level] + pos], carry);
    if (ql <= l && qr >= r) {  // request covers this segment
      return cur < height;
    }
    return treeTest(level + 1, 2 * pos, ql, qr, height, cur) ||
           treeTest(level + 1, 2 * pos + 1, ql, qr, height, cur);
  }
  return false;
}

void treeAttack(int level, int pos, int ql, int qr, int height) {
  int l = pos * levelNode[level], r = l + levelNode[level] - 1;
  if (qr >= l && ql <= r) {  // request intersects this segment
    if (ql <= l && qr >= r) {  // request covers this segment
      if (height > treeActive[levelStart[level] + pos])
        treeActive[levelStart[level] + pos] = height;
    }
    else {
      treeAttack(level + 1, 2 * pos, ql, qr, height);
      treeAttack(level + 1, 2 * pos + 1, ql, qr, height);
    }
    if (level < treeDepth) {
      int next = min(treeActive[levelStart[level + 1] + 2 * pos],
                     treeActive[levelStart[level + 1] + 2 * pos + 1]);
      if (next > treeActive[levelStart[level] + pos])
        treeActive[levelStart[level] + pos] = next;
    }
  }
}

void printTree() {
  for (int i = 0; i <= treeDepth; i++) {
    for (int j = 0; j < levelSize[i]; j++) {
      printf("%d ", treeActive[levelStart[i] + j]);
    }
    printf("\n");
  }
}

int main() {
  int T = 0;
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d", &N);
    events.clear();
    endpointsCount = 0;
    for (int i = 0; i < N; i++) {
      int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
      scanf("%d %d %d %d %d %d %d %d", &di, &ni, &wi, &ei, &si, &delta_di, &delta_pi, &delta_si);
      for (int j = 0; j < ni; j++) {
        Event current;
        current.time = di;
        current.height = si;
        current.startX = wi;
        current.endX = ei;

        endpoints[endpointsCount++] = wi;
        endpoints[endpointsCount++] = ei;

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
    makeSegments();

    // compress segments
    for (int i = 0; i < events.size(); i++) {
      events[i].startS = lower_bound(segStart, segStart + segCount, events[i].startX) - segStart;
      events[i].endS = (lower_bound(segStart, segStart + segCount, events[i].endX) - segStart) - 1;
    }

    buildTree();
    sort(events.begin(), events.end());
    int rv = 0;
    for (int i = 0; i < events.size(); i++) {
      if (events[i].type == 0) {
        if (treeTest(0, 0, events[i].startS, events[i].endS, events[i].height, 0)) {
          rv++;
        }
      }
      else {
        treeAttack(0, 0, events[i].startS, events[i].endS, events[i].height);
      }
    }
    printf("Case #%d: %d\n", t + 1, rv);
  }
}
