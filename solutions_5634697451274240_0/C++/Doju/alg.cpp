#include <cstdio>

char S[110];

int main(){
  int T; scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    printf("Case #%d: ", tt);

    scanf("%s", S);

    int ans = 0; bool minus = false;
    for(int i = 0; S[i]; i++){
      if(i > 0 && S[i] != S[i - 1]) ans++;
      minus = (S[i] == '-');
    }
    if(minus) ans++;

    printf("%d\n", ans);
  }
  return 0;
}
