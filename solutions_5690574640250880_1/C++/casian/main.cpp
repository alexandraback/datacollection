#include<cstdio>

using namespace std;

void solve(int n, int m, int nrm, int k)
{
  int i, j, min, nrl;
  min = n;
  nrl = n * m - nrm;
  if(m < min)
    min = m;
  if(nrl <= min + min + 1)
  {
    if(nrl <= 4)
    {
      if(nrl <= 2)
      {
        if(nrl == 1)
        {
          printf("Case #%d:\n", k);
          printf("c");
          for(i = 2; i <= m; ++ i)
            printf("*");
          printf("\n");
          for(i = 2; i <= n; ++ i)
          {
            for(j = 1; j <= m; ++ j)
              printf("*");
            printf("\n");
          }
        }
        else
          printf("Case #%d:\nImpossible\n", k);
      }
      else
      {
        if(nrl == 3)
          printf("Case #%d:\nImpossible\n", k);
        else
        {
          printf("Case #%d:\n", k);
          printf("c.");
          for(j = 3; j <= m; ++ j)
            printf("*");
          printf("\n");
          printf("..");
          for(j = 3; j <= m; ++ j)
            printf("*");
          printf("\n");
          for(i = 3; i <= n; ++ i)
          {
            for(j = 1; j <= m; ++ j)
              printf("*");
            printf("\n");
          }
        }
      }
    }
    else
    {
      if(nrl % 2 == 0)
      {
        printf("Case #%d:\n", k);
        printf("c");
        for(i = 2; i <= nrl/2; ++ i)
          printf(".");
        for(i = nrl/2 + 1; i <= m; ++ i)
          printf("*");
        printf("\n");
        for(i = 1; i <= nrl/2; ++ i)
          printf(".");
        for(i = nrl/2 + 1; i <= m; ++ i)
          printf("*");
        printf("\n");
        for(i = 3; i <= n; ++ i)
        {
          for(j = 1; j <= m; ++ j)
            printf("*");
          printf("\n");
        }
      }
      else
      {
        if(nrl == 5)
          printf("Case #%d:\nImpossible\n", k);
        else
        {
          if(nrl == 7)
            printf("Case #%d:\nImpossible\n", k);
          else
          {
            printf("Case #%d:\n", k);
            nrl -= 3;
            printf("c");
            for(i = 2; i <= nrl/2; ++ i)
              printf(".");
            for(i = nrl/2 + 1; i <= m; ++ i)
              printf("*");
            printf("\n");
            for(i = 1; i <= nrl/2; ++ i)
              printf(".");
            for(i = nrl/2 + 1; i <= m; ++ i)
              printf("*");
            printf("\n");
            printf("...");
            for(i = 4; i <= m; ++ i)
              printf("*");
            printf("\n");
            for(i = 4; i <= n; ++ i)
            {
              for(j = 1; j <= m; ++ j)
                printf("*");
              printf("\n");
            }
          }
        }
      }
    }
  }
  else
  {
    printf("Case #%d:\n", k);
    if(m == min)
    {
      if(nrm % m == m - 1)
      {
        printf("c");
        for(i = 2; i <= n * m; ++ i)
        {
          if(i <= nrl + 1 && i != nrl - 1)
            printf(".");
          else
            printf("*");
          if(i % m == 0)
            printf("\n");
        }
      }
      else
      {
        printf("c");
        for(i = 2; i <= n * m; ++ i)
        {
          if(i <= nrl)
            printf(".");
          else
            printf("*");
          if(i % m == 0)
            printf("\n");
        }
      }
    }
    else
    {
      if(nrm % n == n - 1)
      {
        for(i = 1; i <= n; ++ i)
        {
          for(j = 1; j <= m; ++ j)
          {
            if(i == 1 && j == 1)
              printf("c");
            else
            {
              if(j * n - n + i <= nrl + 1 && j * n - n + i != nrl - 1)
                printf(".");
              else
                printf("*");
            }
          }
          printf("\n");
        }
      }
      else
      {
        for(i = 1; i <= n; ++ i)
        {
          for(j = 1; j <= m; ++ j)
          {
            if(i == 1 && j == 1)
              printf("c");
            else
            {
              if(j * n - n + i <= nrl)
                printf(".");
              else
                printf("*");
            }
          }
          printf("\n");
        }
      }
    }
  }
}

int main()
{
  int n, m, nrm, t, i, k;
  scanf("%d", &t);
  for(k = 1; k <= t; ++ k)
  {
    scanf("%d%d%d", &n, &m, &nrm);
    if(n == 1)
    {
      if(n * m <= nrm)
        printf("Case #%d:\nImpossible\n", k);
      else
      {
        printf("Case #%d:\n", k);
        printf("c");
        for(i = 1; i < m - nrm; ++ i)
          printf(".");
        for(i = 1; i <= nrm; ++ i)
          printf("*");
        printf("\n");
      }
    }
    else
    {
      if(m == 1)
      {
        if(n * m <= nrm)
          printf("Case #%d:\nImpossible\n", k);
        else
        {
          printf("Case #%d:\n", k);
          printf("c\n");
          for(i = 1; i < n - nrm; ++ i)
            printf(".\n");
          for(i = 1; i <= nrm; ++ i)
            printf("*\n");
        }
      }
      else
      {
        if(n == 3 && m == 3 && nrm == 2)
          printf("Case #%d:\nImpossible\n", k);
        else
        {
          if((m == 2 || n == 2) && (nrm % 2 == 1 && n * m - nrm != 1))
            printf("Case #%d:\nImpossible\n", k);
          else
            solve(n, m, nrm, k);
        }
      }
    }
  }
  return 0;
}
