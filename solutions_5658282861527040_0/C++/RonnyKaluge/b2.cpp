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

int max(int a, int b)
{
  if (a < b) return b;;
  return a;
}

int main()
{
  int i, j, T, A, B, K;
  cin >> T;
  for (int t=1; t<=T; ++t)
  {
    cin >> A >> B >> K;
    int result = 0;
    for (i=0; i<A; ++i)
      for (j=0; j<B; ++j)
        if ((i & j) < K) ++result;
    cout << "Case #" << t << ": " << result << endl;
  }
	return 0;
}
