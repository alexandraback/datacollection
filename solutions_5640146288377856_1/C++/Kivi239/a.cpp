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

#define file "A-large"
const int N = 100500;
                     
int main()
{
  freopen(file".in", "r", stdin);
  freopen(file".out", "w", stdout);

  int test;
  cin >> test;
  for (int t = 0; t < test; t++)
  {
    int r, c, w;
    cin >> r >> c >> w;
    int ans = c / w;
    ans += w;
    if (c % w == 0)
    	ans--;
    printf("Case #%d: %d\n", t + 1, ans * r);
  }

  return 0;
}