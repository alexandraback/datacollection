#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <random>
#include <cmath>
#include <ctime>
#include <map>

using namespace std;

#define RA(x) (x).begin(), (x).end()
#define SZ(x) ((int) (x).size())

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


long long nChoosek( long long n, long long k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    long long result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

double solve()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    if (X < 0)
      X = -X;
    int t = X + Y;
    int p1 = (t-2)*(t-2)/2 + 3*(t-2)/2 + 1;
    int p2 = t*t/2 + 3*t/2 + 1;
    if (N < p1)
      return 0;
    if (N >= p2)
      return 1;
    N -= p1;
    double ans=0;
    if (Y == t)
    {
      if (N == 2*t+1)
        return 1;
      else
        return 0;
    }
    if((N-t)>(Y+1))
      return 1;
    for(int i=Y+1; i<=N; ++i) {
      ans+=nChoosek(N, i);
    }
    ans /= (1<<N);
    return ans;
}

int main()
{
  int cases;
  cin >> cases;

  for (int cas = 1; cas < cases+1; cas++) {
    double ans = solve();
    printf("Case #%d: %f\n", cas, ans);
  }

  return 0;
}
