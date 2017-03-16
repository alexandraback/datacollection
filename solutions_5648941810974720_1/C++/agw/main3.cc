#include <algorithm>
#include <cassert>
#include <cstdio>
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
#include <unordered_map>
#include <vector>


#define INF 1000000002486618624LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


std::vector<std::string> NUMBERS = {
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE"
};


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::vector<std::pair<char, int>> a;

  a.emplace_back('G', 8);
  a.emplace_back('U', 4);
  a.emplace_back('W', 2);
  a.emplace_back('X', 6);
  a.emplace_back('Z', 0);
  a.emplace_back('O', 1);
  a.emplace_back('T', 3);
  a.emplace_back('S', 7);
  a.emplace_back('F', 5);
  a.emplace_back('E', 9);
  
  int T;

  std::cin >> T;

  std::map<int, std::map<char, int>> table;

  for (int i = 0; i < 10; i ++) {
    const std::string& s = NUMBERS[i];

    for (int j = 0, size = s.size(); j < size; j ++)
      table[i][s[j]] ++;
  }

#if 0
  std::cerr << "   A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << std::endl;
  
  for (int i = 0; i < 10; i ++) {
    std::cerr << i << ":";
    for (int j = 0; j < 26; j ++)
      std::cerr << ' ' << table[i][j + 'A'];
    std::cerr << std::endl;
  }
#endif

  for (int t = 1; t <= T; t ++) {
    std::string s;
    
    std::cin >> s;

    std::map<char, int> dist;

    for (const auto& c : s)
      dist[c] ++;
    
#if 0
    for (const auto& kv : dist)
      if (kv.second)
        std::cerr << "t=" << t << ":< " << kv.first << ' ' << kv.second << std::endl;
#endif

    std::string ss;

    for (const auto& pair : a) {
      char c = pair.first;
      int  x = pair.second;

      bool update = false;
      
      while (dist[c]) {
        for (const auto& kv : table[x])
          dist[kv.first] -= kv.second;
        
        ss += x + '0';

        update = true;
      }

#if 0
      if (update)
        for (const auto& kv : dist)
          if (kv.second)
            std::cerr << "t=" << t << ":" << c << " " << kv.first << ' ' << kv.second << std::endl;

#endif
    }
    
    for (const auto& kv : dist)
      if (kv.second)
        std::cerr << "t=" << t << ":> " << kv.first << ' ' << kv.second << std::endl;
    
    std::sort(ALL(ss));

    std::cout << "Case #" << t << ": " << ss << std::endl;
  }

  return 0;
}
