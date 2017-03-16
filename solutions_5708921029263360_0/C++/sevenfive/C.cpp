// my first program in C++
#include <iostream>
#include <math.h>

using namespace std;

int jp[10*10];
int ps[10*10];
int js[10*10];

int used[10*10*10] = {0};

int safe(int K) {
  for (int i = 0; i < 100; i++) {
    if (jp[i] > K || ps[i] > K || js[i] > K) {
      return 0;
    }
  }
  return 1;
}

int score(int j, int p, int s) {
  return max(jp[j+5*p],max(ps[p+5*s],js[j+5*s]) + min(jp[j+5*p],min(ps[p+5*s],js[j+5*s]))) + (used[j+5*p+25*s] ? 9999 : 0);
}

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int J;
    cin >> J;
    int P;
    cin >> P;
    int S;
    cin >> S;
    int K;
    cin >> K;
    for (int i = 0; i < 100; i++) {
      jp[i] = 0;
      ps[i] = 0;
      js[i] = 0;
    }
    for (int i = 0 ; i < 1000; i++) {
      used[i] = 0;
    }
    while (safe(K)) {
      int bestScore = 999;
      int bestJ;
      int bestP;
      int bestS;
      for (int j = 0; j < J; j++) {
        for (int p = 0; p < P; p++) {
          for (int s = 0; s < S; s++) {
            int sc = score(j,p,s);
            if (sc < bestScore) {
              bestJ = j; bestP = p; bestS = s;
              bestScore = sc;
            }
          }
        }
      }
      if (bestScore == 999) {break;}
      jp[bestJ + 5 * bestP] += 1;
      ps[bestP + 5 * bestS] += 1;
      js[bestJ + 5 * bestS] += 1;
      used[bestJ + 5*bestP + 25*bestS] = 1;
      if (safe(K)) {
        cout << bestJ + 1 << " " << bestP + 1 << " " << bestS + 1 << endl;
      }
    }
  }

}
