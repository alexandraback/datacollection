#include "bits/stdc++.h"

using namespace std;

int tab[30007][30007];

int s(char x)
{
  switch(x)
  {
    case 'i':
      return 2;
    case 'j':
      return 3;
    case 'k':
      return 4;
  }
}

char mul(int a, int b)
{
  if(abs(a)==1 or abs(b)==1)
    return a*b;
  int znak = (a>0 ? 1 : -1) * (b>0 ? 1 : -1);
  a = abs(a);
  b = abs(b);
  if(a==b)
    return znak*-1;
  if(a==2 and b==3)
    return znak*4;
  if(a==2 and b==4)
    return znak*-3;
  if(a==3 and b==2)
    return znak*-4;
  if(a==3 and b==4)
    return znak*2;
  if(a==4 and b==2)
    return znak*3;
  if(a==4 and b==3)
    return znak*-2;
  cerr << a << " " << b << "\n";
  throw runtime_error( "you forgot about something!" );
}

string test()
{
  int n, k;
  cin >> n >> k;
  string x;
  cin >> x;
  string w = "";
  for(int i=0; i<k; i++)
    w += x;
  n = w.size();
  for(int i=0; i<n; i++)
  {
    int znak = 1;
    for(int j=i; j<n; j++)
    {
      znak = mul(znak, s(w[j]));
      tab[i][j] = znak;
    }
  }
  for(int i=0; i<n; i++)
    for(int j=i+2; j<n; j++)
      if(tab[0][i] == 2 and tab[i+1][j-1] == 3 and tab[j][n-1] == 4)
      {
        //cerr << "[" << 0 << " " << i << "] ";
        //cerr << "[" << i+1 << " " << j-1 << "] ";
        //cerr << "[" << j << " " << n-1 << "] ";
        return "YES";
      }
  return "NO";
}

int main()
{
  int t;
  cin >> t;
  for(int tti=1; tti<=t; tti++)
    cout << "Case #" << tti << ": " << test() << "\n";
}
