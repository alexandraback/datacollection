#include <iostream>
using namespace std;


int inherits(int ** t, int X, int Y)
{
  int count = 0;
  int l = t[X-1][0];
  for(int i = 1; i<l+1; i++)
  {
    if(t[X-1][i] == Y)
      count++;
    if(count>=2) return count;
  }

  
  for(int i = 1; i<l+1; i++)
  {
    count += inherits(t,t[X-1][i],Y);
    if(count>=2) return count;
  }  
  return count;
}


bool result(int **t, int n, int X)
{
  for(int i = 1; i<=n; i++)
  {
    if(i==X) continue;
    if(inherits(t,X,i)>=2) return true;
  }
  return false;
}

int inp()
{
  int r;
  cin >> r;
  return r;
}
int main()
{
  int cases;
  cin >>cases;
  for(int cas = 0; cas<cases; cas++)
  {
    int n = inp();
    int* t[n];
    for(int cl = 0; cl<n; cl++)
    {
      int l = inp();
      t[cl] = new int[l+1];
      t[cl][0] = l;
      for(int k = 1; k<=l; k++) t[cl][k] = inp(); 
    } 
    bool flag = false;
    for(int cl = 0; cl<n; cl++)
    {
      flag = result(t,n,cl);
      if(flag) break;
    }
    cout << "Case #" << cas+1 << ": ";
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    
    for(int cl = 0; cl<n; cl++)
      delete[] t[cl];
  }
  return 0;
}