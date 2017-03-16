#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int a, b, k;

void ReadData()
{
  scanf("%d %d %d", &a, &b, &k);
}

__int64 answer;

void Solve()
{
  answer = 0;
  for(int i = 0; i < a; i++)
  {
    for(int j = 0; j < b; j++)
    {
      if((i & j) < k)
      {
        answer++;
      }
    }
  }
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