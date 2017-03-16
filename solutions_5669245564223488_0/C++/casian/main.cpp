#include<cstdio>

using namespace std;

int trenulete[105][105];
int lungtr[105];
int frecstart[30], frecmiddle[30], frecend[30];
int standard[30];
int used[30];
int endtren[30];
int starttren[30];

int rez(int n)
{
  int i, j, nrcc = 0, rezultat, aux;
  long long p = 1;
  for(i = 0; i <= 'z' - 'a'; ++ i)
  {
    if(frecmiddle[i] > 1 || frecstart[i] > 1 || frecend[i] > 1)
      return 0;
    if(frecmiddle[i] == 1 && frecstart[i] + frecend[i] > 0)
      return 0;
  }
  for(i = 0; i <= 'z' - 'a'; ++ i)
    for(j = 2; j <= standard[i]; ++ j)
      p = (p * j) % 1000000007;
  for(i = 0; i <= 'z' - 'a'; ++ i)
  {
    endtren[i] = 0;
    starttren[i] = 0;
    used[i] = 0;
  }
  for(i = 1; i <= n; ++ i)
    if(lungtr[i] > 1)
    {
      endtren[trenulete[i][1]] = trenulete[i][lungtr[i]];
      starttren[trenulete[i][lungtr[i]]] = trenulete[i][1];
    }
  for(i = 0; i <= 'z' - 'a'; ++ i)
    if(standard[i] || frecstart[i] || frecend[i])
      if(used[i] == 0)
      {
        ++ nrcc;
        used[i] = 1;
        if(frecstart[i] || frecend[i])
        {
          if(frecstart[i])
          {
            aux = i;
            while(endtren[aux] != 0)
            {
              aux = endtren[aux];
              if(used[aux] != 0)
                return 0;
              else
                used[aux] = 1;
            }
          }
          if(frecend[i])
          {
            aux = i;
            while(starttren[aux] != 0)
            {
              aux = starttren[aux];
              if(used[aux] == 1)
                return 0;
              else
                used[aux] = 1;
            }
          }
        }
      }
  for(i = 2; i <= nrcc; ++ i)
    p = (p * i) % 1000000007;
  rezultat = p;
  return rezultat;
}

int main()
{
  int t, n, i, j, k;
  char c;
  scanf("%d", &t);
  for(i = 1; i <= t; ++ i)
  {
    scanf("%d\n", &n);
    for(j = 0; j <= 'z' - 'a'; ++ j)
    {
      frecend[j] = 0;
      frecstart[j] = 0;
      standard[j] = 0;
      frecmiddle[j] = 0;
    }
    for(j = 1; j <= n; ++ j)
    {
      scanf("%ch", &c);
      k = 0;
      while(c >= 'a' && c <= 'z')
      {
        if(trenulete[j][k] != c - 'a' || k == 0)
          trenulete[j][++ k] = c - 'a';
        scanf("%ch", &c);
      }
      lungtr[j] = k;
      if(k == 1)
        ++ standard[trenulete[j][1]];
      else
      {
        ++ frecstart[trenulete[j][1]];
        ++ frecend[trenulete[j][k]];
        for(k = 2; k < lungtr[j]; ++ k)
          if(used[trenulete[j][k]] == 0)
          {
            ++ frecmiddle[trenulete[j][k]];
            used[trenulete[j][k]] = 1;
          }
        for(k = 0; k <= 'z' - 'a'; ++ k)
          used[k] = 0;
      }
    }
    printf("Case #%d: %d\n", i, rez(n));
  }
  return 0;
}
