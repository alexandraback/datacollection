#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include <algorithm>
#include <map>
#include <set>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

ull m[1 << 26];
vector<string> cars;

struct Letter_Info
{
  vector<int> beg;
  vector<int> ends;
  vector<int> only;
};

Letter_Info li[26];
ull fact[300];
const ull MOD = 1000000007;
int chars_used = 0;

ull f(int mask)
{
  if ((mask & chars_used) == 0)
    return 1;

  if (m[mask] != -1)
    return m[mask];

  ull res = 0;

  for (int i = 0; i < 26; ++i)
  {
    if (mask & (1 << i))
    {
      if (li[i].ends.size() > 0)
        continue;

      if ((chars_used & (1 << i)) == 0)
        continue;

      int new_mask = mask;
      ull cur_ans = fact[li[i].only.size()];
      new_mask = mask & (~(1 << i));

      int index = i;

      while (li[index].beg.size() > 0)
      {
        index = cars[li[index].beg[0]].back() - 'a';
        cur_ans = cur_ans * fact[li[index].only.size()] % MOD;
        new_mask = new_mask & (~(1 << index));
      }

      cur_ans = cur_ans * f(new_mask) % MOD;
      res += cur_ans;
      res %= MOD;
    }
  }
  m[mask] = res;
  return res;
}

bool check(const string & s)
{
  for (int i = 0; i < s.size();)
  {
    char x = s[i];
    while (s[i] == x)
      ++i;

    if (s.find(x, i) != string::npos)
      return false;
  }

  return true;
}

int main()
{
  freopen("B-small-attempt1.in", "r", stdin);
  freopen("B-result-small1.out", "w", stdout);
  int T;
  scanf("%d", &T);

  fact[0] = 1;
  for (int i = 1; i < 300; ++i)
  {
    fact[i] = fact[i-1] * i % MOD;
  }

  for (int i = 0; i < T; ++i)
  {
    chars_used = 0;
    for (int i = 0; i < (1 << 26); ++i)
    {
      m[i] = -1;
    }
    cars.clear();
    for (int i = 0; i < 26; ++i)
    {
      li[i].beg.clear();
      li[i].ends.clear();
      li[i].only.clear();
    }

    int n;
    cin >> n;
    ull answer = 0;
    for (int i = 0; i < n; ++i)
    {
      cars.push_back("");
      cin >> cars.back();

      for (int j = 0; j < cars.back().size(); ++j)
        chars_used = chars_used | (1<< (cars.back()[j] - 'a'));

    }

    for (int i = 0; i < n; ++i)
    {
      string & s = cars[i];
      if (s.front() != s.back())
      {
        li[s.front() - 'a'].beg.push_back(i);
        li[s.back() - 'a'].ends.push_back(i);
      }
      else
      {
        li[s.back() - 'a'].only.push_back(i);
      }

      for (int j = 0; j < s.size(); ++j)
      {
        if (s[j] != s.front() && s[j] != s.back())
        {
          for (int k = 0; k < n; ++k)
          {
            if (k == i)
              continue;

            if (cars[k].find(s[j]) != string::npos)
              answer = -1;
          }
        }
      }
    }

    for (int i = 0; i < 26; ++i)
    {
      if (li[i].ends.size() > 1 || li[i].beg.size() >1)
        answer = -1;
    }

    //if (answer != -1)
    //  answer = f((1 << 26) - 1);
    //else
    //  answer = 0;
    answer = 0;
    vector<int> order;
    for (int i = 0; i < n; ++i)
      order.push_back(i);

    do
    {
      string s;
      for (int i = 0; i < n; ++i)
        s += cars[order[i]];

      if (check(s))
        answer++;

    } while ( std::next_permutation(order.begin(),order.end()) );

    printf("Case #%d: %I64u", i + 1, answer);



    printf("\n");
    fflush(stdout);
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
};