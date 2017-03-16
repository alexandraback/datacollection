#include<iostream>
#include<cmath>
#include<cstdio>
#define debug 0
using namespace std;

int A,B;
double prob[100001];
double expected (int i) {
}
int main() {
  int T;
  scanf("%d",&T);
  for ( int kase = 1 ; kase <= T ; kase ++) {
    scanf("%d%d",&A,&B);
    int i;
    double mult = 1;
    for (i =0 ; i < A ; i++) {
      cin >> prob[i];
      mult = mult * prob[i];
    }
    double probWrong = 1 - mult;
    int giveup = 1 + B + 1;
    double continued = (B - A + 1)*(mult) + (probWrong) * (B - A+ 1 + B + 1);
    double ans1 = min(giveup + 0.0, continued);
    double ans = 100007;
    double now = 0;
    double mult1 = 1;
    if (debug) {
      cout << continued << " -- COntinued \n";
      cout << giveup << "-- Giveup\n";
    }
    for ( int i = 0; i < A ; i++) {
      now = 0;
      now = now + A - i;
      now = now + (B-i);
      now ++;
      int failed = now + B + 1;
      now = now * mult1;
      ans = min(ans,now + failed * (1-mult1));
      mult1 = mult1 * prob[i];
      if (debug) {
        cout << "Ans " << ans << " i " << i << " now " << now << "\n";
      }
    }
    printf("Case #%d: ",kase);
    printf("%f\n", min(ans,ans1));
  }
}
