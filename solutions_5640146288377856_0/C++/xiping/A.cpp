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
   ist R, C, W;
   ist ans;

   void read_input()
   {
      cin >> R >> C >> W;
   }

   ist solve(ist c)
   {
      if (c < W) return R * C + 1;

      if (c == W) return W;

      if (c < 2 * W - 1) return W + 1;

      return 1 + solve(c - W);
   }

   void solve()
   {
      ans = solve(C);
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

