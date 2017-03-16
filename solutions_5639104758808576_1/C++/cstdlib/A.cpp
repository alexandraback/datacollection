#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
  int T;
  cin>>T;
  for(int i = 1; i <= T; i++)
  {
    int ans = 0;
    int clap = 0;
    int smax;
    string s;
    cin>>smax>>s;
    for(int j = 0; j < s.size();j++)
    {
      if(j <= clap)
      {
        clap += s[j] - '0';
      }
      else
      {
        ans += j - clap;
        clap = j + s[j] - '0';
      }
    }

    printf("Case #%d: %d\n",i, ans);
  }
  return 0;
}
