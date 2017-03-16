#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int ai, bi, ki;

void ReadData()
{
  scanf("%d %d %d", &ai, &bi, &ki);
}

__int64 answer;

bool a[35], b[35], k[35];

__int64 dp[39][2][2][2];
int ad, bd, cd;

__int64 f(int cnt, int ea, int eb, int ec)
{
  if(cnt == -1)
  {
    /*if((ea + eb + ec) == 0)
    {
      printf("nice: %d %d %d", ad, bd, cd);
    }*/
    return (ea + eb + ec) == 0 ? 1 : 0;
  }
  if(dp[cnt][ea][eb][ec] != -1)
  {
    return dp[cnt][ea][eb][ec];
  }
  __int64 result = 0;
  if(ec == 1)
  {
    if(k[cnt])
    {
      //Получить ноль
      /*ad &= ~(1 << cnt);
      bd &= ~(1 << cnt);
      cd &= ~(1 << cnt);*/
      result += f(cnt - 1, ea * (a[cnt] ? 0 : 1), eb * (b[cnt] ? 0 : 1), 0);
      if(eb == 0 || b[cnt])
      {
        /*ad &= ~(1 << cnt);
        bd |= 1 << cnt;
        cd &= ~(1 << cnt);*/
        result += f(cnt - 1, ea * (a[cnt] ? 0 : 1), eb, 0);
      }
      if(ea == 0 || a[cnt])
      {
        /*ad |= 1 << cnt;
        bd &= ~(1 << cnt);
        cd &= ~(1 << cnt);*/
        result += f(cnt - 1, ea, eb * (b[cnt] ? 0 : 1), 0);
      }
      //Получить единицу
      if((ea == 0 || a[cnt]) && (eb == 0 || b[cnt]))
      {
        /*ad |= 1 << cnt;
        bd |= 1 << cnt;
        cd |= 1 << cnt;*/
        result += f(cnt - 1, ea, eb, 1);
      }
    }
    else
    {
      //Получить ноль
      /*ad &= ~(1 << cnt);
      bd &= ~(1 << cnt);
      cd &= ~(1 << cnt);*/
      result += f(cnt - 1, ea * (a[cnt] ? 0 : 1), eb * (b[cnt] ? 0 : 1), 1);
      if(eb == 0 || b[cnt])
      {
        /*ad &= ~(1 << cnt);
        bd |= 1 << cnt;
        cd &= ~(1 << cnt);*/
        result += f(cnt - 1, ea * (a[cnt] ? 0 : 1), eb, 1);
      }
      if(ea == 0 || a[cnt])
      {
        /*ad |= 1 << cnt;
        bd &= ~(1 << cnt);
        cd &= ~(1 << cnt);*/
        result += f(cnt - 1, ea, eb * (b[cnt] ? 0 : 1), 1);
      }
    }
  }
  else
  {
    //Получить ноль
    result += f(cnt - 1, ea * (a[cnt] ? 0 : 1), eb * (b[cnt] ? 0 : 1), 0);
    if(eb == 0 || b[cnt])
    {
      result += f(cnt - 1, ea * (a[cnt] ? 0 : 1), eb, 0);
    }
    if(ea == 0 || a[cnt])
    {
      result += f(cnt - 1, ea, eb * (b[cnt] ? 0 : 1), 0);
    }
    //Получить единицу
    if((ea == 0 || a[cnt]) && (eb == 0 || b[cnt]))
    {
      result += f(cnt - 1, ea, eb, 0);
    }
  }
  dp[cnt][ea][eb][ec] = result;
  return result;
}

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(k, 0, sizeof(k));
  ad = bd = cd = 0;
  answer = 0;
  int copy = ai;
  for(int i = 0; i < 32; i++)
  {
    a[i] = (copy & 1) == 1;
    copy >>= 1;
  }
  copy = bi;
  for(int i = 0; i < 32; i++)
  {
    b[i] = (copy & 1) == 1;
    copy >>= 1;
  }
  copy = ki;
  for(int i = 0; i < 32; i++)
  {
    k[i] = (copy & 1) == 1;
    copy >>= 1;
  }
  answer = f(31, 1, 1, 1);
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  int QWE;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    printf("Case #%d: ", T + 1);
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}