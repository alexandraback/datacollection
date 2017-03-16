#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
  int t;
  cin>>t;
  for(int test = 0; test < t; test++)
    {
      string s;
      cin>>s;
      string ans(1, s[0]);
      for(int i=1; i < s.size();i++)
        {
          if(s[i] >= ans[0])
            ans.insert(0,1, s[i]);
          else
            ans.append(1, s[i]);
        }
      printf("Case #%d: %s\n", test + 1, ans.c_str());
    }
  
}
