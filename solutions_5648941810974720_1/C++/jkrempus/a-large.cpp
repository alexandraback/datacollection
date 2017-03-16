#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <deque>
#include <utility>
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

    std::vector<Int> digit_counts(10, 0);

    const std::pair<char, Int> letter_digit_pairs[] = {
      std::make_pair<char, Int>('Z', 0),
      std::make_pair<char, Int>('X', 6),
      std::make_pair<char, Int>('G', 8),
      std::make_pair<char, Int>('U', 4),
      std::make_pair<char, Int>('W', 2),
      std::make_pair<char, Int>('H', 3),
      std::make_pair<char, Int>('S', 7),
      std::make_pair<char, Int>('F', 5),
      std::make_pair<char, Int>('O', 1),
      std::make_pair<char, Int>('I', 9)};


    static const std::string words[] = {
      "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    for(auto e : letter_digit_pairs)
    {
      auto letter_idx = e.first - 'A';
      auto digit = e.second;
      Int n = counts[letter_idx];
      for(auto letter : words[digit]) counts[letter - 'A'] -= n;
      digit_counts[digit] += n;
    }

    cout << "Case #" << case_ << ": ";
    for(Int i = 0; i < digit_counts.size(); i++)
      for(Int j = 0; j < digit_counts[i]; j++)
        cout << i;

    cout << endl;
  }

  return 0;
}
