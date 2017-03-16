#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

inline long long min(long long a, long long b)
{
  return a < b ? a : b;
}

inline long long max(long long a, long long b)
{
  return a > b ? a : b;
}

struct event
{
  event()
    :id(0), val(0) {}
  int id;
  long long val;
};

bool comp(event e1, event e2)
{
  return e1.val < e2.val;
}

int main()
{
  int cnt;
  cin >> cnt;
  for(int i = 0; i < cnt; ++i)
    {
      cout << "Case #" << i+1 << ": ";
      long long e, r, N;
      cin >> e >> r >> N;
      vector<event> eve(N);
      for(int j = 0; j < N; ++j)
	{
	  cin >> eve[j].val;
	  eve[j].id = j;
	}
      sort(eve.begin(), eve.end(), comp);
      reverse(eve.begin(), eve.end());
      vector<long long> upper(N, e);
      vector<long long> lower(N, 0);
      long long sum = 0;
      for(int j = 0; j < eve.size(); ++j)
	{
	  long long pos = eve[j].id;
	  long long cost = (upper[pos]-lower[pos]);
	  sum += cost*eve[j].val;
	  long long left = upper[pos]-r;
	  for(int k = pos-1; left > 0 && k >=0; --k)
	    {
	      if(lower[k] < left)
		{lower[k] = left;}
	      left-=r;
	    }
	  long long right = lower[pos]+r;
	  for(int k = pos+1; right < e && k < N; ++k)
	    {
	      if(upper[k] > right)
		{upper[k] = right;}
	      right += r;
	    }
	}
      cout << sum << endl;
    }
}
