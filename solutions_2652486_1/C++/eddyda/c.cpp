#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
using namespace std;
#define ulli unsigned long long int


int main()
{
  freopen("C-small-2-attempt1.in", "rt", stdin);
  freopen("C-small-2-attempt1.out", "wt", stdout);

  int T;
  int R, N, M, K;
  cin>>T;
  for (int c=1; c<=T; c++)
  {
    printf("Case #%d:\n", c);
    cin>>R>>N>>M>>K;
    for (int r = 0; r < R; ++r)
    {
      int power[M+1]; 
      for (int m = 2; m <= M; ++m) 
        power[m] = 0;
   
      for (int k = 0; k < K; ++k)
      {
        int pk;
        cin>>pk;
        for (int d = 2; d <= M; ++d)
        { 
          int p = pk;
          int pow = 0;
          while (p > 0)
          {
            if (p%d == 0)
            {
              pow++;
              p /= d;
            }
            else break;
          }
          if (pow > power[d]) power[d] = pow;
        }
      }

/*
      for (int m = 2; m <= M; ++m)
        cout<<power[m]<<endl;
*/

      //now we have the max power of each digit, make a guess
      //from large to small
      int count = 0;
      int guess[N];
      for (int n = 0; n < N; ++n)
        guess[n] = 2;

      int digit = M;
      while (count < N && digit >= 2) 
      {
        if (power[digit])
        {  
          guess[count] = digit;
          power[digit]--;
          count++;
        }
        else digit--;
      }         

      for (int n = count; n < N; ++n)
        guess[n] = rand()%(M-1)+2;

      //print result
      for (int n = 0; n < N; ++n)
        printf("%d", guess[n]);

      printf("\n");
      

    }

  }
}
