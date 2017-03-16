#include <iostream>
#include <vector>
#include <cstdio>
#define forn(i,n) for(int i = 0; (i) < (int) (n); i++)
typedef long long tint;
using namespace std;

int main()
{
#ifdef ACMTUYO
  freopen("D-small-attempt0.in", "r", stdin);
  freopen("D-small-attempt0.out", "w", stdout);
#endif

	int T;
  cin >> T;
  forn(tc,T)
  {
    tint K, C, S;
    cin >> K >> C >> S;
    if(K > S * C)
    {
      cout << "Case #" << tc+1 << ": " << "IMPOSSIBLE" << "\n";
      continue;
    }
    
    vector<tint> ans;
    int s = 0;
    forn(i, K)
    {
      if(i%C == 0)
      {
        ans.push_back(0);
        s++;
      }
      
      ans[s-1] = ans[s-1] * K + i;
    }
    
    cout << "Case #" << tc+1 << ":";
    forn(i, s) cout << " " << ans[i]+1;
    cout << "\n";
  }
}
