#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back

#define REP(i,n) for(int i=0; i < (n); ++i)

typedef long long ll;

using namespace std;


void solve()
{ 
  ll r, t;
  ll r2;
  cin >> r >> t;
  r2 = r+1;

  int n = 0;
  /*
  while(t > (2 * r - 1) && r > 0) {
    ++n;
    t -= (2 * r -1);
    r -= 2;
  }
  */
  while(t >= (2 * r2 - 1)) {
    ++n;
    t -= (2 * r2 - 1);
    r2 += 2;
  }

  cout << n << endl;
}

int main(int argc, char *argv[])
{
  int t;
  cin >> t;
  string ee;
  getline(cin,ee);

  for(int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}

