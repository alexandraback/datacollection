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

bool explore (vector< vector <uint> >& A, vector< int >& B, int color, int n)
{
  vector<uint>::iterator ait;
  bool isDia = false;
  
  for (ait = A[n].begin(); ait < A[n].end(); ait++)
  {
    if (B[*ait] != color)
    {
      B[*ait] = color;
      isDia = explore (A, B, color, *ait);
    }
    else if (B[*ait] == color)
    {
      isDia = true;
    }
    if (isDia == true)
      break;
  }
  return isDia;
  
}

int main()
{

  uint T, N, M;

  cin >> T;

  for (uint t = 0; t < T; t++)
  {
    cin >> N;
    
    vector< vector< uint > > A;

    for (uint n = 0; n < N; n++)
    {
      cin >> M;

      vector< uint > a;
      for (uint m = 0; m < M; m++)
      {
        uint temp;
        cin >> temp;
        a.push_back(temp-1);   // label 0 to N-1
      }
      
      A.push_back(a);
    }

    vector< int > B (N,-1);

    bool isDia = false;

    for (uint n = 0; n < N; n++)
    {
      isDia = explore (A, B, n, n);
      if (isDia == true)
        break;
    }

    cout << "Case #" << t+1 << ": ";
    if (isDia == true)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}

