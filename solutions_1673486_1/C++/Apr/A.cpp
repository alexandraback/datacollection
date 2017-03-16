#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>

using namespace std;

int N;

int A, B;
long double p[100000];
long double p_ok[100001];

int main()
{
  scanf("%d\n", &N);
  for(int n = 1; n <= N; n++) {
    scanf("%d%d", &A, &B);
    p_ok[0] = 1.0;
    for (int i = 0; i < A; i++) {
      scanf("%Lf", &p[i]);
      p_ok[i+1] = p_ok[i] * p[i];
      //printf("-%d: %Lf\n", i, p_ok[i+1]);
    }

    int rem = B - A;
    long double res = B + 2; //enter
    //printf("%Lf\n", res);
    for(int i = 0; i <= A; i++)
    {
      long double tmp = 2*i + 1 + (p_ok[A-i] * (rem)) + ((1.0 - p_ok[A-i]) * (rem + B + 1));
      //printf("%d: %Lf\n", i, tmp);
      res = min(res, tmp);
    }
    printf("Case #%d: ", n);
    printf("%Lf\n", res);
  }
  return 0;
}
