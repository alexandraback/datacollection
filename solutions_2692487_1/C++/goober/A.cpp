#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
  int T;
  std::cin >> T;
  for (int t=1; t<=T; t++)
  {
    long long A;
    int N;

    std::cin >> A >> N;
    std::vector<int> sizes(N);
    for (int i=0; i<N; i++)
      std::cin >> sizes[i];

    sort(sizes.begin(), sizes.end());
    int best = N;
    int cost = 0;
    if (A > 1)
    {
      for (int i=0; i<N; i++)
      {
        if (cost + (N-i) < best)
          best = cost + (N-i);
        while(A <= sizes[i])
        {
          A += (A-1);
          cost++;
        }
        A+= sizes[i];
      }
      if (cost < best)
        best = cost;
    }
    
    printf("Case #%d: %d\n", t, best);
  }
  return 0;
}
