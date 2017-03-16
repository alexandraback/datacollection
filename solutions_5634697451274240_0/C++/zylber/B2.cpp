#include <iostream>
#include <vector>
#include <cstdio>
#define forn(i,n) for(int i = 0; (i) < (int) (n); i++)
using namespace std;

int main()
{
#ifdef ACMTUYO
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);
#endif

	int T;
  cin >> T;
  forn(tc,T)
  {
    int ans = 0;
    string s;
    cin >> s;
    s += "+";
    forn(i, s.size()-1)
    {
      if(s[i]!=s[i+1]) ans++;
    }
    cout << "Case #" << tc+1 << ": " << ans << "\n";
  }
}
