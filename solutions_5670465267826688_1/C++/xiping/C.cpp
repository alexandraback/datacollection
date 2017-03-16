#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <chrono>
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
   ist L, X;
   vi data;
   ist ans;

   void read_input()
   {
      cin >> L >> X;
      N = L * X;
      string str;
      cin >> str;

      data.resize(L);

      for (ist i = 0; i < L; ++i)
      {
         if (str[i] == 'i') data[i] = 1;
         else if (str[i] == 'j') data[i] = 2;
         else if (str[i] == 'k') data[i] = 3;
      }
   }

   void multi(bool & sign, ist & current, ist c)
   {
      if (current == 0)
      {
         current = c;
      }
      else if (c == current)
      {
         current = 0;
         sign ^= true;
      }
      else
      {
         if (current == c + 1 || c == current + 2)
         {
            sign ^= true;
         }

         current = 6 - c - current;

         assert(current >= 1 && current <= 3);
      }
   }

   void solve()
   {
      ans = 0;

      if (data.size() == 1) return;

      if (count(data.begin(), data.end(), data.front()) == data.size()) return;

      bool sign = false;

      ist current = 0;

      for (auto & c : data)
      {
         multi(sign, current, c);
      }

      if (current)
      {
         if (X % 4 != 2) return;
      }
      else
      {
         if (!sign || X % 2 == 0) return;
      }

      ist l = 0;

      if (!find_i(data, l)) return;

      ist l2 = 0;

      vi data2;
      data2.resize(L);

      for (ist i = 0; i < L; ++i)
      {
         data2[i] = 4 - data[L - i - 1];
      }

      if (!find_i(data2, l2)) return;

      if (l + l2 >= L * X) return;

      ans = 1;
   }

   bool find_i(const vi & data, ist & l)
   {
      bool sign = false;
      ist current = 0;
      for (ist j = 0; j < 4; ++j)
      {
         for (ist i = 0; i < L; ++i)
         {
            multi(sign, current, data[i]);

            if (!sign && current == 1)
            {
               l = i + L * j + 1;
               return true;
            }
         }

         // now we did not find it
         if (current == 0 && !sign) return false;
      }

      return false;
   }


   void print_output()
   {
      cout << (ans?"YES":"NO");
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

