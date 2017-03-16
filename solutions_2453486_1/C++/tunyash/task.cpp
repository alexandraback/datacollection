#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;
const int prime = 9241;
const ld pi = acos(-1.);

void solve(int test)
{
   string u[4];
   for (int i = 0; i < 4; i++)
     cin >> u[i];
   bool xwin = 0;
   bool owin = 0;
   int pt = 0;
   for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
         if (u[i][j] == '.') pt++;
   for (int i = 0; i < 4; i++)
   {
      int xes = 0;
      int os = 0;
      int ts = 0;
      for (int j = 0; j < 4; j++)
         if (u[i][j] == 'X') xes++;
         else if (u[i][j] == 'O') os++;
         else if (u[i][j] == 'T') ts++;
      if (xes+ts == 4)
      {
         xwin = 1;
      } 
      if (os+ts == 4) 
      {
         owin = 1;
      }
   }
   for (int i = 0; i < 4; i++)
   {
      int xes = 0;
      int os = 0;
      int ts = 0;
      for (int j = 0; j < 4; j++)
         if (u[j][i] == 'X') xes++;
         else if (u[j][i] == 'O') os++;
         else if (u[j][i] == 'T') ts++;
      if (xes+ts == 4)
      {
         xwin = 1;
      } 
      if (os+ts == 4) 
      {
         owin = 1;
      }
   }
   int xes = 0;
   int os = 0;
   int ts = 0;
   for (int j = 0; j < 4; j++)
      if (u[j][j] == 'X') xes++;
      else if (u[j][j] == 'O') os++;
      else if (u[j][j] == 'T') ts++;
   if (xes+ts == 4)
   {
      xwin = 1;
   } 
   if (os+ts == 4) 
   {
      owin = 1;
   }
   xes = 0;
   os = 0;
   ts = 0;
   for (int j = 0; j < 4; j++)
      if (u[j][3-j] == 'X') xes++;
      else if (u[j][3-j] == 'O') os++;
      else if (u[j][3-j] == 'T') ts++;
   if (xes+ts == 4)
   {
      xwin = 1;
   } 
   if (os+ts == 4) 
   {
      owin = 1;
   }
   assert(!owin || !xwin);
   cout << "Case #" << test << ": ";
   if (xwin) cout << "X won";
   if (owin) cout << "O won";
   if (!xwin && !owin)
   {
      if (pt == 0)
      {
          cout << "Draw";
      }
      else cout << "Game has not completed";
   }
   cout << endl;
}

int main()
{
   int t;
   cin >> t;
   for (int i = 0; i < t; i++) solve(i+1);
}