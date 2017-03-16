#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>                                                                              

using namespace std;

const double eps = 1e-8;

typedef vector <int> vi;
typedef pair <int, int> pii;
typedef long long ll;

int T;
int n, a[1000];
double r[1000];

int main()
{
  scanf("%d", &T);
  for (int t = 0; t < T; ++t)
  {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    
    for (int i = 0; i < n; ++i)
    {
      double A = 0.0;
      double B = 100.0;
      while (fabs(A - B) > eps)
      {
        double c = (A + B) * 0.5;
        double x = a[i] + sum*c / 100.0;
        double y = sum*(100.0 - c)/100.0;
        for (int j = 0; j < n; ++j)
            if (j != i)
            {
              double p = max(0.0, x - a[j]);
              y -= p;  
            }
                
        if (y > -eps)
            A = c;
        else
            B = c;
      }
      r[i] = (A + B)*0.5;
    }

    printf("Case #%d: ", t + 1);
    for (int i = 0; i < n; ++i)
        printf("%.7f ", r[i]);
    printf("\n");
  }
  return 0;
}
