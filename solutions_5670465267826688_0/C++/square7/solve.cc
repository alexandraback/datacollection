#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

// 1->1, i->2, j->3, k->4

int get(int a, int b)
{
  int sign=(a*b>0?1:-1);
  a=abs(a);
  b=abs(b);
  if(a==1)
    {
      switch(b)
	{
	case 1: return 1*sign;
	case 2: return 2*sign;
	case 3: return 3*sign;
	case 4: return 4*sign;
	}
    }
  if(a==2)
    {
      switch(b)
	{
	case 1: return 2*sign;
	case 2: return -1*sign;
	case 3: return 4*sign;
	case 4: return -3*sign;
	}
    }
  if(a==3)
    {
      switch(b)
	{
	case 1: return 3*sign;
	case 2: return -4*sign;
	case 3: return -1*sign;
	case 4: return 2*sign;
	}
    }
  if(a==4)
    {
      switch(b)
	{
	case 1: return 4*sign;
	case 2: return 3*sign;
	case 3: return -2*sign;
	case 4: return -1*sign;
	}
    }
  cerr << "ERROR" << endl;
  return 0;
}

int mul(const vector<int>& vec)
{
  int val=1;
  for(int i = 0; i < vec.size(); ++i)
    {
      val=get(val, vec[i]);
    }
  return val;
}

bool solve(const vector<int>& vec)
{
  int val=1;
  int target=2;
  for(int i = 0; i < vec.size(); ++i)
    {
      val=get(val, vec[i]);
      if(val==target)
	{
	  val=1;
	  target++;
	}
      else if(val==-target)
	{
	  val=-1;
	  target++;
	}
    }
  if(target==5 && val==1)
    {return true;}
  else
    {return false;}
}

vector<int> copy(const vector<int>& vec, int n)
{
  vector<int> res(vec.size()*n);
  for(int i = 0; i < n; ++i)
    {
      for(int j = 0; j < vec.size(); ++j)
	{
	  res[i*vec.size()+j]=(vec[j]);
	}
    }
  return res;
}

int main()
{
  int cnt;
  cin >> cnt;
  for(int i = 0; i < cnt; ++i)
    {
      int L,X;
      string str;
      cin >> L >> X >> str;
      vector<int> origin,effect;
      for(int j = 0; j < str.size(); ++j)
	{
	  origin.push_back(str[j]-'i'+2);
	}
      if(X<4)
	{
	  effect=copy(origin,X);
	}
      else
	{
	  effect=copy(origin,4);
	  int ele=mul(origin);
	  for(int j=4;j<X;++j)
	    {effect.push_back(ele);}
	}
      cout << "Case #" << i+1 << ": ";
      if(solve(effect))
	{cout << "YES" << endl;}
      else
	{cout << "NO" << endl;}
    }
}
