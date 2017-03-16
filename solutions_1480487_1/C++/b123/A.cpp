#include <fstream>
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <cctype>
#include <algorithm>

using namespace std;

typedef unsigned long long Ullong;
typedef unsigned int uint;

int main()
{

  unsigned int T, N;
  double s;

  cin >> T;

  for (uint t = 0; t < T; t++)
  {
    cin >> N;
    
    vector< double > S (N,0);
    vector< double > S1;

    double X = 0;

    for (uint n = 0; n < N; n++)
    {
      cin >> s;
      S[n] = s;
      X += S[n];
    }

    S1 = S;
    sort (S.begin(),S.end());

    double Y = 1;
    double W = S[0];

    for (uint n = 1; n < N; n++)
    {
      if ( (S[n] - W) * n <= X * Y)
      {
        Y -= (S[n] - W) * n / X;
	W = S[n];
      }
      else
      {
        W += Y*X / double(n);
	Y = 0;
	break;
      }
    }
    W += Y*X / N;

    vector< double > ans (N,0);
    for (uint n = 0; n < N; n++)
    {
      ans[n] = (W-S1[n])/X * 100;
      if (ans[n] < 0)
	      ans[n] = 0;
    }

    cout << "Case #" << t+1 << ": ";
    for (uint n = 0; n < N-1; n++)
    {
      printf("%.6f ",ans[n]);
    }
    printf("%.6f",ans[N-1]);
    cout << endl;
  }
  return 0;
}

