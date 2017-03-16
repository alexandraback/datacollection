#include <iostream>
#include <vector>
#include <cstdio>
#define forn(i,n) for(int i = 0; (i) < (int) (n); i++)
using namespace std;

void addDigits(vector<int>& seen, int act, int& tot)
{
  while(act > 0)
  {
    if(!seen[act%10])
    {
      seen[act%10] = 1;
      tot++;
    }
    act /= 10;
  }
}

int main()
{
#ifdef ACMTUYO
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
#endif

	int T;
  cin >> T;
  forn(tc,T)
  {
    int N;
    cin >> N;
    if(N == 0)
    {
      cout << "Case #" << tc+1 << ": " << "INSOMNIA" << "\n";
      continue;
    }
    vector<int> seen(10, 0);
    int tot = 0, act = N;
    while(tot < 10)
    {
      addDigits(seen, act, tot);
      act += N;
    }
    cout << "Case #" << tc+1 << ": " << act-N << "\n";
  }
}
