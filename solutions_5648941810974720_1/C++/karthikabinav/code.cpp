#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

string vals[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int mapping[10][26];
int order[10] = {2, 0, 6, 8, 4, 5, 7, 3, 1, 9};

bool possible(int has[26], int i)
{
  int j;
  for(j=0;j<vals[i].length();j++)
  {
      if(has[vals[i][j]-'A']<mapping[i][vals[i][j]-'A'])
        return false;

  }
  return true;

}

bool check(int has[26])
{
  int i;
  for(i=0;i<26;i++)
  {
    if(has[i]>0)
    return false;
  }
  return true;
}
int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  int i,j;
  for(i=0;i<10;i++)
  {
      for(j=0;j<vals[i].length();j++)
        mapping[i][vals[i][j]-'A']++;
  }

  int count = 1;
  while(t--)
  {
      string s;
      cin>>s;

      int has[26];
      for(i=0;i<26;i++)
      has[i] = 0;

      for(i=0;i<s.length();i++)
        has[s[i]-'A']++;

      vector<int> ans;

      /*for(i=0;i<26;i++)
        cout<<has[i]<<" ";
        cout<<endl;*/
      for(i=0;i<10;i++)
      {
          int cur = order[i];
          while(possible(has, cur))
          {
              ans.push_back(cur);
              for(j=0;j<vals[cur].length();j++)
              {
                  has[vals[cur][j]-'A']--;
              }
              /*for(i=0;i<26;i++)
                cout<<has[i]<<" ";
                cout<<endl;*/

          }

      }
      assert(check(has));
      /*for(i=0;i<26;i++)
        cout<<has[i]<<" ";
        cout<<endl;*/
      sort(ans.begin(),ans.end());
      cout<<"Case #"<<count<<": ";
      for(i=0;i<ans.size();i++)
        cout<<ans[i];
      cout<<endl;
      count++;

  }


  return 0;
}
