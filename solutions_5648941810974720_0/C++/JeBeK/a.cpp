#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>

using namespace std;

vector<int>ans;
int t[20];

int f(char c)
{
  return int(c-'A');
}

bool hav(string s)
{
  for(int i=0;i<s.size();i++)
    if(!t[f(s[i])])
      return false;
  return true;
}

void ok(string s,int k)
{
  while(hav(s))
    {
      for(int i=0;i<s.size();i++)
	t[f(s[i])]--;
      ans.push_back(k);
    }
}

int main()
{
  int qw;
  cin>>qw;
  for(int q=1;q<=qw;q++)
    {
      string s;
      cin>>s;
      for(int i=0;i<s.size();i++)
	t[f(s[i])]++;
      ans.clear();
      ok("ZERO",0);
      ok("TWO",2);
      ok("FOUR",4);
      ok("THREE",3);
      ok("ONE",1);
      ok("FIVE",5);
      ok("SIX",6);
      ok("SEVEN",7);
      ok("EIGHT",8);
      ok("NINE",9);
      cout<<"Case #"<<q<<": ";
      sort(ans.begin(),ans.end());
      for(int i=0;i<ans.size();i++)
	cout<<ans[i];
      cout<<endl;
    }
}
