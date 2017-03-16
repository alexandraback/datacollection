#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Event {
  
  double time;
  int c1, c2, type;

  Event() {}
  Event(double ttime, int cc1, int cc2, int ttype) {
    time = ttime;
    c1 = cc1;
    c2 = cc2;
    type = ttype; // 0 - dojezdza, 1 - odjezdza
  }
};

bool operator<(Event a, Event b) {
  return a.time < b.time;
}

struct Car {
  char side;
  int speed, position; 
};

Car * car;
vector<Event> event;
set<int> state;

double eps = 0.00000001;

int change(int j, int s) {
  return (s xor (1<<j));
}

void duplicate(int j) {
  int i = 0, n = state.size();
  int * save = new int[n];
  for (set<int>::iterator it = state.begin(); it != state.end(); ++it) {
    save[i++] = *it;
  }
  for (i=0; i<n; ++i) {
    state.insert(change(j, save[i])); 
  }
  return;
}

void synchronize(int p, int q) {
  int i = 0, n = state.size();
  int * save = new int[n];
  for (set<int>::iterator it = state.begin(); it != state.end(); ++it) {
    save[i++] = *it;
  }
  state.clear();
  for (i=0; i<n; ++i) {
    if (((save[i] & (1<<p)) && !(save[i] & (1<<q))) || 
        (!(save[i] & (1<<p)) && (save[i] & (1<<q)))) {
      state.insert(save[i]);
    }
  }
  return;
}

int caseCount = 0;
void make() {
  state.clear();
  while(event.size()) event.pop_back();
  int n; scanf(" %d", &n);
  car = new Car[n];
  for (int i=0; i<n; ++i) {
    scanf(" %c %d %d", &car[i].side, &car[i].speed, &car[i].position);
  }
  
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      if (car[i].speed < car[j].speed) {
        double t1 = ((double)car[i].position - car[j].position - 5) / (car[j].speed - car[i].speed);
        double t2 = ((double)car[i].position - car[j].position + 5) / (car[j].speed - car[i].speed);
        if (t1 + eps > 0) {
          event.push_back(Event(t1 + eps, i, j, 0)); 
        }
        if (t2 - eps > 0) {
          event.push_back(Event(t2 - eps, i, j, 0));
        }
      }
    }
  }
  sort(event.begin(), event.end());

  int * intersect = new int[n];
  memset(intersect, 0, sizeof(int) * n);
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      if (i != j) {
        if (abs(car[i].position - car[j].position) < 5) {
          ++intersect[i];
        }
      }
    }
  }

  int beginState = 0;
  for (int i=0; i<n; ++i) {
    if (car[i].side == 'R') {
      beginState |= 1<<i;
    }
  }
  state.insert(beginState);

  for (int i=0; i<n; ++i) {
    if (intersect[i] == 0) {
      duplicate(i);
    }
  }

  for (int i=0; i<event.size(); ++i) {
    if (event[i].type) {
      if (--intersect[event[i].c1]) {
        duplicate(event[i].c1);
      }
      if (--intersect[event[i].c2]) {
        duplicate(event[i].c2);
      }
    } else {
      ++intersect[event[i].c1];
      ++intersect[event[i].c2];
      synchronize(event[i].c1, event[i].c2);  
    }
    if (state.size() == 0) {
      printf("Case #%d: %lf\n", ++caseCount, event[i].time);
      delete[] car;
      return;
    }
  }
  printf("Case #%d: Possible\n", ++caseCount);
  delete[] car;
  return;
}

int main() {
  int t; scanf(" %d", &t);
  while(t--) {
    make();
  }
  return 0;
}
