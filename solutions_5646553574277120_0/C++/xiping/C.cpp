#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <numeric>

using namespace std;

typedef ptrdiff_t ist;
typedef size_t iut;
typedef vector<ist> vi;
typedef pair<ist, ist> pii;

bool trailing_space = true; // for output

struct Solver
{
   ist C, D, V;
   vi data;
   ist ans;

   void read_input()
   {
      cin >> C >> D >> V;
      data.resize(D);
      for (auto & d : data) cin >> d;
      sort(data.begin(), data.end());
   }

   void solve()
   {
      ist start = 1;
      ist i = 0;
      ans = 0;
      while (start <= V)
      {
         ist coin = start;
         if (i < D && data[i] <= start)
         {
            coin = data[i];
            ++i;
         }
         else
         {
            std::cerr << start << '\n';
            ++ans;
         }
         start += C * coin;
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

