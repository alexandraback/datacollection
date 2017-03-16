#include <cstdio>
#include <cstring>

char S[1010];
char mx[1010];
char res[1010];

int main(){
  int T; scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    printf("Case #%d: ", tt);

    scanf("%s", S);
    int N = strlen(S);

    mx[0] = S[0];
    for(int i = 1; i < N; i++) mx[i] = (mx[i - 1] > S[i] ? mx[i - 1] : S[i]);

    int rs = 0, re = N - 1;
    for(int i = N - 1; i >= 0; i--){
      if(mx[i] == S[i]) res[rs++] = S[i];
      else res[re--] = S[i];
    }
    res[N] = 0;
    puts(res);
  }
  return 0;
}
