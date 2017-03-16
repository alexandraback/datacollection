#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <cmath>
#include <algorithm>

#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

#define M (20)

int h, w, K;
int total;
bool f[M][M];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
bool visit[M][M];
int calc(){
  int ret = 0;
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++){
      if(f[i][j]){
        ret++;
        continue;
      }
      for(int a = 0; a < h; a++)for(int b = 0; b < w; b++)visit[a][b] = false;
      visit[i][j] = true;
      queue< pair<int, int> > q;
      q.push(make_pair(i, j));
      bool ok = false;
      bool loop = true;
      while(loop && !q.empty()){
        pair<int, int> p = q.front(); q.pop();
        int y = p.first;
        int x = p.second;
        if(y == 0 || y == h-1 || x == 0 || x == w-1){
          ok = true;
          break;
        }
        for(int a = 0; a < 4; a++){
          int ny = y + dy[a];
          int nx = x + dx[a];
          if(ny < 0 || ny >= h || nx < 0 || nx >= w){
            ok = true;
            loop = false;
            break;
          }
          if(f[ny][nx] || visit[ny][nx])
            continue;
          visit[ny][nx] = true;
          q.push(make_pair(ny, nx));
        }
      }
      if(!ok)
        ret++;
    }
  return ret;
}

int main(){
  //cin.tie(0);
  //ios_base::sync_with_stdio(false);

  int T;
  scanf("%d", &T);
  for(int o = 1; o <= T; o++){
    printf("Case #%d: ", o);
    scanf("%d%d%d", &h, &w, &K);
    total = h*w;
    int lim = 1<<total;
    int ans = total;
    for(int i = 1; i < lim; i++){
      int stone = 0;
      for(int j = 0; j < total; j++){
        if((i>>j)&1){
          stone++;
          f[j/w][j%w] = true;
        }else{
          f[j/w][j%w] = false;
        }
      }
      if(calc() >= K)
        ans = min(ans, stone);
    }
    printf("%d\n", ans);
  }

  return 0;
}
