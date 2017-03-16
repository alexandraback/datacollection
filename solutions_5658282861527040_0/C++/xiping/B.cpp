#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool trailing_space = true; // for output

struct Solver
{
   long A, B, K;

   void read_input()
   {
      cin >> A >> B >> K;
   }

   void solve()
   {
      if (A < B) swap(A, B);

      if (K >= B)
      {
         cout << A * B;
         return;
      }
      long sum = 0;
      for(int i = 0; i < A; ++ i)
{
      for(int j = 0; j < B; ++ j)
      {
         if ((i & j) < K) ++ sum;
      }
}
      cout << sum;
   }

   void print_output()
   {
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
   long T = 0;
   cin >> T;
   for (long i = 0; i < T; ++ i)
   {
      cout << "Case #" << i + 1 << ':';
      if (trailing_space) cout << ' ';
      Solver s;
      s.execute();
      cout << '\n';
   }

   return 0;
}

