#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("in.txt","r", stdin);
  freopen("out.txt", "w", stdout);

  int tests;
  scanf("%d", &tests);

  for(int testNo = 1; testNo <= tests; testNo++) {
    printf("Case #%d: ", testNo);
    double C, F, X;
    scanf("%lf %lf %lf", &C, &F, &X);

    if(X < C) {
      printf("%lf\n", X / 2.0);
      continue;
    }

    int farms = 0;
    double timeTaken = 0.0;

    while(C / (2.0 + farms * F) + X / (2.0 + (farms + 1) * F) < X / (2.0 + farms * F)) {
      timeTaken += C / (2.0 + farms * F);
      farms++;
    }

    timeTaken += X / (2.0 + farms * F);

    printf("%.8lf\n",timeTaken);
    cerr << "Case #" << testNo << ": " << " Farms = " << farms << " timeTaken = " << timeTaken << endl;

  }
  return 0;
}