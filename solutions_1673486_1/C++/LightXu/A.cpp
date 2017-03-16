#include <cstdio>

double p[100000];
int A, B;
double answer;

double expected_value_of_keystrokes(int N);

int main()
{
  int T;
  scanf("%d", &T);
  for (int ca = 1; ca <= T; ca++)
  {
    scanf("%d%d", &A, &B);
    for (int i = 0; i < A; i++)
      scanf("%lf", &p[i]);
    answer = B + 2; //press enter right away
    for (int back = 0; back < A; back++)
    {
      double temp = expected_value_of_keystrokes(A - back) + back;
      if (temp < answer) answer = temp;
    }
    printf("Case #%d: %.6lf\n", ca, answer);
  }
  return 0;
}

double expected_value_of_keystrokes(int N)
{
  double pRight = 1;
  for (int i = 0; i < N; i++)
    pRight *= p[i];
  return (pRight * (B + 1 - N) + (1 - pRight) * (2 * (B + 1) - N));
}