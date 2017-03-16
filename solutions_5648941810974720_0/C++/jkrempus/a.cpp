#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <deque>
using std::cout;
using std::cin;
using std::endl;
typedef int64_t Int;

int main()
{
  Int ncases;
  cin >> ncases;
  for(Int case_ = 1; case_ <= ncases; case_++)
  {
    std::string s;
    cin >> s;
    std::vector<Int> counts(26, 0);
    for(auto c : s) counts[c - 'A']++;

    struct E
    {
      std::vector<Int> counts;
      std::vector<Int> digits;
    };

    std::deque<E> q;
    q.push_back(E({counts, {}}));

    while(q.size() > 0)
    {
      E e = q.front();
      q.pop_front();
      auto& c = e.counts;

      if(all_of(c.begin(), c.end(), [](Int a){ return a == 0; }))
      {
        cout << "Case #" << case_ << ": ";
        for(auto digit : e.digits) cout << digit;
        cout << endl;
        break;
      } 

      static const std::string words[] = {
        "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

      for(Int i = e.digits.size() ? e.digits.back() : 0; i < 10; i++)
      {
        E next = e;
        for(auto letter : words[i]) next.counts[letter - 'A']--;

        auto& c = next.counts;;

        if(any_of(next.counts.begin(), next.counts.end(), [](Int a){ return a < 0; }))
          continue;

        next.digits.push_back(i);
        q.push_back(next);
      }
    }
  }

  return 0;
}
