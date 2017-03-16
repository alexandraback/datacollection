#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

const int W = 20;
const int H = 20;

int cnt;
bool vis[H+1][2*W+1];
int p[H+1][2*W+1];
int N;

void calc(int d=0, int x=0, int y=H){
  if(d == N){
    for(int y = 0; y <= H; ++y)
      for(int x=-W; x <= W; ++x)
        p[y][x+W] += vis[y][x+W];
    ++cnt;
    return;
  }
  if(d == 0){
    vis[0][W+x] = true;
    calc(1);
    return;
  }

  while(y != 0){
    if(vis[y-1][x+W-1] && vis[y-1][x+W+1]){
      vis[y][x+W] = true;
      calc(d+1);
      vis[y][x+W] = false;
      return;
    }
    if(vis[y-1][x+W-1] || vis[y-1][x+W+1]){
      if(vis[y-1][x+W-1]) ++x;
      if(vis[y-1][x+W+1]) --x;
      --y;
    }
    else if(y >= 2){
      if(vis[y-2][x+W]){
        calc(d, x+1, y-1);
        calc(d, x-1, y-1);
        return;
      }
      else
        y -= 2;
    }
    else
      assert(false);
  }

  vis[y][x+W] = true;
  calc(d+1);
  vis[y][x+W] = false;
}

int main(void){
  int T;
  cin >> T;
  for(int t = 0; t < T; ++t){
    int X, Y;
    cin >> N >> X >> Y;
    cnt = 0;

    for(int y = 0; y <= H; ++y){
      fill_n(p[y], 2*W+1, 0);
      fill_n(vis[y], 2*W+1, false);
    }

    calc();

#ifdef DEBUG
    for(int y = H; y >= 0; --y){
      for(int x=-W; x <= W; ++x){
        printf("%d ", p[y][x+W]);
      }
      cout << endl;
    }
#endif

    double ans = 0;
    if(X < -W || W < X || Y > H)
      ans = 0;
    else
      ans = p[Y][X+W] / (double)cnt;
    cout << "Case #" << t+1 << ": " << ans << endl;
  }

  return 0;
}
