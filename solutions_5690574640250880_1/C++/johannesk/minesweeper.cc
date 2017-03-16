#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

typedef long long int lli;

#undef _GLIBCXX_DEBUG

#define all(c) (c).begin(),(c).end()
#define foreach(name, list)         \
  for (__decltype((list).begin())   \
         name = (list).begin(),     \
         name##_end = (list).end(); \
       name != name##_end; ++name)

bool vertical_fill(int r, int w, int m,
                   std::vector<std::string> *solution=0)
{
  if (r == 1) return false;

  for (int filled_rows=0; filled_rows<w; filled_rows++) {
    int remaining = m - r*filled_rows;

#ifdef _GLIBCXX_DEBUG
    std::cout<<"remaining: "<< remaining << " r="<<r<<",filled_rows="<<filled_rows<<",w="<<w<<'\n';
#endif
    if (remaining >= r) continue;
    if (remaining < 0)  return false;
    if (w != 1 && ((remaining && filled_rows >= w-2)
                   || (!remaining && filled_rows > w-2))) return false;

    bool fix_remaining = false;
    if (remaining == r-1 && w != 1) {
      if (r == 2 || filled_rows == w-3)
        return false;
      remaining--;
      fix_remaining=true;
    }

    if (solution) {
      for (int i=0; i<r; ++i) {
        std::string row;
        for (int j=0; j<w; ++j) {
          if (i==r-1&&j==w-1)
            row.push_back('c');
          else if (j<filled_rows)
            row.push_back('*');
          else if (j==filled_rows)
            row.push_back(i < remaining ? '*' : '.');
          else
            row.push_back(j==filled_rows+1&&i==0&&fix_remaining?'*':'.');
        }
        solution->push_back(row);
      }
    }

    return true;
  }  
  return false;
}

bool horizontal_fill(int r, int w, int m, bool print=true)
{
  for (int done=0; done<=m; done += w) {
    int rows_remaining = r - done/w;
    if (vertical_fill(rows_remaining, w, m-done)) {
      if (print) {
        for (int i=0; i<done/w; ++i)
          std::cout << std::string(w, '*') << '\n';
#ifdef _GLIBCXX_DEBUG
        std::cout<< "--\n";
#endif
        std::vector<std::string> solution;
        vertical_fill(rows_remaining, w, m-done, &solution);
        for (auto& s : solution) std::cout << s << '\n';
      }
      return true;
    }
  }

  int rows_filled = m/w, rows_remaining=r-rows_filled;
  int rest = m - w*rows_filled;

  if (r != 1 && m+1 != w*r) {
    if (rest == w-1)
      return false;
    if (rows_remaining == 1)
      return false;
    if (rest > 0 && rows_remaining == 2)
      return false;
  }
  if (print) {
    for (int i=0; i<rows_filled; ++i)
      std::cout << std::string(w, '*') << '\n';
    if (rows_remaining > 0) {
      std::string last = std::string(w-rest, '.');
      if (--rows_remaining == 0)
        last.back() = 'c';
      std::cout << std::string(rest, '*')
                << last << '\n';
      while (rows_remaining--)
        std::cout << std::string(w-1, '.')+(rows_remaining?'.':'c') << '\n';
    }
  }
  return true;
}

bool solve(int r, int w, int m)
{
  return horizontal_fill(r, w, m);
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

 // for (int i=0; i<10000; ++i) {
 //   int r = 1+rand()%5;
 //   int w = 1+rand()%5;
 //   int m = rand()%(r*w);
 //   bool a = solve(r, w, m, true);
 //   bool b = solve(w, r, m, false);
 //   if (a!=b)
 //     std::cout << "LOOK AT THIS!\n";
 //   std::cout << std::string(80, '-') << '\n';
 //  }


  int num_of_testcases; std::cin >> num_of_testcases;
  for (int testcase=1; testcase<=num_of_testcases; ++testcase) {
    int r, w, m; std::cin >> r >> w >> m;
    std::cout << "Case #" << testcase << ":\n";// << r << " " << w << " " << m << "\n";

    if (!solve(r, w, m))
      std::cout << "Impossible\n";
  }
}

/*
 * Local variables:
 * mode:c++
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g -ggdb3 -O0 -Wall -Wextra -Wno-long-long -std=c++11 minesweeper.cc -o minesweeper && for f in *.in; do echo \"--- $f -------------\"; ./minesweeper <$f; done"
 * end:
 */
