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

bool trailing_space = false; // for output

struct Solver
{
   ist N;
   vector<vi> data;
   vi ans;

   void read_input()
   {
      cin >> N;
      data.resize(2 * N -1);
      map<ist, ist> counts;
      for(auto & d: data)
      {
        d.resize(N);
        for(auto &n: d)
        {
          cin >> n;
          ++ counts[n];
        }
      }

      for(auto &kv: counts)
      {
        if (kv.second &1) ans.push_back(kv.first);
      }
   }

   void solve()
   {
   }

   void print_output()
   {
      if (ans.size() != N) throw(0);

      for(auto &n: ans) cout << ' ' << n;
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

