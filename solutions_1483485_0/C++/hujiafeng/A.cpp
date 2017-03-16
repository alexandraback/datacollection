#include<iostream>
#include<memory.h>
using namespace std;
int main()
{
    string s[3]={"ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
    string v[3]={"our language is impossible to understand","there are twenty six factorial possibilities",
    "so it is okay if you want to just give up"};
    int a[26];
    memset(a,-1,sizeof(a));
    for(int i=0;i<3;i++)
    {
        int h=s[i].size();
        for(int j=0;j<h;j++)
        {
            if(s[i][j]>='a' && s[i][j]<='z')
            a[s[i][j]-'a']=v[i][j]-'a';
        }
    }
    a['q'-'a']='z'-'a';
        a[25]='q'-'a';

   // for(int i=0;i<26;i++)
  //  {
      //  if(a[i]!=-1)
      // cout<<char(i+'a')<<"-->"<<char(a[i]+'a')<<endl;
   // }
    string str;
    freopen("A-small-attempt4.in","r",stdin);
    freopen("a.out","w",stdout);
    int ca;
    cin>>ca;
    getchar();
    for(int z=1;z<=ca;z++)
    {
        cout<<"Case #"<<z<<": ";
        getline(cin,str);
      //  cout<<str;
        for(int k=0;k<str.size();k++)
        {
             if(str[k]>='a' && str[k]<='z' && a[str[k]-'a']!=-1)
             cout<<char(a[str[k]-'a']+'a');
             else cout<<str[k];
        }
        cout<<endl;
    }
    return 0;
}
