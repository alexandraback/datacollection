//Im namen Gottes
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int n=20;
int inp[n];

map<int,int> mp;

void print(int x)
{
  for(int i=0;i<n;++i)
    {
    if(x%2)
      cout<<inp[i]<<" ";
    x/=2;
    }
  cout<<endl;
}

int slv()
{
  map<int,int> t;
  mp=t;
  int shit;
  cin>>shit;
  for(int i=0;i<n;++i)
    cin>>inp[i];
  for(int i=0;i<=1048575;++i)
    {
      int cp=i;
      int sum=0;
      for(int j=0;j<20;++j)
	{
	if(cp%2)
	  sum+=inp[j];
	cp/=2;
	}
      if(mp.find(sum)!=mp.end())
	{
	print(mp[sum]);
	print(i);
	return 0;
	}
      mp[sum]=i;
    }
  cout<<"Impossible"<<endl;
  return 0;
}

int main()
{
  int t;
  cin>>t;
  for(int i=1;i<=t;++i)
    {
    cout<<"Case #"<<i<<":\n";
    slv();
    }
  return 0;
}
