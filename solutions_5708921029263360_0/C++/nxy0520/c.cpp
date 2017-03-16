#include "iostream"
#include "stdio.h"

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int cs = 1; cs<=T; cs++) {
    cout << "Case #" << cs << ": ";
    int J, P, S, K;
    cin >> J >> P >> S >> K;
    int count = 0;
    int JP[11][11] = {};
    int JS[11][11] = {};
    int PS[11][11] = {};
    int ans = 0;
    for (int j = 1; j<=J;j++) {
      count = j;
      for (int p = 1; p<=P;p++) {
        count = count + 1;
        for (int ss =count;ss<count+S;ss++) {
          int s = ss % S + 1;
          if (JP[j][p] < K && JS[j][s] < K && PS[p][s] < K) {
            JP[j][p]++;
            JS[j][s]++;
            PS[p][s]++;
            ans++;
          }
        }
      }
    }
    for (int j = 1; j<=J;j++) {
      for (int p = 1; p<=P;p++) {
        for (int s =1;s<=S;s++) {
          JP[j][p]=0;
          JS[j][s]=0;
          PS[p][s]=0;
        }
      }
    }
    cout << ans <<endl;
    count = 0;
    for (int j = 1; j<=J;j++) {
      count = j;
      for (int p = 1; p<=P;p++) {
        count = count + 1;
        for (int ss =count;ss<count+S;ss++) {
          int s = ss % S + 1;
          if (JP[j][p] < K && JS[j][s] < K && PS[p][s] < K) {
            JP[j][p]++;
            JS[j][s]++;
            PS[p][s]++;
            cout << j<<" "<<p<<" "<<s<<endl;
          }
        }
      }
    }
  }
}
