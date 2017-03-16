#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
  {
    int X, R, C;
    cin >> X >> R >> C;
    bool winPick = false;
    bool done = false;
    
    if (R > C)
    {
      int aux = R;
      R = C;
      C = aux;
    }
    
    if (X >= 7) 
    {
      winPick = true;
      done = true;
    }   
    
    if (R*C % X != 0)
    {
      winPick = true;
      done = true;
    }
    
    if (R < X and C < X)
    {
      winPick = true;
      done = true;
    }
    
    if (X == 1)
    {
      winPick = false;
      done = true;
    }
    
    if (X == 2)
    {
      if (R*C % X != 0) winPick = true;
      done = true;
    }
    
    if (X == 4 and !done)
    {
      if (R <= 2)
      {
        winPick = true;
        done = true;
      }
      else
      {
        winPick = false;
        done = true;
      }
    }
    
    if (X == 3 and !done)
    {
      winPick = false;
      done = true;
    }
    
    int squaryFigureSize = (X - 1)/2 + 1;
    if (R < squaryFigureSize)
    {
      winPick = true;
      //cout << "SS: " << X << " " << R << " " << C << endl;
      done = true;
    }
    
    if (!done) cout << "Case #" << t << ": NOT DONE " << X << " " << R << " " << C << endl;
    if (winPick) cout << "Case #" << t << ": RICHARD" << endl;
    else cout << "Case #" << t << ": GABRIEL" << endl;
  }
  return 0;
}








