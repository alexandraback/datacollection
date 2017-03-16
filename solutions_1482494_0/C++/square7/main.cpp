#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class level
{
public:
  level(int x, int y, int i)
    :a(x), b(y), visit1(0),visit2(0), id(i) {}
  bool visit1;
  bool visit2;
  int a;
  int b;
  int id;
};

bool operator==(level a, level b)
{
  return a.id == b.id;
}

bool comp1(level x, level y)
{
  return x.a > y.a;
}

bool comp2(level x, level y)
{
  return x.b > y.b;
}

int main()
{
  int totCase;
  cin >> totCase;
  for(int i = 0; i < totCase; ++i)
    {
      int l;
      cin >> l;
      cout << "Case #" << (i+1) << ": ";
      vector<level> level1;
      vector<level> level2;
      for(int j = 0; j < l; ++j)
	{
	  int x, y;
	  cin >> x >> y;
	  level1.push_back(level(x, y, j));
	  level2.push_back(level(x,y, j));
	}
      sort(level1.begin(), level1.end(), comp1);
      sort(level2.begin(), level2.end(), comp2);
      int currStar = 0;
      int curr = 0;
      while(level2.size() != 0)
	{
	  ++curr;
	  if(currStar >= level2.back().b)
	    {
	      vector<level>::iterator iter = find(level1.begin(), level1.end(), level2.back());
	      if(iter == level1.end())
		{
		  ++currStar;
		}
	      else
		{
		  currStar += 2;
		  level1.erase(iter);
		}
	      cerr << level2.back().id << " ";
	      level2.pop_back();
	      continue;
	    }
	  if(level1.size() != 0 && currStar >= level1.back().a)
	    {
	      //cerr << "!!!" << level1.back().id << " ";
	      vector<level>::iterator iter = level1.end();
	      vector<level>::iterator finalIter = iter;
	      --iter;
	      int l2 = 0;
	      while(iter != level1.end() && currStar >= iter->a)
		{
		  if(l2 < iter->b)
		    {l2 = iter->b; finalIter = iter;}
		  if(iter != level1.begin())
		    {--iter;}
		  else
		    {iter = level1.end();}
		}
	      
	      //cerr << "!!!" << iter->id << " ";
	      level1.erase(finalIter);
	      ++currStar;
	      continue;
	    }
	  cout << "Too Bad" << endl;
	  break;
	}
      if(level2.size() == 0)
	{cout << curr << endl;}
      // cerr << endl;
    }
}
