#include <cstdio>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;

const double eps = 0.001;

int gdc(int a, int b) {
  if (a==0) return b;
  return gdc(b%a, a);
}

struct event {
  double time;
  int type; // 0 - xSym, 1 - ySym, 2 - center

  event() {}
  event(double ti, int ty) {
    time = ti;
    type = ty;
  }
};

bool operator<(const event & a, const event & b) {
  return a.time < b.time;
}

int H, W;
int D;
bool t[64][64];
int xBeg, yBeg;
int x, y;
bool xSym, ySym;
vector<event> events;

bool getXSide() {
  if (xSym) {
    return t[x-1][y];
  } else {
    return t[x+1][y];
  }
}

bool getYSide() {
  if (ySym) {
    return t[x][y-1];
  } else {
    return t[x][y+1];
  }
}

bool getCorner() {
  if (xSym) {
    if (ySym) {
      return t[x-1][y-1];
    } else {
      return t[x-1][y+1];
    }
  } else {
    if (ySym) {
      return t[x+1][y-1];
    } else {
      return t[x+1][y+1];
    }
  }
}

void moveX() {
  if (xSym) {
    --x;
  } else {
    ++x;
  }
}

void moveY() {
  if (ySym) {
    --y;
  } else {
    ++y;
  }
}

int simulate() {
  for (int i=0; i<events.size();) {
    int type = events[i].type;
    if ((i+1 < events.size()) && (events[i+1].time - events[i].time < eps)) {
      //printf("nakładka: %d %d\n", events[i].type, events[i+1].type);
      type = 3;
    }
    //printf(" - %d : (%d, %d) -> (%d, %d)\n", type, x, y, ((int)xSym) * 2 - 1, ((int)ySym) * 2 - 1);
    //printf("    %d %d %d\n", getXSide(), getYSide(), getCorner());
    bool getX = getXSide(), getY = getYSide(), corner = getCorner();
    if (type == 0) {
      if (getX) {
        xSym = !xSym;
      } else {
        moveX();
      }
      ++i;
    } else if (type == 1) {
      if (getY) {
        ySym = !ySym;
      } else {
        moveY();
      }
      ++i;
    } else if (type == 2) {
      if ((x == xBeg) && (y == yBeg)){
        return 1;
      }
      ++i;
    } else if (type == 3) {
      if (corner && (!getX) && (!getY)) {
        return 0;
      }
      if (getX && corner) {
        xSym = !xSym;
      } else {
        moveX();
      }
      if (getY && corner) {
        ySym = !ySym;
      } else {
        moveY();
      }
      i += 2;
    }
  }
  return 0;
}

int caseCount = 0;
void make() {
  scanf(" %d %d %d", &H, &W, &D);
  for(int i=0; i<H; ++i) {
    for(int j=0; j<W; ++j) {
      char c;
      scanf(" %c", &c);
      switch (c) {
        case '#':
          t[i][j] = true;
          break;
        case 'X':
          xBeg = i;
          yBeg = j;
        case '.':
          t[i][j] = false;
          break;
      }
    }
  }

  int res = 0;
  for (int i=-51; i<=51; ++i) {
    for (int j=-51; j<=51; ++j) {
      if (i*i + j*j < D*D + eps) {
        int I = abs(i), J = abs(j);
        if (gdc(I, J) == 1) {
          x = xBeg;
          y = yBeg;
          if (i < 0) { xSym = true; }
          else { xSym = false; }
          if (j < 0) { ySym = true; }
          else { ySym = false; }

          int s = (int) sqrt(((double)D*D + 10 * eps) / (I*I + J*J));
          I *= s;
          J *= s;
          
          while (!events.empty()) { events.pop_back(); }
          for (int k=1; k<=s; ++k) {
            events.push_back(event(sqrt(i*i+j*j) * k, 2));    
          }
          for (int k=0; k<I; ++k) {
            events.push_back(event( sqrt(I*I + J*J) / (2*I) * (2*k+1), 0));
          }
          for (int k=0; k<J; ++k) {
            events.push_back(event( sqrt(I*I + J*J) / (2*J) * (2*k+1), 1));
          }
          
          sort(events.begin(), events.end());

//          printf("SHOOT: %d %d\n", i, j);

          int tmp = simulate();
          if (tmp) {
//            printf("GOL! %d %d \n", i, j);
          } else{
//            printf("PUDŁO. %d %d\n", i, j);
          }
          res += tmp;
        }
      }
    }
  }
  printf("Case #%d: %d\n", ++caseCount, res);
}

int main() {
  int t; scanf(" %d", &t);
  while(t--) {
    make();
  }
  return 0;
}
