#include <iostream>
#include <map>
#include <set>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <memory.h>
#include <math.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;

int n, s, p, t, v;

int main() 
{
  freopen("ib.txt", "r", stdin);
  freopen("ob.txt", "w", stdout);
  cin >> t;
  for(int tt = 0; tt < t; tt++)
  {
    cin >> n >> s >> p;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
      cin >> v;
      if(p == 0)
	++cnt;
      else if(p == 1)
      {
	if(v > 0)
	  ++cnt;
      }
      else
      {
	if(v >= 3 * p - 2)
	  cnt++;
	else if(v >= 3 * p - 4 && s > 0)
	{
	  --s;
	  ++cnt;
	}
      }
    }
    cout << "Case #" << (tt + 1) << ": " << cnt << endl;
  }
  return 0;
}
