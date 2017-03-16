#include <iostream>
#include <vector>

using namespace std;

void solve_case();

int main()
{
   int N = 0;
   cin >> N;
   for (int i = 0; i < N; ++ i)
   {
      cout << "Case #" << i + 1 << ":";
      solve_case();
      cout << '\n';
   }

   return 0;
}

int index(int C, int i, int j)
{
   return C * i + j;
}

void print(vector<char> & data, int R, int C)
{
   data[0] = 'c';
   for(int i = 0; i < R; ++ i)
   {
      cout << '\n';
      for(int j = 0; j < C; ++ j)
      {
         cout << data[index(C, i, j)];
      }
   }
}

void solve_case()
{
   int R = 0;
   int C = 0;
   int M = 0;

   cin >> R;
   cin >> C;
   cin >> M;

   int T = R * C;

   vector<char> data(T, '*');

   if (R == 1 || C == 1)
   {
      for(int i = 1; i < T - M; ++ i)
         data[i] = '.';
      print(data, R, C);
      return;
   }

   int S = T - M;

   if (S == 1)
   {
      print(data, R, C);
      return;
   }

   if (S == 2 || S == 3 || S == 5 || S == 7)
   {
      cout << '\n' << "Impossible";
      return;
   }

   if (R == 2)
   {
      if ( M & 1)
      {
         cout << '\n' << "Impossible";
      }
      else
      {
         int c = S >> 1;
         for(int i = 0; i < R; ++ i)
            for(int j = 0; j < c; ++j)
            {
               data[index(C, i, j)] = '.';
            }
         print(data, R, C);
      }
      return;
   }

   if (C == 2)
   {
      if ( M & 1)
      {
         cout << '\n' << "Impossible";
      }
      else
      {
         int r = S >> 1;
         for(int i = 0; i < r; ++ i)
            for(int j = 0; j < C; ++j)
            {
               data[index(C, i, j)] = '.';
            }
         print(data, R, C);
      }
      return;
   }

   {
// R >= 3 and C >= 3 and S >= 8 || S = 4, 6
// It is always possible for such arrangement

      int r = 2;

      while ( r < R && r < C && (r+1) * (r+1) <= S) ++ r;

      int c = r;

      if (r < R && r * (r+1) <= S) r = r + 1;

      if (r == R) c = S / r;
      else if (c == C) r = S/C;

      int remainder = S - c * r;

      for(int i = 0; i < r; ++ i)
      {
         for(int j = 0; j < c; ++ j)
         {
            data[index(C, i, j)] = '.';
         }
      }
      if (r == R)
      {
         for(int i = 0; i < remainder; ++ i)
         {
            data[index(C, i, c)] = '.';
         }
         if (remainder == 1)
         {
            data[index(C, 1, c)] = '.';
            data[index(C, r-1, c-1)] = '*';
         }
      }
      else
      {
         for(int j = 0; j < remainder; ++ j)
         {
            data[index(C, r, j)] = '.';
         }
         if (remainder == 1)
         {
            data[index(C, r, 1)] = '.';
            data[index(C, r-1, c-1)] = '*';
         }
      }

   }
   print(data, R, C);
}
