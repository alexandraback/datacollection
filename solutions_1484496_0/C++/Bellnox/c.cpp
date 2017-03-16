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

int n;
int a[512];
map<int, set<int> > ss;
int ps[2 << 22];

void print(int v)
{
  for(int i = 0; i < n; i++)
  {
    if((v & (1 << i)) != 0)
      cout << a[i] << " ";
  }
}

int main() 
{
  freopen("ic.txt", "r", stdin);
  freopen("oc.txt", "w", stdout);
  int tt;
  cin >> tt;
  for(LL t = 0; t < tt; t++)
  {
    memset(ps, 0, sizeof(ps));
    ss.clear();
    cout << "Case #" << (t + 1) << ":";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < (1 << i); j++)
      {
	ps[j + (1 << i)] = ps[j] + a[i];
	ss[ps[j] + a[i]].insert(j + (1 << i));
      }
    }
    bool has = 0;
    for(map<int, set<int> >::iterator it = ss.begin(); it != ss.end() && !has; it++)
    {
      for(set<int>::iterator s1 = it->second.begin(); s1 != it->second.end() && !has; s1++)
      {
	for(set<int>::iterator s2 = it->second.begin(); s2 != it->second.end() && !has; s2++)
	{
	  if(((*s1) & (*s2)) == 0)
	  {
	    has = 1;
	    cout << endl;
	    print(*s1);
	    cout << endl;
	    print(*s2);
	  }
	}
      }
    }
    if(!has)
    {
      cout << endl << "Impossible";
    }
    cout << endl;
  }
  return 0;
}
