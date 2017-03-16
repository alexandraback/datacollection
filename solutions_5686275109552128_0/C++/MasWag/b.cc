#include <cstdio>
#include <cstdlib>
#include <list>
#include <cmath>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>

#define rep(i,n) for (int i = 0; i < n; i++)

using namespace std;

int main(void)
{
  int T;
  scanf ("%d",&T);
  rep (t,T)
    {
      int y = 0;
      int D;
      int changeTimes = 0;
      list<int> P;
      vector<int> ans;
      scanf ("%d",&D);
      rep (i,D) 
        {
          int p;
          scanf ("%d",&p);
          P.push_back(p);
        }

      while (1) 
        {
          P.sort (std::greater<int>());
          const int n = P.front();
          ans.push_back(n + changeTimes);
          if (n <= 1)
            break;

          P.pop_front();
          P.push_back ((n >> 1) + (n & 1));
          P.push_back (n >> 1);

          changeTimes++;
        }
      
      sort (ans.begin (),ans.end ());
      y = ans.front ();
      printf ("Case #%d: %d\n",t+1,y);
    }

  return 0;
}


