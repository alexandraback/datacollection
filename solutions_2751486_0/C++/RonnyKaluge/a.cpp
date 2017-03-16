#include <iostream>
#include <stack>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

#define A first
#define B second

bool name[1000000];
bool Q[1000000];

bool isVocal(char c)
{
  return c=='a' || c=='i' || c=='u' || c=='e' || c=='o';
}

int main()
{
  int i, j, k, total, idx, length, n, T, last;
  long long result;
  char c;
  cin >> T;
  for (int t=1; t<=T; ++t)
  {
    length = 0;
    while (scanf("%c", &c)!=EOF && (c > 'z' || c < 'a'));
    do
    {
      name[length++] = !isVocal(c);
    }
    while (scanf("%c", &c)!=EOF && (c <= 'z' && c >= 'a'));
    cin >> n;
    idx = 0;
    total = 0;
    for (i=0; i<n; ++i)
    {
      Q[i] = name[i];
      if (name[i])
        ++total;
    }
    // cout << " " << idx << " " << total << " " << n << endl;
    if (n==total)
    {
      result = (long long)(length-n+1);
      last = 1;
      j = 1;
    }
    else
    {
      result = 0LL;
      last = 0;
      j = 0;
    }
    for (i=n; i<length; ++i)
    {
      if (name[i])
        ++total;
      if (Q[idx])
        --total;
      Q[idx] = name[i];
      if (n == total)
      {
        ++j;
        // cout << length-i << " " << i-n+2-last << " " << i << endl;
        result += (long long)(length-i) * (long long) (i-n+2-last);
        last = i-n+2;
      }
      if (++idx >= n)
        idx=0;
    }
    printf("Case #%d: %d\n", t, result);
  }
	return 0;
}
