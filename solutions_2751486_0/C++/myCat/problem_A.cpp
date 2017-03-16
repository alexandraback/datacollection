#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::map;
using std::set;

typedef long long answer_type;

bool check_vovel(char c)
{
  if (c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e')
    return true;

  return false;
}

long long solve()
{
  string s;
  int n, k;
  cin >> s >> k;
  n = s.size();

  vector < long long > answer(n, 0);
  vector < int > max_seq(n, 0);

  if (k == 1 && !check_vovel(s[0]))
    answer[0] = 1;

  if (!check_vovel(s[0]))
    max_seq[0] = 1;
  
  for (int i = 1; i < n; ++i)
  {
    answer[i] = answer[i - 1];
    if (!check_vovel(s[i]))
      max_seq[i] = max_seq[i - 1] + 1;
    else
      max_seq[i] = 0;

    if (max_seq[i] >= k)
    {
      answer[i] = 1 + i - k + 1;
    }
  }
  
  long long sum = 0;
  for (int i = 0; i < n; ++i)
    sum += answer[i];
//  for (int i = 0; i < n; ++i)
//    cerr << answer[i] << " ";
//  cerr << endl;
  return sum;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int tests_number;
  scanf("%d", &tests_number);

  for (int test = 1; test <= tests_number; ++test)
  {
    answer_type answer = solve();
    cout << "Case #" << test << ": " << answer << endl;
  }
  
  return 0;
}
