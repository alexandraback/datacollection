#include <bits/stdc++.h>

using namespace std;



int main()
{
  int n, cas = 0, ls;
  scanf("%d", &n);
  char s[1001];
  string ans;
  while(n--)
  {
    scanf(" %s", s);
    ans.clear();
    ans.push_back(s[0]);
    for(char * w = s + 1; *w; ++w)
    {
      if(*w >= ans.front())
        ans.insert(0, 1, *w);
      else
        ans.push_back(*w);
    }
    cout << "Case #" << ++cas << ": " << ans << "\n";
  }
  return 0;
}
