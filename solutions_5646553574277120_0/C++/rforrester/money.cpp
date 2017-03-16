#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

#define DBG(X)

bool solvesmall(int V, vector<int> D)
{
  int ret = 0;
  int n = D.size();
  int tab[1250];
  memset(tab,0,sizeof(tab));
  for (int i = 0; i < (1 << n); i++)
  {
    int s = 0;
    for (int j = 0; j < n; j++)
    {
      if ((1 << j) & i) 
      {
        s += D[j];
      }
    }
    tab[s] = 1;
  }
  for (int i = 1; i <= V; i++)
  {
    if (!tab[i]) return false;
  }
      
  return true;
  
}

int main()
{
  int r, c;
  int t;
  scanf("%d", &t);
  int z = 1;
  while (z <= t)
  {
   unsigned int ret = 100;
    int C, D, V;
    scanf("%d%d%d", &C, &D, &V);
    vector<int> DD;
    for (int i = 0; i < D; i++)
    {
      int x;
      scanf("%d", &x);
      DD.push_back(x);
    }
    
    if (solvesmall(V, DD))
    {
      ret = 0;
    }
    else
    {
   //   cout << "x " << endl;
   
      for (int i = 0; i < (1 << 8); i++)
      {
        vector<int> F = DD;

        for (int j = 0; j < 8; j++)
        {
          if ((1 << j) & i)
          {
            bool found = false;
            for (int x = 0; x < DD.size(); x++)
            {
              if (DD[x] == j + 1) found = true;
            }
            if (!found)
            {
              F.push_back(j + 1);
            }
          }
        }
        /*if (F.size() == 4) {
          cout << F[0] << endl;
          cout << F[1] << endl;
          cout << F[2] << endl;
          cout << F[3] << endl;
        }*/
        if (solvesmall(V, F))
        {
     //     cout << "solve" << F.size() << endl;
          ret = min(ret, (unsigned)(F.size() - DD.size()));
        }
      }
      
      for (int j = 3; j <= V; j++)
      {
        vector<int> F = DD;
        for (int k = j; k <= V; k += j)
        {
          bool found = false;
          for (int x = 0; x < DD.size(); x++)
            {
              if (DD[x] == k) found = true;
            }
            if (!found)
            {
              F.push_back(k);
            }
        }
        if (F.size() <= 8 && solvesmall(V, F))
        {
     //     cout << "solve" << F.size() << endl;
          ret = min(ret, (unsigned)(F.size() - DD.size()));
        }
        
        if (F.size() < 8)
        for (int i = 0; i < (1 << 8); i++)
        {
          vector<int> G = F;
          for (int j = 0; j < 8; j++)
          {
            if ((1 << j) & i)
            {
              bool found = false;
              for (int x = 0; x < F.size(); x++)
              {
                if (F[x] == j + 1) found = true;
              }
              if (!found)
              {
                G.push_back(j + 1);
              }
            }
          }
          if (G.size() <= 8 && solvesmall(V, G))
          {
       //     cout << "solve" << F.size() << endl;
            ret = min(ret, (unsigned)(G.size() - DD.size()));
          }
          
        }
        
      }
      
      
    }
    
    
    printf("Case #%d: %d\n", z, ret);
    z++;
  }
  
  return 0;
}


