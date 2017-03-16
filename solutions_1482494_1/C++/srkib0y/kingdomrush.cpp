#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define FORIN FOR(i, 0, n)
#define FORV(x) for(int i = 0, __len = (x).size(); i < __len; i++)

#define MAXN 2010

using namespace std;
int t, n, a[MAXN], b[MAXN], sol;
bool marked[MAXN][2];

void init()
{
   for (int i = 0; i < MAXN; i++)
      for (int j = 0; j < 2; j++)
         marked[i][j] = false;
}

void read()
{
   cin >> n;
   for (int i  =0; i < n; i++)
      cin >> a[i] >> b[i];
}

void write(int casen)
{
   if (sol == -1)
      cout << "Case #" << casen << ": " << "Too Bad" << endl;
   else
      cout << "Case #" << casen << ": " << sol << endl;
}

void solve()
{
   int stars = 0, total = 0, total2 = 0;;
   while (true)
   {
      int nexti = -1, nextj;
      for (int k = 0; k < 2 * n; k++)
      {
         int j = k / n;
         int i = k % n;
         if (j == 0 && marked[i][1])
            continue;
         if (!marked[i][j] && stars >= (j == 0 ? a[i] : b[i]))
         {
            if (nexti != -1 && j == 0 && (nextj == 1 || b[nexti] > b[i]))
               continue;
            nexti = i;
            nextj = j;
            if (j == 1 && !marked[i][0])
               break;
         }
      }
      if (nexti == -1)
         break;
      if (nextj == 1)
         total2++;
      total++;
      marked[nexti][nextj] = true;
      if (nextj == 0)
         stars++;
      else if (marked[nexti][0])
         stars++;
      else
         stars += 2;
      if (total2 == n)
         break;
   }
   if (total2 != n)
      sol = -1;
   else
      sol = total;
}

int main()
{
   cin >> t;
   for (int casen = 0; casen < t; casen++)
   {
      init();
      read();
      solve();
      write(casen + 1);
   }
   return 0;
}
