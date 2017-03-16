#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int J,P,S,K;

struct V
{
  int T[3];
};

void read()
{
  cin >> J >> P >> S >> K;
}

bool test(vector<V> &rst)
{
  for(int j=1;j<=J;j++)
    for(int p=1;p<=P;p++)
      {
	int k=K;
	for(auto v=rst.begin();v!=rst.end();v++)
	  {
	    if(v->T[0]==j && v->T[1]==p)
	      {
		if(k==0)
		  return false;
		else
		  k--;
	      }
	  }
      }
  for(int j=1;j<=J;j++)
    for(int s=1;s<=S;s++)
      {
	int k=K;
	for(auto v=rst.begin();v!=rst.end();v++)
	  {
	    if(v->T[0]==j && v->T[2]==s)
	      {
		if(k==0)
		  return false;
		else
		  k--;
	      }
	  }
      }
  for(int p=1;p<=P;p++)
    for(int s=1;s<=S;s++)
      {
	int k=K;
	for(auto v=rst.begin();v!=rst.end();v++)
	  {
	    if(v->T[1]==p && v->T[2]==s)
	      {
		if(k==0)
		  return false;
		else
		  k--;
	      }
	  }
      }
  return true;
}

void solve(int n,vector<V> &all,vector<V> &rst)
{
  if(n==all.size())
    {
      if(!test(rst))
	rst.clear();
      return;
    }
  vector<V> rst1;
  vector<V> rst2;
  for(int i=0;i<rst.size();i++)
    {
      rst1.push_back(rst[i]);
      rst2.push_back(rst[i]);
    }
  rst1.push_back(all[n]);
  solve(n+1,all,rst1);
  solve(n+1,all,rst2);
  if(rst1.size()>=rst2.size())
    rst=rst1;
  else
    rst=rst2;
}

void solve()
{
  /*vector<V> all;
  for(int j=1;j<=J;j++)
    for(int p=1;p<=P;p++)
      for(int s=1;s<=S;s++)
	{
	  V add;
	  add.T[0]=j;
	  add.T[1]=p;
	  add.T[2]=s;
	  all.push_back(add);
	}
  
  vector<V> rst;
  solve(0,all,rst);*/
  vector<V> rst;
  for(int s=1;s<=S;s++)
    for(int p=1;p<=P;p++)
      for(int j=1;j<=J;j++)
	{
	  V add;
	  add.T[0]=j;
	  add.T[1]=p;
	  add.T[2]=s;
	  rst.push_back(add);
	  if(!test(rst))
	    rst.erase(rst.end()-1);
	}
  cout << rst.size() << endl;
  for(int i=0;i<rst.size();i++)
    cout << rst[i].T[0] << " "<< rst[i].T[1] << " "<< rst[i].T[2] << endl;
}

int main()
{
  int T;
  cin >> T;
  for(int t=1;t<=T;t++)
    {
      read();
      cout << "Case #" << t << ": ";
      solve();
    }
  return 0;
}
