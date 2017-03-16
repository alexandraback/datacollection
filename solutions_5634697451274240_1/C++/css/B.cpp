#include <cstdio>
#include <cstring>
using namespace std;

const int maxN = 107;
int T, len, ans;
char str[maxN];

int main()
{
  freopen("B-large.in", "r", stdin);
  freopen("output.out", "w", stdout);

  scanf("%d", &T);
  for (int cou = 1; cou <= T; cou++) {
    scanf("%s", str), len = strlen(str), str[len] = '+';
    
    ans = 0;
    for (int i = 0; i < len; i++)
      if (str[i] != str[i + 1]) ans++;

    printf("Case #%d: %d\n", cou, ans); 
  }

  fclose(stdin);
  fclose(stdout);
}
