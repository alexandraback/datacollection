#include <iostream>
#include <map>
#include <vector>

using namespace std;

string digits[10] = {
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE",
};

int order[10];
char chars[10];
bool used[10];

int main()
{
  int used_cnt = 0;
  while (used_cnt < 10)
  {
    bool found = false;
    for (int i = 0; !found && i < 10; ++i)
      if (!used[i])
        for (auto c : digits[i])
        {
          bool unique = true;
          for (int j = 0; j < 10; ++j)
            if (i != j && !used[j] && digits[j].find(c) != string::npos)
            {
              unique = false;
              break;
            }

          if (unique)
          {
            used[i] = true;
            chars[used_cnt] = c;
            order[used_cnt++] = i;
            found = true;
            break;
          }
        }
  }
  chars[9] = 'I';

  int t;
  cin >> t;
  for (int test = 1; test <= t; ++test)
  {
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto c : s)
      ++cnt[c];
    vector<int> answer(10);
    for (int i = 0; i < 10; ++i)
    {
      int x = cnt[chars[i]];
      answer[order[i]] = x;
      for (auto c : digits[order[i]])
        cnt[c] -= x;
    }
    for (auto it : cnt)
      if (it.second)
        return 1;
    cout << "Case #" << test << ": ";
    for (int i = 0; i < 10; ++i)
      for (int j = 0; j < answer[i]; ++j)
        cout << i;
    cout << endl;
  }
  return 0;
}
