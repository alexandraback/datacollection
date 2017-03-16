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
   map<vi, ist> cache;

   ist N;
   vi data;
   ist ans;

   void read_input()
   {
      cin >> N;
      data.resize(N);

      for (auto & i : data) cin >> i;
   }

   ist solve(const vi & input)
   {
      if (input.back() <= 3)
      {
         return input.back();
      }

      auto iter = cache.find(input);

      if (iter != cache.end()) return iter->second;

      vi i3 = input;

      ist b = i3.back();

      i3.pop_back();

      ist n = input.back();

      for (ist i = 1; i <= b / 2; ++i)
      {
         vi i4 = i3;
         i4.push_back(i);
         i4.push_back(b - i);
         sort(i4.begin(), i4.end());
         ist n2 = 1 + solve(i4);
         if (n > n2) n = n2;
      }


      return cache[input] = n;
   }

   void solve()
   {
      sort(data.begin(), data.end());
      ans = solve(data);
   }

   void print_output()
   {
      cout << ans;
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

