#include <cstdio>

int to[1010];
bool is_final[1010], ed[1010], vs[1010];
int cc[1010];
int fin[1010], dist[1010];

int path[1010];

int main(){
  int T; scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    printf("Case #%d: ", tt);

    int N; scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &to[i]);

    for(int i = 1; i <= N; i++){
      is_final[i] = ed[i] = false;
      cc[i] = fin[i] = dist[i] = 0;
    }

    // detect cycles, O(N^2)
    for(int i = 1; i <= N; i++){
        int x = i, d = 0;
        for(;;){
          if(vs[x]) break; // cycle start from x
          vs[x] = true; x = to[x];
          d++;
        }
        if(x == i){
          is_final[i] = true;
          cc[i] = d;
        }
        x = i;
        for(;;){
          if(!vs[x]) break;
          vs[x] = false; x = to[x];
        }
    }

    for(int i = 1; i <= N; i++){
      if(!is_final[i]){
        int x = i, d = 0;
        for(;;){
          if(is_final[x]) break;
          x = to[x]; d++;
        }
        fin[i] = x; dist[i] = d;
      }
    }

    int ans = 0, v = 0;

    for(int i = 1; i <= N; i++){
      if(is_final[i] && !ed[i]){
        if(cc[i] == 2){
          int A = i, B = to[i];
          v += 2;

          int m = 0;
          for(int j = 1; j <= N; j++) if(fin[j] == A && dist[j] > m) m = dist[j];
          v += m;
          m = 0;
          for(int j = 1; j <= N; j++) if(fin[j] == B && dist[j] > m) m = dist[j];
          v += m;

          ed[A] = ed[B] = true;
        }
        else{
          if(cc[i] > ans) ans = cc[i];
          int x = i;
          for(;;){
            if(ed[x]) break;
            ed[x] = true; x = to[x];
          }
        }
      }
    }

    if(v > ans) ans = v;

    printf("%d\n", ans);
  }
  return 0;
}
