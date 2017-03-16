#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

int T;
int K,N;
int C[256];
int clen;
int needed[256];
int get[256][256];
int get_len[256];
int start_keys[256];
int visited[1<<22];

int route[256];
int dfs(int state, int route_len, int keys[]){
  if (visited[state])
    return false;

  visited[state] = 1;

  if (route_len == N){
    for (int i = 0; i < route_len; i++)
      printf(" %d", route[i]);
    return true;
  }

  int save_keys[42];
  memcpy(save_keys, keys, sizeof(save_keys));

  for (int i = 1; i <= N; i++){
    if ((1<<(i-1))&state)
      continue;
    if (keys[needed[i]] == 0)
      continue;

    route[route_len] = i;
    for (int j = 0; j < get_len[i]; j++)
      keys[get[i][j]]++;
    keys[needed[i]]--;

    if (dfs(state|(1<<(i-1)), route_len+1, keys))
      return true;

    memcpy(keys, save_keys, sizeof(save_keys));
  }
  return false;
}

int main(){
  scanf("%d", &T);
  for (int i = 1; i <= T; i++){
    memset(visited, 0, sizeof(visited));
    memset(start_keys, 0, sizeof(start_keys));
    scanf("%d%d", &K,&N);
    for (int j = 1; j <= K; j++){
      int tt = 0;
      scanf("%d", &tt);
      start_keys[tt]++;
    }
    for (int j = 1; j <= N; j++){
      scanf("%d%d", &needed[j], &get_len[j]);
      for (int k = 0; k < get_len[j]; k++){
        scanf("%d", &get[j][k]);
      }
    }
    printf("Case #%d:", i);
    if (!dfs(0,0,start_keys))
      printf(" IMPOSSIBLE");
    printf("\n");
  }
}
