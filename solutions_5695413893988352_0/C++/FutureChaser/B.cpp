#include <stdio.h>
#include <string.h>

using namespace std;

const int MAXL = 20;

char a[MAXL], b[MAXL];

int abs(int a)
{
  return (a < 0) ? -a : a;
}

int main()
{
  int cases;
  scanf("%d", &cases);
  for (int k = 1; k <= cases; ++k)
  {
    printf("Case #%d: ", k);
    scanf("%s%s", a, b);
    int mindiff = 100000;
    int ansa, ansb;

    if (strlen(a) == 1)
    {
      for (int i = 0; i < 10; ++i)
      {
        if ((a[0] != '?') && (a[0] != i + '0')) continue;
        for (int j = 0; j < 10; ++j)
        {
          if ((b[0] != '?') && (b[0] != j + '0')) continue;
          if (abs(i - j) < mindiff)
          {
            mindiff = abs(i - j);
            ansa = i, ansb = j;
          }
        }
      }
      printf("%01d %01d\n", ansa, ansb);
    }
    else if (strlen(a) == 2)
    {
      for (int i = 0; i < 100; ++i)
      {
        if ((a[0] != '?') && (a[0] != i / 10 + '0')) continue;
        if ((a[1] != '?') && (a[1] != i % 10 + '0')) continue;
        for (int j = 0; j < 100; ++j)
        {
          if ((b[0] != '?') && (b[0] != j / 10 + '0')) continue;
          if ((b[1] != '?') && (b[1] != j % 10 + '0')) continue;
          if (abs(i - j) < mindiff)
          {
            mindiff = abs(i - j);
            ansa = i, ansb = j;
          }
        }
      }
      printf("%02d %02d\n", ansa, ansb);
    }
    else if (strlen(a) == 3)
    {
      for (int i = 0; i < 1000; ++i)
      {
        if ((a[0] != '?') && (a[0] != i / 100 + '0')) continue;
        if ((a[1] != '?') && (a[1] != i % 100 / 10 + '0')) continue;
        if ((a[2] != '?') && (a[2] != i % 10 + '0')) continue;
        for (int j = 0; j < 1000; ++j)
        {
          if ((b[0] != '?') && (b[0] != j / 100 + '0')) continue;
          if ((b[1] != '?') && (b[1] != j % 100 / 10 + '0')) continue;
          if ((b[2] != '?') && (b[2] != j % 10 + '0')) continue;
          if (abs(i - j) < mindiff)
          {
            mindiff = abs(i - j);
            ansa = i, ansb = j;
          }
        }
      }
      printf("%03d %03d\n", ansa, ansb);
    }
  }
  return 0;
}
