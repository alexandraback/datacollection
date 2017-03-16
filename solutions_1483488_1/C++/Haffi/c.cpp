#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int intPow(int x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = intPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

int main(){
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int cases;
  cin >> cases;
  for(int i=0; i<cases; ++i)
  {
    cout << "Case #" << i+1 << ": ";
    int A,B; cin >> A >> B;
    int sum = 0;
    if(B>=A && B>=0)
    {
      int k = B, digitsOfB = 0;
      while(k>0)
      {
        digitsOfB++;
        k = k/10;
      }
      int lowerbound = max(A,0);
      for(int j=lowerbound; j<=B; ++j)
      {
        k = j;
        int digits = 0;
        while(k>0)
        {
          digits++;
          k = k/10;
        }
        if(digits == digitsOfB)
        {
          set<int> done;
          // Possibility of recycled pairs
          for(int k=1; k<digits; ++k)
          {
            int l = j%intPow(10,k); // Latter part
            int m = intPow(10,digits-k)*l + j/intPow(10,k);
            if(done.count(m)==0 && m>j && m<=B)
            {
              sum++;
              done.insert(m);
            }
          }
        }
      }
    }
    cout << sum << "\n";
  }
  return 0;
}