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

#define file "B-small-attempt0"
const int N = 20;
                                                                                 
char p[N], t[N], keys[N];
int k, l, s;
int mx;

int cntBan()
{
  int ans = 0;
  for (int i = 0; i < s - l + 1; i++)
  {
    bool ok = true;
    for (int j = 0; j < l; j++)
      if (p[j] != t[i + j])
      {
        ok = false;
        break;
      }
    ans += ok;
  }

  return ans;
}

int doit(int step)
{
  if (step == s)
  {
  	int ans = cntBan();
  	mx = max(mx, ans);
  	return ans;
  }
  int ans = 0;
  for (int i = 0; i < k; i++)
  {
    t[step++] = keys[i];
    ans += doit(step);
    step--;
  }
  return ans;
}
                   
int main()
{
  freopen(file".in", "r", stdin);
  freopen(file".out", "w", stdout);

  int test;
  scanf("%d", &test);
  for (int t = 0; t < test; t++)
  {
    scanf("%d%d%d\n", &k, &l, &s);
    scanf("%s\n%s", keys, p);
    mx = 0;
    int ans = doit(0);
    printf("Case #%d: %.9lf\n", t + 1, mx - ans * 1.0 / pow(k, s));
  }


  return 0;
}