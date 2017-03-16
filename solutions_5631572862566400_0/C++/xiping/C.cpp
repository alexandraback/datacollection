#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>

#include <cassert>

using namespace std;

typedef ptrdiff_t ist;
typedef size_t iut;
typedef vector<ist> vi;
typedef pair<ist, ist> pii;

bool trailing_space = true; // for output

struct Solver
{
   ist N;
   vi fs;
   ist ans;

   void read_input()
   {
      cin >> N;
      fs.resize(N);
      for(auto &f: fs)
      {
        cin >> f;
        -- f;
      }
   }

   void solve()
   {
      ans = 0;
      vi markers(N);
      vi markers2(N);

      for(ist i = 0; i < N; ++ i)
      {
        if (markers[i]) continue;
        ist j = i;
        ist k = 1;
        vi markers3(N);
        for(; !markers3[j]; j = fs[j], ++ k)
        {
          markers[j] = 1;
          markers3[j] = k;
        }
        if (k == markers3[j] + 2)
        {
          ans = max(ans, k - 1 + markers2[fs[j]]);
          markers2[j] = max(markers2[j], k - 3);
        }
        else
        {
           ans = max(ans, k  - markers3[j]);
        }
      }
   }

   void print_output()
   {
      cout << ans;
   }

   void execute()
   {
      read_input();
      solve();
      print_output();
   }
};


int main()
{
   int T = 0;
   cin >> T;
   for (int i = 0; i < T; ++ i)
   {
      cerr << "Solving Case #" << i + 1 << '\n';
      cout << "Case #" << i + 1 << ':';
      if (trailing_space) cout << ' ';
      Solver s;
      s.execute();
      cout << '\n';
   }

   return 0;
}

