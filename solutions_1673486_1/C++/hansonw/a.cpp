#include <iostream>
#include <cstdio>
using namespace std;

double p[100000];

int main()
{
  int T; cin >> T;
  for (int ti = 1; ti <= T; ti++)
  {
    int A, B; cin >> A >> B;
    for (int i = 0; i < A; i++) cin >> p[i];
    
    double ans = 2+B;
    double prob = 1;
    for (int i = 0; i <= A; i++) {
      ans = min(ans, A-i+B-i+1 + (1-prob)*(B+1));
      prob *= p[i];
    }
 
    
    printf("Case #%d: %.6lf\n", ti, ans);
  }
}