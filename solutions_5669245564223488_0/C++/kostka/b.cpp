#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

string L[17];
int P[17], wys[200];

string skrocslowo(string A)
{
  string B = "";
  B += A[0];
  for(int i=1; i<A.size(); i++)
    if(A[i] != A[i-1])
      B += A[i];
  return B;
}

int main()
{
  int ttt;
  cin >> ttt;
  for(int tti=1; tti<=ttt; tti++)
  {
    cout << "Case #" << tti << ": ";
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
      cin >> L[i];
      L[i] = skrocslowo(L[i]);
    }
    for(int i=0; i<n; i++)
      P[i] = i;
    long long wyn = 0;
    do
    {
      bool czy = true;
      string X = "";
      for(int i=0; i<n; i++)
        X += L[P[i]];
      for(int i='a'; i<='z'; i++)
        wys[i] = -1;
      //cout << X << "\n";
      for(int i=0; i<X.size(); i++)
      {
        if(wys[X[i]] == -1)
          wys[X[i]] = i;
        else if(wys[X[i]] == i-1)
          wys[X[i]] = i;
        else
        {
          czy = false;
          break;
        }
      }
      if(czy)
        wyn++;
        
    }while(next_permutation(P, P+n));
    cout << wyn << "\n";
  }
  return 0;
}