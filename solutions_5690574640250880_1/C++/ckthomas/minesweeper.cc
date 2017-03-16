#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  int Nprob;
  cin >> Nprob;
  for (int np=0; np<Nprob; np++)
  {
    int R, C, M;
    cin >> R >> C >> M;
    if (M == (R*C-1))
    {
      cout << "Case #" << np+1 << ":\nc";
      for (int i=1; i<C; i++)
        cout << "*";
      cout << "\n";
      for (int j=1; j<R; j++)
      {
        for (int i=0; i<C; i++)
          cout << "*";
        cout << "\n";
      }
      continue;
    }
    if (M == 0 && R == 1 && C == 1)
    {
      cout << "Case #" << np+1 << ":\nc\n";
      continue;
    }
    if (R == 1)
    {
      cout << "Case #" << np+1 << ":\n";
      if (M < C-1)
      {
        cout << "c";
        for (int i=0; i<C-M-1; i++)
          cout << ".";
        for (int i=0; i<M; i++)
          cout << "*";
        cout << "\n";
      }
      else
        cout << "Impossible\n";
      continue;
    }
    if (C == 1)
    {
      cout << "Case #" << np+1 << ":\n";
      if (M < R-1)
      {
        cout << "c\n";
        for (int i=0; i<R-M-1; i++)
          cout << ".\n";
        for (int i=0; i<M; i++)
          cout << "*\n";
      }
      else
        cout << "Impossible\n";
      continue;
    }
    int impossible = 1;
    for (int X=2; impossible && X<=C; X++)
      for (int Y=2; impossible && Y<=R; Y++)
      {
        int curM = M - (C*R-X*Y);
        if (curM < 0 || curM >= X || curM >= Y)
          continue;
        if (curM > 0 && (X == 2 || Y == 2))
          continue;
        if (X == 3 && Y == 3 && curM == 2)
          continue;
        if (X > Y)
        {
          cout << "Case #" << np+1 << ":\nc";
          for (int i=1; i<X; i++)
            cout << ".";
          for (int i=X; i<C; i++)
            cout << "*";
          cout << "\n";
          for (int j=1; j<Y-1; j++)
          {
            for (int i=0; i<X; i++)
              cout << ".";
            for (int i=X; i<C; i++)
              cout << "*";
            cout << "\n";
          }
          for (int i=0; i<X-curM; i++)
            cout << ".";
          for (int i=X-curM; i<C; i++)
            cout << "*";
          cout << "\n";
          for (int j=Y; j<R; j++)
          {
            for (int i=0; i<C; i++)
              cout << "*";
            cout << "\n";
          }
        }
        if (X < Y)
        {
          cout << "Case #" << np+1 << ":\nc";
          for (int i=1; i<X; i++)
            cout << ".";
          for (int i=X; i<C; i++)
            cout << "*";
          cout << "\n";
          for (int j=1; j<Y; j++)
          {
            for (int i=0; i<X-1; i++)
              cout << ".";
            if (j<Y-curM)
              cout << ".";
            else
              cout << "*";
            for (int i=X; i<C; i++)
              cout << "*";
            cout << "\n";
          }
          for (int j=Y; j<R; j++)
          {
            for (int i=0; i<C; i++)
              cout << "*";
            cout << "\n";
          }
        }
        if (X == Y)
        {
          cout << "Case #" << np+1 << ":\nc";
          for (int i=1; i<X; i++)
            cout << ".";
          for (int i=X; i<C; i++)
            cout << "*";
          cout << "\n";
          for (int j=1; j<Y; j++)
          {
            for (int i=0; i<X-2; i++)
              cout << ".";
            if (curM == Y-1 && j == Y-1)
              cout << "*";
            else
              cout << ".";
            if (j < 2 || j<Y-curM)
              cout << ".";
            else
              cout << "*";
            for (int i=X; i<C; i++)
              cout << "*";
            cout << "\n";
          }
          for (int j=Y; j<R; j++)
          {
            for (int i=0; i<C; i++)
              cout << "*";
            cout << "\n";
          }
        }
        impossible = 0;
      }
    if (impossible)
      cout << "Case #" << np+1 << ":\nImpossible\n";
  }
}
