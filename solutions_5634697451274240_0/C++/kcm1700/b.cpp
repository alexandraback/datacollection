#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for (int testcase = 1; testcase <= T; testcase++)
  {
    char buffer[200];
    scanf("%s", buffer);
    string s(buffer);
    s.push_back('+');
    int ans = 0;
    for (int i = 0; i + 1 < s.length(); i++)
    {
      if (s[i] != s[i + 1]) {
        ans++;
      }
    }
    printf("Case #%d: %d\n", testcase, ans);
  }
  return 0;
}