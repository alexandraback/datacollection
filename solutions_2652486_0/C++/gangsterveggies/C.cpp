#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<string> pos;
int seq[5];
int st[10], R, N, M, K;
int used[10];

int random(int a, int b)
{
  if (a == b)
    return a;
  if (b - a + 1 == 0)
  {
    printf("WTF\n");
    return 0;
  }
  return (rand() % (b - a + 1)) + a;
}

void mark(int val)
{
  int i;
  for (i = 0; i < K; i++)
    if (val == st[i])
      used[i] = 1;
}

void dfs(int curr, int prod)
{
  mark(prod);
  if (curr == N)
    return;
  dfs(curr + 1, prod);
  dfs(curr + 1, prod * seq[curr]);
}

int main()
{
  printf("Case #1:\n");
  scanf("%*d");
  srand((unsigned)(time(NULL)));
  int i, j;
  scanf("%d %d %d %d", &R, &N, &M, &K);
  for (i = 0; i < R; i++)
  {
    for (j = 0; j < K; j++)
      scanf("%d", &st[j]);
    pos.clear();
    seq[0] = seq[1] = seq[2] = 2;
    while (1)
    { 
//      printf("%d %d %d\n", seq[0], seq[1], seq[2]);
      memset(used, 0, sizeof used);
      dfs(0, 1);
      int o, flag = 1;
      for (o = 0; o < K; o++)
        if (!used[o])
        {
          flag = 0;
        }
      if(flag)
      {
        string str = "";
        str += seq[0] + '0';
        str += seq[1] + '0';
        str += seq[2] + '0';
        pos.push_back(str);
      }

      if (seq[0] == seq[1] && seq[1] == seq[2] && seq[2] == M)
        break;
      seq[0]++;
      if (seq[0] > M)
      {
        seq[0] = 2;
        seq[1]++;
      }
      if (seq[1] > M)
      {
        seq[1] = 2;
        seq[2]++;
      }
    }
    printf("%s\n", pos[random(0, pos.size() - 1)].c_str());
  }
  return 0;
}
