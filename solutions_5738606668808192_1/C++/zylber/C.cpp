#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#define forn(i,n) for(int i = 0; (i) < (int) (n); i++)
typedef long long tint;
#define MAXD 100
using namespace std;

string binarize(tint n)
{
  string rans;
  while(n > 0)
  {
    rans += '0' + n%2;
    n /= 2;
  }
  reverse(rans.begin(), rans.end());
  return rans;
}

int main()
{
#ifdef ACMTUYO
  freopen("C-large.in", "r", stdin);
  freopen("C-large.out", "w", stdout);
#endif

  int T;
  cin >> T;
  forn(tc,T)
  {
    int N, J;
    cin >> N >> J;
    tint k = (1LL << (N -1)) + 1;
    vector<pair<string, vector<tint> > > ans;
    int found = 0;
    while(found < J)
    {
      vector<tint> primes;
      for(tint b = 2; b <= 10; b++)
      {
        tint d;
        for(d = 2; d < MAXD; d++)
        {
          tint p = 1, r = 0;
          forn(i, N)
          {
            if(k & (1<<i)) r = (r + p) % d;
            p = (p * b) % d;
          }
          
          if(r == 0)
          {
            primes.push_back(d);
            break;
          }
        }
        if(d == MAXD) break;
      }
      if(primes.size() == 9)
      {
        ans.push_back(make_pair(binarize(k), primes));
        found++;
      }
      k += 2;
    }
    cout << "Case #" << tc+1 << ": " << "\n"; 
    forn(i, J)
    {
      cout << ans[i].first;
      forn(j, 9)
      {
        cout << " " << ans[i].second[j];
      }
      cout << "\n";
    }
  }

}
