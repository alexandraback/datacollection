#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

#define x first 
#define y second
#define mp make_pair
#define pb push_back
#define sz(v) (int)(v).size()
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int)(2e9);
const ld eps = 1e-12;

#define file "C-small-attempt0"
const int N = 500;

int ds[N];
bool was[N];
                     
int main()
{
  freopen(file".in", "r", stdin);
  freopen(file".out", "w", stdout);

  int test;
  scanf("%d", &test);
  for (int t = 0; t < test; t++)
  {
    int c, d, v;
    scanf("%d%d%d", &c, &d, &v);
    for (int i = 1; i <= v; i++)
    	was[i] = false;
    for (int i = 0; i < d; i++)
    	scanf("%d", &ds[i]);

    was[0] = true;
    for (int i = 0; i < d; i++)
    	for (int w = v; w >= 0; w--)
    	  was[w + ds[i]] |= was[w];

    bool ok = false;
    int ans = 0;
    while (!ok)
    {
      ok = true;
      int id = -1;
      for (int i = 0; i <= v; i++)
      	if (!was[i])
      	{
      	  ok = false;
      	  id = i;
      	  break;
      	}
      if (!ok) 
      {
        ds[d++] = id;
        ans++;
        for (int i = 1; i <= v; i++)
          was[i] = false;
        for (int i = 0; i < d; i++)
    			for (int w = v; w >= 0; w--)
    	   		was[w + ds[i]] |= was[w];
      }	
    }

    printf("Case #%d: %d\n", t + 1, ans);
  }

  return 0;
}