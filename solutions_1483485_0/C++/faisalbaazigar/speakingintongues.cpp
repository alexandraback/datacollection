#include<iostream>
#include<map>

using namespace std;

int main()
{
  int t;
  cin>>t;
  map<char,char> lang;
  lang['a']='y';
  lang['b']='h';
  lang['c']='e';
  lang['d']='s';
  lang['e']='o';
  lang['f']='c';
  lang['g']='v';
  lang['h']='x';
  lang['i']='d';
  lang['j']='u';
  lang['k']='i';
  lang['l']='g';
  lang['m']='l';
  lang['n']='b';
  lang['o']='k';
  lang['p']='r';
  lang['q']='z';
  lang['r']='t';
  lang['s']='n';
  lang['t']='w';
  lang['u']='j';
  lang['v']='p';
  lang['w']='f';
  lang['x']='m';
  lang['y']='a';
  lang['z']='q';
  string str;
  getline(cin,str);
  for(int q=1;q<=t;q++)
  {
    getline(cin,str);
    string ans;
    for(int i=0;i<str.size();i++)
    {
      if(str[i]==' ')
	ans.push_back(' ');
      else
	ans.push_back(lang[str[i]]);
    }
    cout<<"Case #"<<q<<": "<<ans<<"\n";
  }
  return 0;
}