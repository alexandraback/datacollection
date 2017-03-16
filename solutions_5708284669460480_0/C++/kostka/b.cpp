#include "bits/stdc++.h"

using namespace std;

int k, l, s;
vector <char> X;
string a, b;
vector <int> S;

void go(int c)
{
  if(c==s)
  {
    int ile = 0;
    for(int i=0; i<=X.size()-b.size(); i++)
    {
      bool czy = true;
      for(int j=0; j<b.size(); j++)
        if(b[j]!=X[i+j])
          czy = false;
      if(czy)
        ile++;
    }
    S.push_back(ile);
    return;
  }
  for(int i=0; i<a.size(); i++)
  {
    X.push_back(a[i]);
    go(c+1);
    X.pop_back();
  }
}

void test()
{
  cin >> k >> l >> s;
  cin >> a >> b;
  S.clear();
  go(0);
  sort(S.begin(), S.end());
  double ile = 0;
  for(auto ele : S)
    ile += ele;
  double res = 1.0 * S.back() - (1.0 * ile) / (int)S.size();
  cout << res;
}

int main()
{
  cout << fixed << setprecision(15);
  int t;
  cin >> t;
  for(int tti=1; tti<=t; tti++)
  {
    cout << "Case #" << tti << ": ";
    test();
    cout << "\n";
  }
}
