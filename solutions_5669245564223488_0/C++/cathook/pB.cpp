#include <cstdio>

int N;
char str[200][100];

int last[256];

bool used[200];

int f(int now){
  static int id[200];
  if(now == N){
    for(int i = 0; i < 256; i++){
      last[i] = -1;
    }
    bool ok = true;
    int len = 0;
    for(int i = 0; i < N; i++){
      int ii = id[i];
      for(int j = 0; str[ii][j] != '\0'; j++){
        int c = str[ii][j];
        //printf("%c", str[ii][j]);
        if(last[c] == -1 || last[c] == len - 1){
          last[c] = len;
        }else{
          ok = false;
          //goto out;
        }
        len++;
      }
    }
out:
    //printf("\n");
    if(ok) return 1;
    return 0;
  }else{
    int ret = 0;
    for(int i = 0; i < N; i++){
      if(used[i] == false){
        used[i] = true;
        id[now] = i;
        ret += f(now + 1);
        used[i] = false;
      }
    }
    return ret;
  }
}

int main(){
  for (int TT, T = (scanf("%d", &TT), 1); T <= TT; T++) {
    scanf("%d", &N);
    char s2[10000];
    for(int i = 0; i < N; i++){
      scanf("%s", s2);
      int len = 0;
      for(int j = 0; s2[j] != '\0'; j++){
        if(j == 0 || s2[j - 1] != s2[j]){
          str[i][len++] = s2[j];
        }
      }
      str[i][len] = '\0';
    }
    for(int i = 0; i < N; i++) used[i] = false;
    int ct = f(0);
    printf("Case #%d: %d\n", T, ct);
  }
  return 0;
}
