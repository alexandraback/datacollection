#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int digit(const int n)
{
  int m = n;
  int nbDigit = 0;
  while(m > 0)
  {
    m = m /10;
    ++ nbDigit;
  }
  return nbDigit;
}

int power(const int base, const int exponent)
{
  int r = 1;
  for(int i = 0; i < exponent; ++i)
  {
    r = r * base;
  }
  return r;
}

int n_factorial(const int n)
{
  int r = 1;
  for(int i = 1; i <= n; ++i)
  {
    r = r * i;
  }
  return r;
}

int nCombi(const int i)
{
  if(1 == i) {
    return 1;
  } else if(2 == i) {
    return 1;
  }
  int a = n_factorial(i);
  int b = n_factorial(i - 2);
  int r = a / b / 2;
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for(int tc = 1; tc <= T; ++ tc)
  {
    int A;
    int B;
    scanf("%d %d", &A, &B);
    //printf("Case #%d: %d %d\n", tc, A, B);
    int nbBDigit = digit(B);
    int shift = nbBDigit - 1;
    int shiftPower = power(10, shift);
    set<int> nSet;
    int total = 0;
    for(int n = A; n <= B; ++n) {
      int nn = n;
      set<int>::iterator it = nSet.find(nn);
      if(nSet.end() != it) {
        continue;
      }
      int nbNN = 1;
      for(int d = 1; d < nbBDigit; ++d)
      {
        int q = nn / 10;
        int r = nn % 10;
        bool da = false;
        bool db = false;
        nn = r * shiftPower + q;
        if(nn == n) {
          break;
        }
        if(nn < A) {
          continue;
        }
        if(nn > B) {
          continue;
        }
        //printf("%d ", nn);
        nSet.insert(nn);
        ++ nbNN;
      }
      if(nbNN > 1) 
      {
        nbNN = nCombi(nbNN);
        //printf("%d : %d\n", n, nbNN);
        total += nbNN;
      }
    }
    //printf("total %d\n", total);
    printf("Case #%d: %d\n", tc, total);
  }
}
