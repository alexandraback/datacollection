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
   ist N;
   ist X, R, C;
   ist ans;

   void read_input()
   {
      cin >> X >> R >> C;
      N = R * C;
   }

   void solve()
   {
      if (N < X || N % X != 0 || X > max(R, C) ||  X > 2 * (min(R, C)) || X >= 7 || (N == X && N != 2))
      {
         ans = 1;
         return;
      }

      ans = 0;

      if (X == 2 || X == 3 ) return;

      if (X == 4)
      {
         if (min(R, C) == 2)
         {
            ans = 1;
         }
         return;
      }
   }

   void print_output()
   {
      cout << (ans ? "RICHARD" : "GABRIEL");
   }

   void execute()
   {
      read_input();
      chrono::time_point<chrono::high_resolution_clock> start = chrono::high_resolution_clock::now();
      solve();
      chrono::time_point<chrono::high_resolution_clock> finish = chrono::high_resolution_clock::now();
      cerr << "PERF: size: " << N << " time: " << chrono::duration_cast<chrono::microseconds>(finish - start).count() << " us\n";
      print_output();
   }
};


int main()
{
   int T = 0;
   cin >> T;
   for (int i = 0; i < T; ++i)
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

