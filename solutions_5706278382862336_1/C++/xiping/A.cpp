#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool trailing_space = true; // for output

struct Solver
{
   long P, Q;

   static long get_gcd(long a, long b)
   {
      while (b)
      {
         long r = a % b;
         a = b;
         b = r;
      }
      return a;
   }

   void read_input()
   {
      char c;

      cin >> P >> c >> Q;
   }

   void solve()
   {
      long gcd = get_gcd(P, Q);
      P /= gcd;
      Q /= gcd;

      if (Q & (Q - 1))
      {
         cout << "impossible";
         return;
      }
      int gen = 0;
      while (Q > P)
      {
         Q >>= 1;
         ++ gen;
      }
      cout << gen;
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

