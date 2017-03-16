#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

int main()
{
  int brt;
  scanf("%d", &brt);

  for (int br=1; br<=brt; br++) {
    int len, dub, imam;
    scanf("%d%d%d", &len, &dub, &imam);
    printf("Case #%d: ", br);

    if (imam * dub < len) {
      printf("IMPOSSIBLE\n");
      continue;
    }

    for (int ind=0; ind<len; ) {
      ll tmp = 0;
      for (int i=0; i<dub; i++, ind++) {
        int nov = min(ind, len-1);
        tmp = tmp * len + nov;
      }

      printf("%lld ", tmp + 1);
    }
    printf("\n");
  }

  return 0;
}

