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

typedef string answer_type;

answer_type solve()
{
  long long x, y, x_c, y_c;
  string answer_x = "";
  string answer_y = "";

  cin >> x >> y;
 
  for (int i = 0; i < x; ++i)
  {
    answer_x = answer_x + "WE";
  }
  for (int i = 0; i > x; --i)
  {
    answer_x = answer_x + "EW";
  }
  for (int i = 0; i < y; ++i)
  {
    answer_y = answer_y + "SN";
  }
  for (int i = 0; i > y; --i)
  {
    answer_y = answer_y + "NS";
  }
  
  string answer = answer_x + answer_y;
  return answer;
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
