#include <cassert>
#include <list>
#include <map>
#include <vector>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
  int T; scanf("%d\n", &T); for (int ii = 1; ii <= T; ++ii)
  {
    int n; scanf("%d\n", &n);
    vector<int> D(n), H(n), M(n);
    for (int i = 0; i < n; ++i) scanf("%d %d %d\n", &D[i], &H[i], &M[i]);
    if (n == 1)
    {
      printf("Case #%d: 0\n", ii);
    }
    else
    {
        if (M[0] >= 2 * M[1] || M[1] >= 2 * M[0]) printf("Case #%d: 1\n", ii);
        else printf("Case #%d: 0\n", ii);
    }
  }
  return 0;
}
