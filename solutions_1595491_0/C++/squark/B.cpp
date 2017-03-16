#include <stdio.h>

int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, i0;
  scanf("%d", &T);
  for(i0 = 1; i0 <= T; i0++){
    int a, b;
    int n, s, p;
    int p1, p2;
    scanf("%d%d%d", &n, &s, &p);
    a = b = 0;
    if(p)
      p1 = p*3-2;
    else
      p1 = 0;
    if(p >= 2)
      p2 = p*3-4;
    else
      p2 = p;
    while(n--){
      int t;
      scanf("%d", &t);
      if(t >= p1)
        a++;
      else if(t >= p2)
        b++;
    }
    printf("Case #%d: %d\n", i0, a+(b<s?b:s));
  }
  return 0;
}
