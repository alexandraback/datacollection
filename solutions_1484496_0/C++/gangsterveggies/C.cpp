#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 2000000

long long int list [501];
long long int DP [MAX + 5];
vector <long long int> v;
vector <long long int> s1;
vector <long long int> s2;
int t, aa = 0;

void remove()
{
  int i, tam = v.size(), fd = 0;
  for (i = 1; i < tam - fd; i++)
    if (v[i] == v[i - 1])
    {
      v.erase(v.begin() + i - 1);
      v.erase(v.begin() + i - 1);
      fd += 2;
      i -= 2;
    }
}

void print(long long int where)
{
  t++;
  if (where == 0)
    return;
  if (where != DP[where])
  {
    v.push_back(DP[where]);
    if (aa)
      s2.push_back(DP[where]);
    else
      s1.push_back(DP[where]);
    print(where - DP[where]);
  }
  else
  {
    v.push_back(DP[where]);
    if (aa)
      s2.push_back(DP[where]);
    else
      s1.push_back(DP[where]);
  }
}

int main()
{
  int tf, T, n, i, j;
  scanf("%d", &T);
  for (tf = 0; tf < T; tf++)
  {
    scanf("%d", &n);
    v.clear();
    s1.clear();
    s2.clear();
    memset(DP, 0, sizeof(DP));
    for (i = 0; i < n; i++)
    {
      scanf("%lld", &list[i]);
    }
    int mx = 0, flag = 1;
    printf ("Case #%d:\n", tf + 1);
    for (i = 0; i < n && flag; i++)
    {
      for (j = MAX - list[i]; j >= 0 && flag; j--)
      {
        if (DP[j] || j == 0)
        {
          if (DP[j + list[i]])
          {
            int t1, t2;
            t = 0;
            aa = 0;
            print(j + list[i]);
            t1 = t;
            t2 = 1;
            t = 0;
            v.push_back(list[i]);
            s2.push_back(list[i]);
            aa = 1;
            if (j != 0)
              print(j);
            sort(v.begin(), v.end());
            remove();
            int o, tam = s1.size(), ini = 1;
            for (o = 0; o < tam; o++)
              if (binary_search (v.begin(), v.end(), s1[o]))
              {
                if (ini)
                  printf("%lld", s1[o]);
                else
                  printf(" %lld", s1[o]);
                ini = 0;
              }
            putchar('\n');
            tam = s2.size();
            ini = 1;
            for (o = 0; o < tam; o++)
              if (binary_search (v.begin(), v.end(), s2[o]))
              {
                if (ini)
                  printf("%lld", s2[o]);
                else
                  printf(" %lld", s2[o]);
                ini = 0;
              }
            putchar('\n');
            flag = 0;
            break;
          }
          DP[j + list[i]] = list[i];
        }
      }
    }
    if (flag)
      printf("Impossible\n");
  }
  return 0;
}

