#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main() {
  int N;
  cin>>N;
  for (int n=1;n<=N;n++){
    double C,F,X;
    cin>>C>>F>>X;
    double time = 0.0;
    double rate = 2.0;
    double besttime = X/2;
    while(true) {
      time += C/rate;
      rate += F;
      double candTime = time + X/rate;
      if (candTime>besttime)
	break;
      besttime = candTime;
    }
    printf("Case #%d: %.7f\n",n,besttime);
  }

}
