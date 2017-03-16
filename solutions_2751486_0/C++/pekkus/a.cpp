#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF 100000000

bool isConsonant(char c)
{
  if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c) return false;
  return true;
}

int main()
{
  int T; cin >> T;
  for(int test_case = 1; test_case <= T; ++test_case)
  {
    string L; int n;
    cin >> L >> n;
    int N = L.size();
    ll res = 0;
    vi starts_n_consecutive_consonants(N, 0);
    for(int start = 0; start + n - 1 < N; ++start)
    {
      bool ok = true;
      for(int i = 0; i < n; ++i)
      {
        ok &= isConsonant(L[start + i]);
      }
      if (ok) starts_n_consecutive_consonants[start] = 1;
    }
    int start = 0;
    for(int i = 0; i < N; ++i)
    {
      if (starts_n_consecutive_consonants[i])
      {
        res += i - start;
        res += N - (i + n) + 1;
        res += (i - start) * (N - (i + n));
        start = i + 1;
      }
      //cout << i << " " << res << endl;
    }
    printf("Case #%d: %d\n", test_case, res);
  }
}

