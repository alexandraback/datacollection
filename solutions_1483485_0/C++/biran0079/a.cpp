#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char *argv[])
{

  string s[3]={
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"
  },ss[3]={
"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"
  };
  int a[256]={0};
  for(int i=0;i<3;i++){
    for(int j=0;j<s[i].size();j++){
      a[s[i][j]]=ss[i][j];
    }
  }
  a['z']='q';
  a['q']='z';
  int n;
  cin>>n;
  string t;
  getline(cin,t);
  for(int tm=1;tm<=n;tm++){
    cout<<"Case #"<<tm<<": ";
    getline(cin,t);
    for(int j=0;j<t.size();j++)
      cout<<(char)a[t[j]];
    cout<<endl;
  }
  return 0;
}
