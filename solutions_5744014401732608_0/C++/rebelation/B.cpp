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

int b;
ll m;
int g[64][64];
ll way[64];

bool tra(int cur, int hist){
  if((hist >> cur) & 1)
    return false;
  hist |= 1<<cur;
  way[cur]++;
  bool ok = true;
  for(int i = 0; i < b-1; i++)if(g[cur][i])ok &= tra(i, hist);
  return ok;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for(int o = 1; o <= T; o++){
    printf("Case #%d: ", o);
    cin >> b >> m;
    for(int i = 0; i < b; i++)for(int j = 0; j < b; j++)g[i][j] = 0;
    int c = b-1;
    int d = c*(c-1);
    int lim = 1<<d;
    bool found = false;
    for(int s = 0; s < lim && !found; s++){
      int count = 0;
      for(int i = 0; i < c; i++)
        for(int j = 0; j < c; j++)
          if(i != j){
            g[i][j] = (s>>count) & 1;
            count++;
          }
      bool f = true;
      for(int i = 0; i < c; i++)for(int j = 0; j < c; j++)if(g[i][j] == 1 && g[j][i]){f = false; break;}
      if(!f)continue;
      //memset(way, sizeof(way), 0);
      for(int i = 0; i < c; i++)way[i] = 0;
      if(!tra(0, 0))
        continue;
      int mask = 1<<c;
      for(int t = 1; t < mask; t++){
        ll sum = 0;
        for(int i = 0; i < c; i++)if((t>>i)&1)sum += way[i];
        if(sum == m){
          found = true;
          for(int j = 0; j < c; j++)g[j][c] = (t>>j)&1;
          printf("POSSIBLE\n");
          for(int j = 0; j < b; j++){
            for(int k = 0; k < b; k++)printf("%d", g[j][k]);
            printf("\n");
          }
          break;
        }
      }
    }
    if(!found)printf("IMPOSSIBLE\n");
  }

  return 0;
}
