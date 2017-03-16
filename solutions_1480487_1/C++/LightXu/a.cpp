#include <cstdio>
#include <cstring>

int judge[200];
int no[200];
double answer[200];
double remain;
int N, X;

void swap(int& a, int& b)
{
  int t = a; a = b; b = t;
}

void swap(double& a, double& b)
{
  double t = a; a = b; b = t;
}

int main()
{
  int T, ca;
  scanf("%d", &T);
  for (ca = 1; ca <= T; ca++)
  {
    scanf("%d", &N);
    X = 0;
    for (int i = 0; i < N; i++)
    {
      scanf("%d", &judge[i]);
      no[i] = i;
      X += judge[i];
    }
    for (int i = 0; i < N; i++)
      for (int j = i + 1; j < N; j++)
        if (judge[i] > judge[j])
        {
          swap(judge[i], judge[j]);
          swap(no[i], no[j]);
        }
    remain = 1.0;
    memset(answer, 0, sizeof(answer));
    int i;
    for (i = 1; i < N; i++)
      if (judge[i] > judge[i - 1])
      {
        if ((judge[i] - judge[i - 1]) / (double) X * i <= remain)
        {
          remain -= (judge[i] - judge[i - 1]) / (double) X * i;
          for (int j = 0; j < i; j++)
            answer[j] += (judge[i] - judge[i - 1]) / (double) X;
        }
        else
          break;
      }
    for (int j = 0; j < i ; j++)
      answer[j] += remain / i;
    for (int i = 0; i < N; i++)
      for (int j = i + 1; j < N; j++)
        if (no[i] > no[j])
        {
          swap(no[i], no[j]);
          swap(answer[i], answer[j]);
        }
    printf("Case #%d: ", ca);
    for (int i = 0; i < N; i++)
      printf("%.6lf%c", answer[i] * 100, i < N - 1 ? ' ' : '\n');
  }
  return 0;
}