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

int h[2100000];
int n, a, b;

inline void rotate(int a)
{
  int p = 1;
  while(10 * p <= a)
    p *= 10;
  for(int c = (a / 10) + ((a % 10) * p); c != a; c = (c / 10) + ((c % 10) * p))
    ++h[c];
}

int main() 
{
  freopen("ic.txt", "r", stdin);
  freopen("oc.txt", "w", stdout);
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    memset(h, 0, sizeof(h));
    cin >> a >> b;
    int cnt = 0;
    for(int c = a; c <= b; c++)
    {
      cnt += h[c];
      rotate(c);
    }
    cout << "Case #" << (i + 1) << ": " << cnt << endl;
  }
  return 0;
}
