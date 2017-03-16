#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(const vector<int>& vec, int a)
{
  int ans=0;
  for(int i = 0; i<vec.size(); ++i)
    {
      if(vec[i]<=a)
	{continue;}
      ans+=(vec[i]-1)/a;
    }
  return ans+a;
}

int main()
{
  int cnt;
  cin >> cnt;
  for(int i = 0; i < cnt; ++i)
    {
      int D;
      vector<int> vec;
      cin >> D;
      for(int j = 0; j < D; ++j)
	{
	  int temp;
	  cin >> temp;
	  vec.push_back(temp);
	}
      sort(vec.begin(), vec.end());
      int ans=1000000;
      for(int avg=1; avg<=vec.back(); ++avg)
	{
	  ans=min(ans,check(vec, avg));
	}
      cout << "Case #" << i+1 << ": " << ans << endl;
    }
}
