#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<fstream>
#define MAXN 20
#define INF 10000
using namespace std;
int mas[MAXN][MAXN];
long long gcd(long long a, long long b)
{
    if (b == 0)
      return a;
    return gcd(b, a % b);
}
int dfs(int cj, int ci, int n, int m)
{
    mas[cj][ci] = 2;
    if (cj + 1 < n && !mas[cj + 1][ci])
      dfs(cj + 1, ci, n, m);
    if (ci + 1 < m && !mas[cj][ci + 1])
      dfs(cj, ci + 1, n, m);
    if (cj - 1 >= 0 && !mas[cj - 1][ci])
      dfs(cj - 1, ci, n, m);
    if (ci - 1 >= 0 && !mas[cj][ci - 1])
      dfs(cj, ci - 1, n, m);
}
int solve(int n, int m, int k)
{
    int maxnum = 1 << (n * m), j, bestres = INF, i;
   // cout << maxnum << endl;
    for (int curj = 0; curj < maxnum; curj++)
    {
        int cur = curj;
        for (j = 0; j < n; j++)
          for (i = 0; i < m; i++)
            mas[j][i] = 0;

        int curst = 0, f = 0, curstep = 0;
       // cout << newnum
        while(cur)
        {
         //   cout << cur % 2;
            if (!(cur % 2))
            {
                curstep++;
                cur /= 2;
                continue;
            }
            mas[curstep / m][curstep % m] = 1;
            curst++;
            if (curst >= bestres || curst > k)
            {
                f = 1;
                break;
            }
            cur /= 2;
            curstep++;
        }
        if (f)
          continue;

        /*cout << "-------------\n";
        for (j = 0; j < n; j++)
        {
            for (i = 0; i < m; i++)
              cout  << mas[j][i] << ' ';
            cout << endl;
        }*/
        for (j = 0; j < m; j++)
        {
          if (!mas[0][j])
            dfs(0, j, n, m);
          if (!mas[n - 1][j])
            dfs(n - 1, j, n, m);
        }
        for (j = 0; j < n; j++)
        {
          if (!mas[j][0])
            dfs(j, 0, n, m);
          if (!mas[j][m - 1])
            dfs(j, m - 1, n, m);
        }
        int closed = 0;
        for (j = 0; j < n; j++)
          for (i = 0; i < m; i++)
          {
              if (mas[j][i] == 1 || mas[j][i] == 0)
                closed++;
          }
        if (closed == k)
        {
            bestres = min(bestres, curst);
        }
    }
    return bestres;
}
int main()
{
    ifstream cin("input_csmall.in");
   ofstream cout ("output_csmall.txt");
  int i, j, n, m, k, l, t;
  cin >> t;
  long long p, q, div;
  for (int curk = 1; curk <= t; curk++)
  {
      cin >> n >>  m >> k;

      cout << "Case #" << curk << ": ";
      cout << solve(n, m, k) << endl;
  }

}
