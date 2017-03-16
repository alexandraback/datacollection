#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>

#include <random>

#include <cassert>

using namespace std;

typedef ptrdiff_t ist;
typedef size_t iut;
typedef vector<ist> vi;
typedef pair<ist, ist> pii;

bool trailing_space = true; // for output

struct Solver
{
   ist K, L, S;
   string keys, word;
   double ans;

   map<char, ist> counts;

   ist m;
   double e;


   void read_input()
   {
      cin >> K >> L >> S;

      cin >> keys >> word;

      assert(K == keys.length() && L == word.length());

      for (auto & c : keys)
         counts[c] ++;
   }



   void solve()
   {
      m = 0;
      e = 0;

      if ((size_t)S < word.length()) return;

      for (auto & c : word)
      {
         if (!counts[c]) return;
         //if (!counts.count(c)) return;
      }

#if 1
      ist l = word.length();

      for (ist i = 1; i < word.length(); ++i)
      {
         ist o = word.length() - i; 
         if (word.compare(i, o, word, 0, o) == 0)
         {
            l = i;
            break;
         }
      }

      m = 1 + (S - word.length()) / l;

      // now calculate the expectation

      double e1 = 1.0;

      for (auto c : word)
      {
         e1 *= double(counts[c]) / double(K);
      }

      e = (double)(S - word.length() + 1) * e1;
#else
      ist count = 0;
       random_device rd;
       std::mt19937 gen(rd());
       std::uniform_int_distribution<> dis(1, (int)K);
      for (ist i = 0; i < 1024 * 1024; ++i)
      {
         string w;
         for (ist j = 0; j < S; ++j)
            w.append(1, keys[dis(gen) - 1]);

         ist c2 = 0;
         for (ist j = 0; j < S - L + 1; ++j)
         {
            if (w.compare(j, L, word, 0, L) == 0)
            {
               ++count;
               ++c2;
            }
         }

         if (c2 > m) m = c2;
      }
      e = (double)count / double(1024 * 1024);

      std::cerr << m << ' ' << e << '\n';
#endif

      ans = (double)m - e;
   }

   void print_output()
   {
      cout << fixed << setprecision(10) << ans;
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

