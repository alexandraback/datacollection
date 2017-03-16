#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int cases;
  cin >> cases;
  for (int t = 1; t <= cases; ++t)
  {
    printf("Case #%d: ", t);
    int a, b, k;
    cin >> a >> b >> k;
    int ans = 0;
    for (int i = 0; i < a; ++i)
      for (int j = 0; j < b; ++j)
        if ((i & j) < k) ++ans;
    printf("%d\n", ans);
  }
  return 0;
}
