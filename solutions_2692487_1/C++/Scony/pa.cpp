#include <iostream>
#include <list>

using namespace std;

pair<int,long long> enbig(int thr, long long sum)
{
  int c = 0;
  while(sum<=thr)
    {
      sum += sum-1;
      c++;
    }

  return pair<int,long long>(c,sum);
}

int main(int argc, char ** argv)
{
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; tc++)
    {
      cout << "Case #" << tc << ": ";
      int a;
      int n;
      cin >> a >> n;
      list<int> x;
      int adds[n];
      for(int i = 0; i < n; i++)
	{
	  adds[i] = 0;//n - i - 1;
	  int tmp;
	  cin >> tmp;
	  x.push_back(tmp);
	}
      x.sort();

      long long sum = a;
      if(sum != 1)
	{
	  int j = 0;
	  for(list<int>::iterator i = x.begin(); i != x.end(); i++)
	    {
	      if(sum > *i)
		adds[j] = j > 0 ? adds[j-1] : 0;
	      else
		{
		  pair<int,long long> re = enbig(*i,sum);
		  sum = re.second;
		  adds[j] = j > 0 ? adds[j-1] + re.first : re.first;
		}
	      sum += *i;
	      j++;
	    }
	}
      else
	{
	  cout << n << endl;
	  continue;
	}

      int min = n;
      for(int i = 0; i < n; i++)
	if(adds[i]+n-i-1 < min)
	  min = adds[i]+n-i-1;
      
      //re
      cout << min << endl;
      //
    }
  return 0;
}
