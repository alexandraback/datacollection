
#include <algorithm>
#include <cstdio>

using namespace std;

double p[100000];
double all_correct[100000];

double optionA(int A, int B)
{
  double correct = 1;
  for (int i = 0; i < A; i++)
    correct *= p[i];
  double incorrect = 1-correct;
  correct *= (B-A+1);
  incorrect *= (B-A+1)+(B+1);
  return correct+incorrect;
}

double optionB(int A, int B)
{
  double best = -1;
  for (int i = A-1; i >= 0; i--)
  {
    double curr = all_correct[i]*(B-i+1) + (1-all_correct[i])*((B-i+1)+(B+1));
    if (best < 0 || best > curr) best = curr;
  }
  return best;
}

double optionC(int A, int B)
{
  return B+2;
}

void process(int A, int B)
{
  all_correct[0] = p[0];
  for (int i = 1; i < A; i++)
    all_correct[i] = all_correct[i-1]*p[i];
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int case_id = 1; case_id <= T; case_id++)
  {
    int A, B;
    scanf("%d %d", &A, &B);
    for (int i = 0; i < A; i++)
      scanf("%lf", &p[i]);
    process(A, B);

    double ans = min(optionA(A,B), min(optionB(A, B), optionC(A, B)));

    printf("Case #%d: %lf\n", case_id, ans);
  }
}
