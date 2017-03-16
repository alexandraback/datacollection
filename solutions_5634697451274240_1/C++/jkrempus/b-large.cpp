#include <iostream>
#include <unordered_set>
#include <queue>
#include <cassert>
#include <fstream>

struct Element
{
  int num_flips;
  std::string s;
  Element(int num_flips, const std::string& s_) : num_flips(num_flips)
  {
    std::unique_copy(s_.begin(), s_.end(), std::back_inserter(s));
  }

  bool operator<(const Element& other) const
  {
    return num_flips + s.size() > other.num_flips + other.s.size();
  }
};

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
    std::priority_queue<Element> q;
    q.push(Element(0, s));

    while(true)
    {
      assert(q.size() > 0);
      auto e = q.top();
      q.pop();
      if(visited.count(e.s) != 0) continue;
      visited.insert(e.s);

      if(e.s == "+")
      {
        std::cout << "Case #" << case_ << ": " << e.num_flips << std::endl;
        break;
      }

      for(auto i = 1; i <= e.s.size(); i++)
      {
        std::string next = e.s;
        std::reverse(next.begin(), next.begin() + i);
        for(auto j = 0; j < i; j++) next[j] = next[j] == '-' ? '+' : '-';
        q.push(Element(e.num_flips + 1, next));
      }
    }
  }

  return 0;
}
