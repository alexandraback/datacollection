#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

__int64 flip(__int64 x)
{
  __int64 rez = 0;

  while(x > 0)
  {
    rez *= 10;    
    rez += x%10;

    x/=10;
  }

  return rez;
}

int get(__int64 x, __int64 &l, __int64 &r)
{
  vector<char> nums;
  __int64 t=x ;
  while(t > 0)
  {
    nums.push_back(t%10);
    t/=10;
  }

  __int64 h = 1;

  int m = nums.size()/2;

  if(nums.size() % 2 != 0 )
    m++;

  for(int i=0; i<m; i++)
    h*=10;

  r = x % h;

  l=0;

  for(int i=m; i<nums.size(); i++)
  {
    l*=10;
    l+=nums[i];
  }

  return nums.size();
}

int main()
{
  int T;

  //ifstream in("test.in");
  //ofstream out("test.out");

  ifstream in("A-small-attempt4.in");
  ofstream out("A-small-attempt4.out");

  //ifstream in("A-large.in");
  //ofstream out("A-large.out");

  in >> T;

  for(int testCase=0; testCase<T; ++testCase)
  {
    __int64 solve = 0; 
    __int64 N;

    in >> N;

    __int64 x=N;
    //solve++;

    cout << N <<":";

    while(1)
    {

      cout << " " << x;
      if(x==1)
      {
        solve++;
        break;
      }

      if(x==9)
      {
        solve += 9;
        break;
      }

      if(x%10 == 0)
      {
        x--;
        solve++;
      }

      __int64 l, r;

      int size = get(x,l,r);

      solve += l-1 + r-1;

      if(l != 1)
        solve ++;

      solve += 2;

      x=9;

      for(int i=1; i<size-1;i++)
        x=x*10 + 9;
      
    }

    cout << endl;

    out << "Case #"<<testCase+1<<": ";

    out << solve << endl;
  }

  return 0;
}