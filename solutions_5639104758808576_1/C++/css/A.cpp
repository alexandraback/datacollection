#include <cstdio>
#include <fstream>
using namespace std;
const int maxN = 1e3+7;
char str[maxN];
int T, len, ans, sum;
int main()
{
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  scanf("%d", &T);
  for (int count = 1; count <= T; count++) {
    ans = sum = 0;
    scanf("%d %s", &len, str);
    for (int i = 0; i <= len; i++) {
        if (sum < i) ans += i-sum, sum = i;
        sum += (int)str[i]-(int)'0';
    }
    printf("Case #%d: %d\n", count, ans);
  }
}
