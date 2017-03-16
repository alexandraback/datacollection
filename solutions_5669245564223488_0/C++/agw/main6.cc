#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>


#define INF 1000000000
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


bool check(const std::string& s)
{
  std::map<char, int> map;

  for (int i = 0, size = s.size(); i < size; i ++) {
    if (map.count(s[i]))
      if (i != map[s[i]] + 1)
        return false;

    map[s[i]] = i;
  }

  return true;
}

std::string concat(const std::vector<std::string>& a)
{
  std::string s;

  std::map<char, int> map;

  for (const auto& i : a) {
    for (int j = 0, size = i.size(); j < size; j ++) {
      if (map.count(i[j]))
        if (s.size() + j != map[i[j]] + 1)
          return "";

      map[i[j]] = s.size() + j;
    }

    s += i;
  }
 
  return s;
}

std::string shorten(const std::string& s)
{
  std::string t;

  for (const auto& c : s)
    if (t.empty() || t.back() != c)
      t.push_back(c);

  return t;
}

int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T, N;
  
  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::cin >> N;

    std::vector<std::string> a(N);

    std::vector<int> b(N);

    for (int i = 0; i < N; i ++)
      std::cin >> a[b[i] = i];

    std::cerr << "t=" << t;
    for (const auto& i : a)
      std::cerr << ' ' << i;
    std::cerr << std::endl;
    
    for (int i = 0; i < N; i ++)
      a[i] = shorten(a[i]);

    std::cerr << "t=" << t;
    for (const auto& i : a)
      std::cerr << ' ' << i;
    std::cerr << std::endl;
    
    long long c = 0;

    do {
      std::vector<std::string> t(N);

      for (int i = 0; i < N; i ++)
        t[i] = a[b[i]];

      std::string s(concat(t));

      if (! s.empty())
        if (check(s))
          c ++;
    } while (std::next_permutation(ALL(b)));

    std::cout << "Case #" << t << ": " << c << std::endl;
  }

  return 0;
}
