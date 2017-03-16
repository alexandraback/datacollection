#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char S[1111];
char str[1111];

int main(void)
{
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  scanf("%d",&T);
  for (int t = 0; t < T; t++) {
    int n;
    int l;
    long long res = 0;
    scanf("%s",S);
    scanf("%d",&n);
    l = (int)strlen(S);
    for (int i = n; i <= l; i++) {
      for (int j = 0; j+i <= l; j++) {
        int c = 0;
        int m = 0;
        for (int k = j; k < j+i; k++) {
          str[k-j] = S[k];
          if (S[k] != 'a' && S[k] != 'e' && S[k] != 'o' && S[k] != 'i' && S[k] != 'u') c++;
          else c = 0;
          m = max(m, c);
        }
        str[i] = 0;
        if (m >= n) {
          res++;
        }
      }
    }
    printf("Case #%d: %lld\n", t+1, res);
  }
  return 0;
}
