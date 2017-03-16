#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <cmath>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i)
  {
    int N;
    cin >> N;
    vector<string> cars;
    copy_n(istream_iterator<string>(cin), N, back_inserter(cars));
    cout << "Case #" << i << ": ";
    int same[128] = {0};
    bool mid[128] = {0};
    char begin[128] = {0};
    char end[128] = {0};
    bool valid = true;
    for (int j = 0; j < N; ++j)
    {
      for (int k = 0; k < cars[j].length(); ++k)
      {
	if (cars[j][k] != cars[j][0])
	{
	  if (begin[cars[j][0]] || end[cars[j][cars[j].length()-1]])
	    valid = false;
	  begin[cars[j][0]] = cars[j][cars[j].length()-1];
	  end[cars[j][cars[j].length()-1]] = cars[j][0];
	  break;
	}
	else if (k == cars[j].length()-1)
	  ++same[cars[j][k]];
      }
      char last = cars[j][0];
      for (int k = 1; k < cars[j].length()-1; ++k)
      {
	if (cars[j][k] != last && cars[j][k] != cars[j][k+1])
	{
	  last = cars[j][k];
	  if (cars[j][0] == cars[j][cars[j].length()-1])
	    valid = false;
	  if (mid[cars[j][k]] || begin[cars[j][k]] || end[cars[j][k]] || same[cars[j][k]])
	    valid = false;
	  mid[cars[j][k]] = true;
	}
      }
    }
     //1   N!    1
    //end same begin
    if (!valid)
    {
      cout << "0" << endl;
      continue;
    }
    int num = 1;
    int segs = 0;
    int used = 0;
    for (char c = 'a'; c <= 'z'; ++c)
    {
      //cout << c << " " << begin[c] << " " << same[c] << " " << end[c] << endl;
      // try to do segs
      if (end[c])
	continue;
      if (begin[c])
      {
	char x = c;
	while (begin[x])
	{
	  used += same[x];
	  for (int j = 1; j <= same[x]; ++j)
	  {
	    num *= j;
	    num %= 1000007;
	  }
	  char t = begin[x];
	  used += same[t]+1;
	  for (int j = 1; j <= same[t]; ++j)
	  {
	    num *= j;
	    num %= 1000007;
	  }
	  begin[x] = 0;
	  same[x] = 0;
	  same[t] = 0;
	  x = t;
	}
	++segs;
      }
      else if (same[c])
      {
	used += same[c];
	for (int j = 1; j <= same[c]; ++j)
	{
	  num *= j;
	  num %= 1000007;
	}
	++segs;
      }
    }
    for (int j = 1; j <= segs; ++j)
    {
      num *= j;
      num %= 1000007;
    }
    if (used != N)
      cout << "0" << endl;
    else
      cout << num << endl;
  }
  return 0;
}
