#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 1<<10;

char s[MAX];
vector <int> V;

int main()
{
  int tt;

  scanf("%d", &tt);

  for (int ii=1; ii<=tt; ii++) {
    int n;
    V.clear();
    scanf("%d%s", &n, s);
  
    int ima=0, rez=0;

    for (int i=0; i<=n; i++) {
      rez += max(0, i - ima);
      ima += max(0, i - ima);
      ima += s[i] - '0';
    }

    printf("Case #%d: %d\n", ii, rez);
  }

  return 0;
}
