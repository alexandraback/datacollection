#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int H, N, M;
vector<int> c;
vector<int> f;
vector<float> best;

#define X(x,y) ((y*M)+x)
void dyngo(float time, int x, int y);

void trygo(float time, float wl, int tx, int ty, int x, int y) {
  //cout << "moving from " << x << ", " << y << " to " << tx << ", " << ty << endl;
  // is square unmovable?
  if ( c[X(tx,ty)] < (f[X(tx,ty)]+50.0)) return;
  if ( (f[X(x,y)]+50) > c[X(tx,ty)]) return;
  if ( (c[X(x,y)]-50) < f[X(tx,ty)]) return;

  // need to wait?
  if ( wl > (c[X(tx,ty)]-50) ) {
    float oldwl = wl;
    wl = c[X(tx,ty)]-50;
    time += (oldwl-wl) / 10.0;
  }

  float movetime = 0.0;
  if (time != 0.0) {
    movetime = 1.0;
    if ( (f[X(x,y)]+20) > wl) movetime = 10.0;
  }


  dyngo(time+movetime, tx, ty);
}

void dyngo(float time, int x, int y) {
  //cout << x << ", " << y << endl;
  if(best[X(x,y)] != -1 && best[X(x,y)] <= time) return;  // been here, did better or same
  best[X(x,y)] = time; // set the new better

  int tx,ty;
  float wl = H - time*10;
  // try left
  if (x > 0) {
    trygo(time, wl, x-1, y, x, y);
  }
  
  // try right
  if (x < (M-1)) {
    trygo(time, wl, x+1, y, x, y);
  }

  // try up
  if (y > 0) {
    trygo(time, wl, x, y-1, x, y);
  }

  // try down
  if (y < (N-1)) {
    trygo(time, wl, x, y+1, x, y);
  }

}

float runcase() {
  cin >> H >> N >> M;

  c.resize(N*M);
  f.resize(N*M);
  best.resize(N*M);
  for (int i=0;i<(N*M);i++) cin >> c[i];
  for (int i=0;i<(N*M);i++) cin >> f[i];
  for (int i=0;i<(N*M);i++) best[i] = -1;

  //cout << X(2,1) << endl;


  dyngo(0.0,0,0);

  /*for (int i=0;i<(N*M);i++) {
    if ((i % N) == 0 && i != 0) cout << endl;
    cout << best[i] << " ";
  }*/

  return best[N*M-1];
}

int main(int argv, char* argc[]) {
  int case_count;
  cin >> case_count;
  for (int i = 0; i < case_count; i++) {
    cout << "Case #" << (i+1) << ": " << setprecision(9) << runcase() << endl;
  }
}

