#include <cstdio>
#include <deque>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for (int testcase = 1; testcase <= T; testcase++)
  {
    char dat[1024];
    scanf("%s", dat);
    string s(dat);
    deque<char> ans;
    for (auto c : s)
    {
      if (ans.empty() || ans[0] <= c) {
        ans.push_front(c);
      }
      else {
        ans.push_back(c);
      }
    }
    string ansstr(ans.begin(), ans.end());
    printf("Case #%d: %s\n", testcase, ansstr.c_str());
  }
  return 0;
}