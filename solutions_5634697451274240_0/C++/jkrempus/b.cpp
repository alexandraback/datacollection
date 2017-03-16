#include <iostream>
#include <unordered_set>
#include <deque>
#include <cassert>

int main()
{
  int ncases = 0;
  std::cin >> ncases;
  std::cin.ignore(100, '\n');
  for(int case_ = 1; case_ <= ncases; case_++)
  {
    std::string s;
    std::getline(std::cin, s);

    std::unordered_set<std::string> visited;
    std::deque<std::pair<int, std::string>> q;
    q.emplace_front(0, s);
    visited.insert(s);

    while(true)
    {
      assert(q.size() > 0);
      auto e = q.back();
      q.pop_back();

      auto& s = e.second;
      if(std::find(s.begin(), s.end(), '-') == s.end())
      {
        std::cout << "Case #" << case_ << ": " << e.first << std::endl;
        break;
      }
  
      for(auto i = 1; i <= s.size(); i++)
      {
        auto next = s;
        std::reverse(next.begin(), next.begin() + i);
        for(auto j = 0; j < i; j++) next[j] = next[j] == '-' ? '+' : '-';
        if(visited.count(next) != 0) continue;
        visited.insert(next);
        q.emplace_front(e.first + 1, next);
      }
    }
  }

  return 0;
}
