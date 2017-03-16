#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>

using namespace std;

typedef ptrdiff_t ist;
typedef size_t iut;
typedef vector<ist> vi;
typedef pair<ist, ist> pii;

bool trailing_space = true; // for output

struct Solver
{
   string S;
   string ans;

   void read_input()
   {
      cin >> S;
   }

   void solve()
   {
      for(auto c: S)
      {
        bool is_larger = false;
        for(auto c2: ans)
        {
          if (c != c2)
          {
            if (c > c2) is_larger = true;
            break;
          }
        }
        if (is_larger) ans.insert(0, 1, c);
        else ans.push_back(c);
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

