#include<iostream>
#include<string>
#include<set>

using namespace std;

int atoi(string a)
{
  int num=0;
  for(int i=0;i<a.size();i++)
    num=num*10+a[i]-'0';
  return num;
}

string rotleft(string a,int i)
{
  string ret;
  for(int j=i;j<a.size();j++)
    ret.push_back(a[j]);
  for(int j=0;j<i;j++)
    ret.push_back(a[j]);
  return ret;
}

string operator+(string a,int x)
{
  bool add=1;
  string ret;
  for(int i=a.size()-1;i>=0;i--)
  {
    //cout<<"in here"<<i<<"\n";
    a[i]=a[i]+add;
    if(a[i]>'9')
    {
      a[i]='0';
      add=1;
    }
    else
      add=0;
  }
  if(add==1)
    ret.push_back('1');
  for(int i=0;i<a.size();i++)
    ret.push_back(a[i]);
  return ret;
}

int main()
{
  int t;
  cin>>t;
  for(int q=1;q<=t;q++)
  {
    string a,b;
    cin>>a>>b;
    set<pair<string,string> > seen;
    for(string i=a;atoi(i)<=atoi(b);i=i+1)
    {
      //cout<<i<<"\n";
      for(int j=1;j<i.size();j++)
      {
	string x=rotleft(i,j);
	if(atoi(x)<=atoi(b) && x[0]!='0' && x!=i && atoi(x)>=atoi(a))
	{
	  //cout<<i<<" "<<x<<"\n";
	  seen.insert(make_pair(min(i,x),max(i,x)));
	}
      }
    }
    cout<<"Case #"<<q<<": "<<seen.size()<<"\n";
  }
  return 0;
}