#include <stdio.h>
#include <string.h>


int T;
int n;
char s[1000010];
int ends[1000010];
int le;
int tam;


int main() {
  scanf(" %d", &T);
  for(int t=1; t<=T; t++) {
    scanf(" %s %d", s, &n);
    int c = 0;
    tam = strlen(s);
    memset(ends, 0, sizeof(ends));
    le = -1;
    for(int i=0; i<tam; i++) {
      if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
        c = 0;
      } else {
        c++;
        if(c >= n) {
          ends[i] = 1;
          le = i;
        }
      }
    }
    
    long long int resp = 0;
    if(le != -1) {
      le = 2000000000;
      for(int i=0; i<tam; i++) {
        if(ends[i] == 1) {
          resp += i - n + 2;
          le = i;
        }
        if(i > le) {
          resp += le - n + 2;
        }
      }
    }
    printf("Case #%d: %lld\n", t, resp);
  }
}
