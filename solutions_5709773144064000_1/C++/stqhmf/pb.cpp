#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

const double EPS = 1e-2;

double C; // farm cost
double F; // extra rate
double X; // target points

double f(double init_r)
{
  int count = 0;

  stack<double> stack;
  stack.push(init_r);
  while ( !stack.empty() ) {
    double r = stack.top();
    if ( X/r < EPS ) {
      break;
    }
    else {
      double next_r = r + F;
      stack.push(next_r); ++count;
    }
  }

  while ( !stack.empty() ) {
    double rF = stack.top(); stack.pop(); if ( stack.empty() ) return rF;
    double r  = stack.top(); stack.pop();
    double T  = min(X/r, C/r + rF);
    stack.push(T);
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    scanf("%lf %lf %lf", &C, &F, &X);

    fprintf(stderr, "Case #%d: ", t);
    fprintf(stderr, "%.7f\n", f(2.0));

    printf("Case #%d: ", t);
    printf("%.7f\n", f(2.0));
  }
}
