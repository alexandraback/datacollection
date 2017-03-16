#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

long long fact(long long x)
{
   if(x == 0) return 1;
   return (x * fact(x - 1)) % MOD;
}

int nbWays(vector<string> trains)
{
   long long nb = 1;
   int tot = trains.size();
   for(char c = 'a'; c <= 'z'; c++)
   {
      int deb = -1, fin = -1, milieu = -1;
      vector<int> tout;
      for(size_t j=0; j<trains.size(); j++)
      {
         string &mot = trains[j];
         int x=-1, y=-1;
         for(size_t i=0; i<mot.size(); i++)
         {
            if(mot[i] == c && y != -1)
               return 0;
            if(mot[i] == c && x == -1)
               x = i;
            if(mot[i] == c && i < mot.size() - 1 && mot[i+1] != c)
               y = i;
         }
         if(milieu != -1 && x != -1)
            return 0;
         if(x == 0 && y == -1)
            tout.push_back(j);
         else if(x == 0 && y != -1)
         {
            if(deb != -1) return 0;
            deb = j;
         }
         else if(x > 0 && y == -1)
         {
            if(fin != -1) return 0;
            fin = j;
         }
         else if(x > 0 && y != -1)
            milieu = j;
      }

      if(!tout.empty())
      {
         nb = (nb * fact(tout.size())) % MOD;
         tot -= tout.size();
         if(deb == -1 && fin == -1)
            tot++;
      }
      if(deb != -1 && fin != -1)
      {
         tot--;
         trains[deb] = trains[fin] + trains[deb];
         trains[fin] = trains.back();
         trains.pop_back();
      }
   }
   nb = (fact(tot) * nb) % MOD;
   return (int)nb;
}

int main()
{
   int nbTests;
   scanf("%d", &nbTests);
   for(int iTest = 1 ; iTest <= nbTests; iTest++)
   {
      int nbTrains;
      scanf("%d", &nbTrains);
      vector<string> trains(nbTrains, "");
      for(int i=0; i<nbTrains; i++)
         cin >> trains[i];
      printf("Case #%d: %d\n", iTest, nbWays(trains));
   }
   return 0;
}
