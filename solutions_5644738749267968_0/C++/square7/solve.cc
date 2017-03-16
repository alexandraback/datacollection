#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int normal(list<double> v1, list<double> v2)
{
  int win=0;
  for(auto it1=v1.begin(); it1!=v1.end(); ++it1)
    {
      auto it=v2.begin();
      for(; it!=v2.end() && *it<*it1; ++it)
	{}
      if(it==v2.end())
	{
	  ++win;
	  v2.pop_front();
	}
      else
	{
	  v2.erase(it);
	}
    }
  return win;
}

int deceit(list<double> v1, list<double> v2)
{
  int win=0;
  for(auto it1 = v1.begin(); it1 != v1.end(); ++it1)
    {
      if(*it1>v2.front())
	{
	  ++win;
	  v2.pop_front();
	}
      else
	{
	  v2.pop_back();
	}
    }
  return win;
}

int main()
{
  int tot;
  cin >> tot;
  for(int i = 0; i < tot; ++i)
    {
      cout << "Case #" << i+1 << ": ";
      list<double> v1, v2;
      int N;
      cin >> N;
      for(int j = 0; j < N; ++j)
	{
	  double val;
	  cin >> val;
	  v1.push_back(val);
	}
      for(int j = 0; j < N; ++j)
	{
	  double val;
	  cin >> val;
	  v2.push_back(val);
	}
      v1.sort();
      v2.sort();
      cout << deceit(v1, v2) << " " << normal(v1, v2) << endl;
    }
}
