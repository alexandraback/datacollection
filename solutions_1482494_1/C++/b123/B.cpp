#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <cctype>
#include <algorithm>

using namespace std;

typedef unsigned long long Ullong;
typedef unsigned int uint;

bool func(vector<uint> a, vector<uint> b)
{
  return (a[1] > b[1]);
}

int main()
{

  uint T, N;

  cin >> T;

  for (uint t = 0; t < T; t++)
  {
    cin >> N;

    vector<vector<uint> > S;

    for (uint n = 0; n < N; n++)
    {
      vector<uint> s (3,0);
      cin >> s[0] >> s[1];

      S.push_back(s);
    }

    sort(S.begin(), S.end(), func);
    
    bool done = false;
    uint y = 0;
    uint stars = 0;

    while (!done) 
    {
      bool turndone = false;
      for (uint n = 0; n < N; n++)
      {
        if ((S[n][1] <= stars) && (S[n][2] < 2))
        {  
          stars += 2 - S[n][2];
          S[n][2] = 2;
          y++;
          turndone = true;
        }
      }
      if (!turndone)
      {
        for (uint n = 0; n < N; n++)
        {
          if ((S[n][0] <= stars) && (S[n][2] < 1))
          {
            stars++;
            S[n][2] = 1;
            y++;
            turndone = true;
            break;
          }
        }
      }
      if (!turndone)
        break;
      if (stars == 2*N)
        done = true;
    }
      
    if (done)
      cout << "Case #" << t+1 << ": " << y << endl;
    else
      cout << "Case #" << t+1 << ": Too Bad" << endl;
  }
  return 0;
}

