#include <stdio.h>
#include <string.h>

char a[10], b[10];
char s[20];

int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, i0;
  scanf("%d", &T);
  for(i0 = 1; i0 <= T; i0++){
    int n, i, j, t;
    int ans = 0;
    scanf("%s%s", a, b);
    n = strlen(a);
    for(i = 0; i < n; i++)
      s[i] = a[i];
    while(strncmp(s, b, n) <= 0){
      for(i = 0; i < n; i++)
        s[i+n] = s[i];
      for(i = 1; strncmp(s+i, s, n); i++)
        if(s[i] != '0' && strncmp(s+i, s, n) < 0 && strncmp(s+i, a, n) >= 0)
          ans++;
      i = n-1;
      s[i]++;
      while(s[i] > '9'){
        s[i] = '0';
        i--;
        if(i < 0)
          break;
        s[i]++;
      }
      if(i < 0)
        break;
    }
    printf("Case #%d: %d\n", i0, ans);
  }
  return 0;
}
