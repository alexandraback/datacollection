#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 221212;

int L, X;
string s;

int arr[MAXN], prd[MAXN];

const int tab[4][4] = {
  { 1, 2, 3, 4},
  { 2,-1, 4,-3},
  { 3,-4,-1, 2},
  { 4, 3,-2,-1}
};

int mul(int a, int b)
{
  int res = tab[abs(a)-1][abs(b)-1];
  return res * (a<0 ? -1 : 1) * (b<0 ? -1 : 1);
}

bool solve()
{
  if(prd[L*X] != -1) return false;
  int state = 0;

  for(int i=1; i<=L*X; i++)
  {
    if(state == 0 && prd[i] == 2)
      state = 1;
    else if(state == 1 && prd[i] == 4)
      state = 2;
  }

  return state == 2;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    for(int tt=1; tt<=T; tt++)
    {
      long long lx;
      cin >> L >> lx >> s;
      if(lx > 12)
        X = (lx-12) % 4 + 12;
      else
        X = lx;

      for(int i=0; i<L*X; i++)
      {
        int j = i % L;
        if(s[j] == 'i')
          arr[i] = 2;
        else if(s[j] == 'j')
          arr[i] = 3;
        else if(s[j] == 'k')
          arr[i] = 4;
      }

      prd[0] = 1;

      for(int i=0; i<L*X; i++)
      {
        prd[i+1] = mul(prd[i], arr[i]);
      }
      
      bool res = solve();
      cout << "Case #" << tt << ": " << (res ? "YES" : "NO") << endl;
    }

    return 0;
}
