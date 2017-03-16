#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int tests;
  scanf("%d", &tests);

  for(int testNo = 1; testNo <= tests; testNo++) {
    printf("Case #%d: ", testNo);
    int n;
    scanf("%d", &n);
    vector <double> a(n), b(n);

    for(int i = 0; i < n; i++)
      scanf("%lf", &a[i]);

    for(int i = 0; i < n; i++)
      scanf("%lf", &b[i]);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int scoreWar = n, scoreDWar = 0;

    int bPos = 0, aPos = 0;
    while(aPos < n && bPos < n) {
      if(a[aPos] < b[bPos]) {
        scoreWar--;
        aPos++;
        bPos++;
      } else bPos++;
    }

    aPos = 0, bPos = 0;
    while(aPos < n && bPos < n) {
      if(a[aPos] > b[bPos]) {
        scoreDWar++;
        aPos++;
        bPos++;
      } else aPos++;
    }

    printf("%d %d\n", scoreDWar, scoreWar);
  }

  return 0;
}